#include "snake.h"
#include "ui_snake.h"

Snake::Snake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Snake)
{
    ui->setupUi(this);
}

Snake::~Snake()
{
    delete ui;
}
