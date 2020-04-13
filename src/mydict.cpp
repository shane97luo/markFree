#include "mydict.h"

MyDict::MyDict(QObject *parent) : QObject(parent)
{
    character_cn<<"你"<<"我"<<"他";
    character_en<<"you"<<"me"<<"he";

    for(int i=0;i<character_cn.length();i++)
    {
        dict_map_cn2zn.insert(character_cn[i],character_en[i]);
    }

}
