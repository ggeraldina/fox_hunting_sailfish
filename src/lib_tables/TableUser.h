#ifndef TABLEUSER_H
#define TABLEUSER_H

#include <QObject>

class TableUser : public QObject {
     Q_OBJECT
public:
    explicit TableUser(QObject *parent = nullptr);

private:
    const int VALUE_FOX = -1;
};

#endif // TABLEUSER_H
