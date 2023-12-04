#ifndef ESTEROID_H
#define ESTEROID_H

#include <QMainWindow>
#include <QLabel>

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
    void finishGame(int finalTime);
    ~Esteroid();

private:
    Ui::Esteroid *ui;
    QLabel *finalTimeLabel;

private slots:
    void closeGame();

};

#endif // ESTEROID_H
