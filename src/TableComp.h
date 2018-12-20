#ifndef TABLECOMP_H
#define TABLECOMP_H

#include <QObject>
#include <QQmlListProperty>
#include "CellComp.h"

class TableComp : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CellComp> dataComp READ getDataComp NOTIFY dataCompChanged)
public:
    explicit TableComp(QObject *parent = 0);

    QQmlListProperty<CellComp> getDataComp();

    Q_INVOKABLE void addDataComp();
private:
    static void appendDataComp(QQmlListProperty<CellComp> *list, CellComp *value);
    static int countDataComp(QQmlListProperty<CellComp> *list);
    static CellComp *atDataComp(QQmlListProperty<CellComp> *list, int index);
    static void clearDataComp(QQmlListProperty<CellComp> *list);

    QList<CellComp*> dataComp;

signals:
    void dataCompChanged();

public slots:
};

#endif // TABLECOMP_H
