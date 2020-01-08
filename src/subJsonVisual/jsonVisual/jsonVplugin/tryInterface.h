#ifndef TRYINTERFACE_H
#define TRYINTERFACE_H

#include <QObject>

class QWidget;
class tryInterface
{
public:

    virtual ~tryInterface(){}
    virtual QWidget *createPluginWidget(QWidget *parent) = 0;

};

#define tryInterface_iid "welcome"
Q_DECLARE_INTERFACE(tryInterface,tryInterface_iid)

#endif // TRYINTERFACE_H
