#include "snake.h"
#include "ui_snake.h"
#include <QTextCodec>
#include <QPalette>
#include <QDebug>
#include "gamewidget.h"
Snake::Snake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Snake)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(891,510));
    QString WinTile = QTextCodec::codecForName("utf8")->toUnicode("cxtan的贪吃蛇");
    this->setWindowTitle(WinTile);
//    this->setWindowIcon(QIcon("../image/WindowPicture.jpg"));
    this->setWindowIcon(QIcon(":/picture/image/WindowPicture.jpg"));

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/picture/image/Back2.jpg")));
//    this->setStyleSheet("background-image:url(../image/GameBack.jpg)");
    this->setPalette(palette);

    StartGame = new QPushButton(this);
    StartGame->setIconSize(QSize(90,35));
    StartGame->setGeometry(400,360,90,40);
    StartGame->setIcon(QIcon(":/picture/image/Start.png"));
    StartGame->setStyleSheet("QPushButton{background-color:transparent;}");
    StartGame->setFlat(true);

    ExitGame = new QPushButton(this);
    ExitGame->setIconSize(QSize(90,35));
    ExitGame->setGeometry(400,400,90,45);
    ExitGame->setIcon(QIcon(":/picture/image/Exit.png"));
    ExitGame->setStyleSheet("QPushButton{background-color:transparent;}");
    ExitGame->setFlat(true);

    ExitMsg = new QMessageBox(QMessageBox::NoIcon, "exit", "Are Exit Snake?", QMessageBox::Yes|QMessageBox::No, NULL);
    connect(StartGame, SIGNAL(clicked()), this, SLOT(OnStartGame()));
    connect(ExitGame, SIGNAL(clicked()), this, SLOT(OnExitGame()));
}

Snake::~Snake()
{
    delete ui;
}
void Snake::OnStartGame()
{
    qDebug()<<"enter OnStartGame"<<endl;
    m_game = new GameWidget(this);
    m_game->show();
//    this->hide();
}
void Snake::OnExitGame()
{
    qDebug()<<"enter OnExitGame"<<endl;
    int result = ExitMsg->exec();
    if (result == QMessageBox::Yes){
        exit(0);
    }
}
