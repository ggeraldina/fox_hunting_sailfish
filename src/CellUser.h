#ifndef CELLUSER_H
#define CELLUSER_H

#include <QObject>

class CellUser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged)
public:
    explicit CellUser(QObject *parent = 0);

    QString getText();
    void setText(QString text);

private:
    QString text;

signals:
    void textChanged(QString text);

public slots:
};

#endif // CELLUSER_H
