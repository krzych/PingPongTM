#ifndef HIT_H
#define HIT_H

class Hit
{
public:
    Hit(int pow, bool rot, int ang=0, int pos=0);

public:
    int power;
    bool rotation;
    int angle;
    int position;
};



#endif // HIT_H
