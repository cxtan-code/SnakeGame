#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <ctime>
#include <QPushButton>
#include <QLabel>
#include <QButtonGroup>
#include <QDebug>
#include <QTextCodec>
class GameWidget :public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);
private:
    time_t Rand_count;//随机种子的起始值
    int Score;//得分
    int Difficulty;//难度级别，时间变化
    QPushButton *UpButton;
    QPushButton *DownButton;
    QPushButton *LeftButton;
    QPushButton *RightButton;
    QPushButton *StartButton;
    QPushButton *ExitButton;

    QLabel *ScoreLabel;
    QLabel *LevelLabel;
    QLabel *ScoreLabelNumber;
    QLabel *LevelLabelNumber;

    QTimer *Timer;

    QButtonGroup *ButtonGroup;//方向键组合上下左右
    int snakeposition[200][2];//蛇的身体坐标
//    int snakepositionCopy[200][2];//蛇的身体坐标复制
    int foodx;//食物的坐标
    int foody;
public slots:
    void on_setDiretion(int index);
};

#endif // GAMEWIDGET_H
