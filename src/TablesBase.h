#ifndef TABLESBASE_H
#define TABLESBASE_H

#include <QObject>
#include <QQmlListProperty>
#include "CellBase.h"

class TablesBase: public QObject {
    Q_OBJECT
    Q_PROPERTY(int baseTableSize READ getBaseTableSize WRITE setBaseTableSize NOTIFY baseTableSizeChanged)
    Q_PROPERTY(int numberFoxes READ getNumberFoxes WRITE setNumberFoxes NOTIFY numberFoxesChanged)

    public:
    explicit TablesBase(QObject *parent = nullptr);
    ~TablesBase();

    int getBaseTableSize();
    int getNumberFoxes();
    void setBaseTableSize(int newValue);
    void setNumberFoxes(int newValue);

    int baseFieldSize;
    int numberFoxes;
    const int VALUE_FOX = -1;

protected:
    // abstract functions (depend on QList<T *>)

    template <class T>
    static void appendDataCells(QQmlListProperty<T> *list, T *value) {
        QList<T *> *dataTable = static_cast<QList<T *> *>(list->data);
        dataTable->append(value);
    }
    template <class T>
    static int countDataCells(QQmlListProperty<T> *list) {
        QList<T *> *dataTable = static_cast<QList<T *> *>(list->data);
        return dataTable->size();
    }
    template <class T>
    static T *atDataCells(QQmlListProperty<T> *list, int index) {
        QList<T *> *dataTable = static_cast<QList<T *> *>(list->data);
        return dataTable->at(index);
    }
    template <class T>
    static void clearDataCells(QQmlListProperty<T> *list) {
        QList<T *> *dataTable = static_cast<QList<T *> *>(list->data);
        qDeleteAll(dataTable->begin(), dataTable->end());
        dataTable->clear();
    }

signals:
    void baseTableSizeChanged();
    void numberFoxesChanged();

};

#endif // TABLESBASE_H
