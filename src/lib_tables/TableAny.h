#ifndef TABLEANY_H
#define TABLEANY_H

#include <QObject>
#include <QVariant>
#include <QVector>

// объяснение, почему реализация шаблонов в .h
// https://www.linux.org.ru/forum/development/12094159
class TableAny : public QObject {
    Q_OBJECT

public:
    explicit TableAny(QObject *parent = nullptr);

    static void calculateIndexesCellsAroundRadius(int indexesCellsAround[],
                                                  int countCells, int currentIndex, int radius = 1);
    static QVector<bool> calculateIndexesShapeSnowflake(int countCells, int currentIndex);

    static int countGroupTrueIndexes(QVector<bool> indexes);

    template <class T>
    static void addFoxes(T *list, QVariant indexes) {
        QList<QVariant> indexesFoxes = indexes.toList();
        for(auto index : indexesFoxes) {
            int indexInt = index.toInt();
            addOneFox(list, indexInt);
        }
    }


    template <class T>
    static QVector<int> addRandomFoxes(T *list, int numberFoxes) {
        QVector<int> indexesFoxes;
        for(int i = 0; i < numberFoxes; i++) {
            int indexFox = addRandomOneFox(list);
            indexesFoxes.append(indexFox);
        }
        return indexesFoxes;
    }

    template <class T>
    static void editCellsShapeSnowflake(T *list, int currentIndex, void fun(T *, int)) {
        int countCells = list->count();
        int indexesCellsAround[8];
        int baseFieldSize = static_cast<int>(sqrt(countCells));
        for(int i = 1; i < baseFieldSize; i++) {
            calculateIndexesCellsAroundRadius(indexesCellsAround, countCells, currentIndex, i);
            for (auto indexCell : indexesCellsAround) {
                if(indexCell >= 0) {
                    fun(list, indexCell);
                }
            }
        }
    }

    template <class T>
    static void editCellsShapeNoSnowflake(T *list, int currentIndex, void fun(T *, int)) {
        const int countCells = list->count();
        QVector<bool> cellsShapeSnowflake = calculateIndexesShapeSnowflake(countCells, currentIndex);
        for (int i = 0; i < countCells; i++) {
            if(!cellsShapeSnowflake[i]) {
                fun(list, i);
            }
        }
    }

    template <class T>
    static void showFoxesOnField(T *list) {
        int countCells = list->count();
        for(int i = 0; i < countCells; i++) {
            int valueCell = list->value(i)->getValue();
            if (valueCell == VALUE_FOX)
                list->value(i)->setText("x");
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
        editValueCellsAddFox(list, currentIndex);
    }

private:
    static const int VALUE_FOX = -1;


    template <class T>
    static int addRandomOneFox(T *list) {
        int countCells = list->count();
        int randomIndex;
        while(true) {
            randomIndex = rand() % countCells;
            if (checkPossibleAddFox(list, randomIndex)) {                
                addOneFox(list, randomIndex);
                return randomIndex;
            }
        }
    }

    template <class T>
    static void editValueCellsAddFox(T *list, int currentIndex) {
        editCellsShapeSnowflake(list, currentIndex, editValueAddFox);
    }

    template <class T>
    static void editValueAddFox(T *list, int currentIndex) {
        int valueCell = list->value(currentIndex)->getValue();
        if(valueCell != VALUE_FOX) {
            list->value(currentIndex)->setValue(valueCell + 1);
        }
    }
};




#endif // TABLEANY_H
