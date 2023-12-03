#ifndef ESTEROID_H
#define ESTEROID_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Esteroid;
}
QT_END_NAMESPACE

class Esteroid : public QMainWindow
{
    Q_OBJECT

public:
    Esteroid(QWidget *parent = nullptr);
    void finishGame();
    ~Esteroid();

private:
    Ui::Esteroid *ui;
};
#endif // ESTEROID_H
