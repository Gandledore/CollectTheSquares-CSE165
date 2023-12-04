#ifndef WEIRDTARGET_H
#define WEIRDTARGET_H

#include "target.h"

class weirdTarget : public Target
{
    Q_OBJECT
public:
    weirdTarget(QWidget *parent = nullptr, float x=0, float y=0);
    void updatePos() override;
    ~weirdTarget();
private:
    float speed;
};

#endif // WEIRDTARGET_H
