#ifndef TABLESCOMPUSER_H
#define TABLESCOMPUSER_H

#include <QObject>
#include "TableComp.h"
#include "TableUser.h"

class TablesCompUser : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(TableComp* tableComp READ getTableComp WRITE setTableComp NOTIFY tableCompChanged)
    Q_PROPERTY(TableUser* tableUser READ getTableUser WRITE setTableUser NOTIFY tableUserChanged)
    Q_CLASSINFO("DefaultProperty", "tableUser")
public:
    explicit TablesCompUser(QObject *parent = 0);

    TableComp* getTableComp();
    TableUser* getTableUser();
    void setTableComp(TableComp *tableComp);
    void setTableUser(TableUser *tableUser);

private:
    TableComp* tableComp;
    TableUser* tableUser;

signals:
    void tableCompChanged();
    void tableUserChanged();

public slots:
};

#endif // TABLESCOMPUSER_H
