#include "gamewidget.h"
#include <QIcon>
GameWidget::GameWidget(QWidget *parent)
    :QWidget(parent)
{
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    setWindowFlags(Qt::Window);
    setFixedSize(QSize(891,510));
    setAutoFillBackground(true);
    setWindowTitle("cxtan");
    setWindowIcon(QIcon(":/picture/image/WindowPicture.jpg"));
    Rand_count = time(NULL);
    qsrand(Rand_count);
    Score = 0;
    Difficulty = 1;

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/picture/image/GameBack.jpg")));
    this->setPalette(palette);

    UpButton = new QPushButton(this);
    DownButton = new QPushButton(this);
    LeftButton = new QPushButton(this);
    RightButton = new QPushButton(this);
    StartButton = new QPushButton(this);
    ExitButton = new QPushButton(this);
    ScoreLabel = new QLabel("Score :", this);
    LevelLabel = new QLabel("Level :", this);
    ScoreLabelNumber = new QLabel(this);
    LevelLabelNumber = new QLabel(this);

    ButtonGroup = new QButtonGroup(this);
    ButtonGroup->addButton(UpButton, 1);
    ButtonGroup->addButton(DownButton, 2);
    ButtonGroup->addButton(LeftButton, 3);
    ButtonGroup->addButton(RightButton, 4);
    connect(ButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(on_setDiretion(int)));

    UpButton->setIconSize(QSize(45,90));
    UpButton->setGeometry(750,160,45,90);
    UpButton->setIcon(QIcon(":/picture/image/up.png"));
    UpButton->setStyleSheet("QPushButton{background-color:transparent;}");
    UpButton->setFlat(true);

    DownButton->setIconSize(QSize(45,90));
    DownButton->setGeometry(750,250,45,90);
    DownButton->setIcon(QIcon(":/picture/image/down.png"));
    DownButton->setStyleSheet("QPushButton{background-color:transparent;}");
    DownButton->setFlat(true);

    LeftButton->setIconSize(QSize(90,45));
    LeftButton->setGeometry(680,227,90,45);
    LeftButton->setIcon(QIcon(":/picture/image/left.png"));
    LeftButton->setStyleSheet("QPushButton{background-color:transparent;}");
    LeftButton->setFlat(true);

    RightButton->setIconSize(QSize(90,45));
    RightButton->setGeometry(775,227,90,45);
    RightButton->setIcon(QIcon(":/picture/image/right.png"));
    RightButton->setStyleSheet("QPushButton{background-color:transparent;}");
    RightButton->setFlat(true);

    StartButton->setIconSize(QSize(90,35));
    StartButton->setGeometry(650,400,90,35);
    StartButton->setIcon(QIcon(":/picture/image/Start.png"));
    StartButton->setStyleSheet("QPushButton{background-color:transparent;}");
    StartButton->setFlat(true);

    ExitButton->setIconSize(QSize(90,35));
    ExitButton->setGeometry(800,400,90,35);
    ExitButton->setIcon(QIcon(":/picture/image/Exit.png"));
    ExitButton->setStyleSheet("QPushButton{background-color:transparent;}");
    ExitButton->setFlat(true);

    ScoreLabel->setGeometry(650, 100, 90, 45);

    ScoreLabelNumber->setText(QString::number(Score)+codec->toUnicode(" 分"));
    ScoreLabelNumber->setGeometry(700, 100, 90, 45);

    LevelLabel->setGeometry(650, 70, 90, 45);
    LevelLabelNumber->setText(QString::number(Difficulty)+codec->toUnicode(" 级"));
    LevelLabelNumber->setGeometry(700, 70, 90, 45);

}
void GameWidget::on_setDiretion(int index)
{
    qDebug()<<"enter on_setDiretion index: "<<index<<endl;
}
