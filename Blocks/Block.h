#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>

class Block : public QWidget{
    Q_OBJECT

public:
    Block();

    virtual void paint(const Block* b);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif
