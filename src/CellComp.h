#ifndef CELLCOMP_H
#define CELLCOMP_H

#include <QObject>

class CellComp : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString color READ getColor WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int value READ getValue WRITE setValue NOTIFY valueChanged)
public:
    explicit CellComp(QObject *parent = 0);

    QString getText();
    void setText(QString text);
    QString getColor();
    void setColor(QString color);
    int getValue();
    void setValue(int value);

private:
    QString text;
    QString color;
    int value;

signals:
    void textChanged(QString text);
    void colorChanged(QString color);
    void valueChanged(int value);

public slots:
};


#endif // CELLCOMP_H
