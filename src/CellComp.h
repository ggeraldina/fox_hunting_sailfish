#ifndef CELLCOMP_H
#define CELLCOMP_H

#include <QObject>

class CellComp : public QObject
{
    Q_OBJECT
public:
    explicit CellComp(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CELLCOMP_H
