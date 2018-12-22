#ifndef CELLCOMP_H
#define CELLCOMP_H

#include <QObject>

class CellComp : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString color READ getColor WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int value READ getValue WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(bool shot READ getShot WRITE setShot NOTIFY shotChanged)
    Q_PROPERTY(bool possibleShot READ getPossibleShot WRITE setPossibleShot NOTIFY possibleShotChanged)
    Q_PROPERTY(int chance READ getChance WRITE setChance NOTIFY chanceChanged)
public:
    explicit CellComp(QObject *parent = 0);

    QString getText();
    void setText(QString text);
    QString getColor();
    void setColor(QString color);
    int getValue();
    void setValue(int value);
    bool getShot();
    void setShot(bool shot);
    bool getPossibleShot();
    void setPossibleShot(bool possibleShot);
    int getChance();
    void setChance(int chance);

private:
    QString text;
    QString color;
    int value;
    bool shot;
    bool possibleShot;
    int chance;

signals:
    void textChanged(QString text);
    void colorChanged(QString color);
    void valueChanged(int value);
    void shotChanged(bool shot);
    void possibleShotChanged(bool possibleShot);
    void chanceChanged(int chance);

public slots:
};


#endif // CELLCOMP_H
