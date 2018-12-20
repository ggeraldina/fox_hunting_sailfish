#ifndef CELLCOMP_H
#define CELLCOMP_H

#include <QObject>

class CellComp : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged)
public:
    explicit CellComp(QObject *parent = 0);

    QString getText();
    void setText(QString text);

private:
    QString text;

signals:
    void textChanged(QString text);

public slots:
};


#endif // CELLCOMP_H
