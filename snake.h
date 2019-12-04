#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>

namespace Ui {
class Snake;
}

class Snake : public QWidget
{
    Q_OBJECT

public:
    explicit Snake(QWidget *parent = 0);
    ~Snake();

private:
    Ui::Snake *ui;
};

#endif // SNAKE_H
