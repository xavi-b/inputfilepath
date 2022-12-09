#ifndef MYCUSTOMCOMPONENT_H
#define MYCUSTOMCOMPONENT_H

#include <QQmlComponent>

namespace Custom {

class MyCustomComponent : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit MyCustomComponent(QObject *parent = nullptr);

signals:

};

}

#endif // MYCUSTOMCOMPONENT_H
