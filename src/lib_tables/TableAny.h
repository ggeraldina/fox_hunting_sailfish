#ifndef TABLEANY_H
#define TABLEANY_H

#include <QObject>
#include <QDebug>

// объяснение, почему реализация шаблонов в .h
// https://www.linux.org.ru/forum/development/12094159
class TableAny : public QObject {
    Q_OBJECT

public:
    explicit TableAny(QObject *parent = nullptr);

    template <class T>
    static void addRandomFoxes(T *list, int numberFoxes) {
        for(int i = 0; i < numberFoxes; i++) {
            addRandomOneFox(list);
        }
    }

private:
    static const int VALUE_FOX = -1;

    static void calculateIndexesCellsAroundRadius(int indexesCellsAround[],
                                                  int countCells, int currentIndex, int radius = 1);


    template <class T>
    static void addRandomOneFox(T *list) {
        int countCells = list->count();
        int randomIndex;
        while(true) {
            randomIndex = rand() % (countCells - 1);
            if (checkPossibleAddFox(list, randomIndex)) {
                addOneFox(list, randomIndex);
                return;
            }
        }
    }

    template <class T>
    static bool checkPossibleAddFox(T *list, int currentIndex) {
        if (list->value(currentIndex)->getValue() == VALUE_FOX)
            return false;
        int countCells = list->count();
        int indexesCellsAround[8];
        calculateIndexesCellsAroundRadius(indexesCellsAround, countCells, currentIndex);
        for (auto indexCell : indexesCellsAround) {
            if(indexCell >= 0 && list->value(indexCell)->getValue() == VALUE_FOX) {
                return false;
            }
        }
        return true;
    }

    template <class T>
    static void addOneFox(T *list, int currentIndex) {
        list->value(currentIndex)->setValue(VALUE_FOX);
        editValueCells(list, currentIndex);
    }

    template <class T>
    static void editValueCells(T *list, int currentIndex) {
        int countCells = list->count();
        int indexesCellsAround[8];
        int baseFieldSize = (int)sqrt(countCells);
        for(int i = 1; i < baseFieldSize; i++) {
            calculateIndexesCellsAroundRadius(indexesCellsAround, countCells, currentIndex, i);
            for (auto indexCell : indexesCellsAround) {
                if(indexCell >= 0) {
                    int valueCell = list->value(indexCell)->getValue();
                    if(valueCell != VALUE_FOX) {
                        list->value(indexCell)->setValue(valueCell + 1);
                    }
                }
            }
        }
    }
};

#endif // TABLEANY_H
