#ifndef OVERLOADS_H
#define OVERLOADS_H

#include "hit.h"
#include <QtCore>

QDataStream &operator <<(QDataStream &out, const QList<Hit> *hits);
//QDataStream &operator >>(QDataStream &in, QList<Hit> *hits);

QDataStream &operator <<(QDataStream &out, QList<Hit> *hits)
{
    for(int i=0;i<hits->size();i++)
    {
        out<< hits->at(i).power <<hits->at(i).rotation <<hits->at(i).angle <<hits->at(i).position;
    }
    return out;
}
/*QDataStream &operator >>(QDataStream &in, QList<Hit> *hits)
{
    hits = *(QList<Hit>());
    for(int i=0;i<hits->size();i++)
    {
        in>> hits->at(i).power >>hits->at(i).rotation >>hits->at(i).angle >>hits->at(i).position;
    }
    return in;
}*/
#endif // OVERLOADS_H
