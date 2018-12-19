#ifndef TABLECOMP_H
#define TABLECOMP_H

#include <QObject>
#include <QQmlListProperty>

class TableComp : public QObject
{
    Q_OBJECT
public:
    explicit TableComp(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TABLECOMP_H
