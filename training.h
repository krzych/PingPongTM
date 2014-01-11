#ifndef TRAINING_H
#define TRAINING_H

#include <QList>
#include "hit.h"

class Training
{
public:
    Training();
    QList<Hit> hits;
    int power;
    void addHit(int pow, bool rot, int ang=0, int pos=0);
    void serialize();
    void deserialize();
};

#endif // TRAINING_H
