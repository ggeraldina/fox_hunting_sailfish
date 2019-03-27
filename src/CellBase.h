#ifndef CELLBASE_H
#define CELLBASE_H

#include <QObject>

class CellBase : public QObject {
    Q_OBJECT
    // text and background displayed on the cell of the field
    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString backgroundURL READ getBackgroundURL WRITE setBackgroundURL NOTIFY backgroundURLChanged)
    // value of cell
    Q_PROPERTY(int value READ getValue WRITE setValue NOTIFY valueChanged)

public:
    explicit CellBase(QObject *parent = nullptr);

    QString getText();
    QString getBackgroundURL();
    int getValue();

    void setText(QString text);
    void setBackgroundURL(QString backgroundURL);
    void setValue(int value);

private:
    QString text;
    QString backgroundURL;
    int value;

signals:
    void textChanged();
    void backgroundURLChanged();
    void valueChanged();
};

#endif // CELLBASE_H
