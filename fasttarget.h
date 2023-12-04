#ifndef FASTTARGET_H
#define FASTTARGET_H
#include "target.h"

class fastTarget : public Target
{
    Q_OBJECT
public:
    fastTarget(QWidget *parent = nullptr, float x=0, float y=0);
    void updatePos() override;
    ~fastTarget();
private:
    float speed;
};

#endif // FASTTARGET_H
