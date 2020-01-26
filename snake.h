#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "gamewidget.h"
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
    QPushButton *StartGame;
    QPushButton *ExitGame;
    QMessageBox *ExitMsg;
    GameWidget *m_game;
public slots:
    void OnStartGame();
    void OnExitGame();
};

#endif // SNAKE_H
