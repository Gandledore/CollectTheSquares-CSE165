#ifndef SMASHBOY_H
#define SMASHBOY_H

#include "block.h"
#include <QPainter>

class Smashboy : public Block{
    Q_OBJECT

    //Member Variables
    area - QRect(50, 50, 50, 50);

    public:
        Smashboy();

    void draw(const Block* b){
        const Smashboy* s = dynamic_cast<const Smashboy*>(b);
        if(b == 0) return;
        QPainter painter(this);
        painter.fillRect(squareRect, Qt::yellow);
    }

};


#endif