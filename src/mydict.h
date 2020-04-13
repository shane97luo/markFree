#ifndef MYDICT_H
#define MYDICT_H

#include <QObject>
#include <QMap>

class MyDict : public QObject
{
    Q_OBJECT
public:
    explicit MyDict(QObject *parent = nullptr);

private:
    QStringList character_cn, character_en;
    QMap<QString,QString> dict_map_cn2zn;


signals:

};

#endif // MYDICT_H
