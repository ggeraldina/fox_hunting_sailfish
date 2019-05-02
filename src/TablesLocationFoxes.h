#ifndef TABLESLOCATIONFOXES_H
#define TABLESLOCATIONFOXES_H

#include <QObject>
#include "TablesBase.h"
#include "CellBase.h"
#include <QQmlListProperty>
#include "lib_tables/TableAny.h"

class TablesLocationFoxes : public TablesBase {
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CellBase> dataFoxes READ getDataFoxes NOTIFY dataFoxesChanged)

public:
    TablesLocationFoxes(QObject *parent = nullptr);
    ~TablesLocationFoxes();

    Q_INVOKABLE void cleanLocationFoxes();
    Q_INVOKABLE void generateRandomLocationFoxes();
    Q_INVOKABLE QString putOrRemoveFox(int index);
    Q_INVOKABLE bool equalNumberAndCountFoxes();

    QQmlListProperty<CellBase> getDataFoxes();

private:
    QList<CellBase *> dataFoxes;
    int currentCountFoxes;

signals:
    void dataFoxesChanged();
    void addFoxComp(int index);
    void removeFoxComp(int index);
    void removeAllFox();

private slots:
    void createData();
};



#endif // TABLESLOCATIONFOXES_H
