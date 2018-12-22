#ifndef CELLUSER_H
#define CELLUSER_H

#include <QObject>

class CellUser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString color READ getColor WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int value READ getValue WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(bool shot READ getShot WRITE setShot NOTIFY shotChanged)
public:
    explicit CellUser(QObject *parent = 0);

    QString getText();
    void setText(QString text);
    QString getColor();
    void setColor(QString color);
    int getValue();
    void setValue(int value);
    bool getShot();
    void setShot(bool shot);

private:
    QString text;
    QString color;
    int value;
    bool shot;

signals:
    void textChanged(QString text);
    void colorChanged(QString color);
    void valueChanged(int value);
    void shotChanged(bool shot);

public slots:
};

#endif // CELLUSER_H
