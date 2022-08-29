#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmath.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    repaint();
    connect(ui->rbXX,   SIGNAL(clicked()), this, SLOT(repaint()));
    connect(ui->rbsinx, SIGNAL(clicked()), this, SLOT(repaint()));
    connect(ui->rb2x,   SIGNAL(clicked()), this, SLOT(repaint()));
    connect(ui->rbsqrt,   SIGNAL(clicked()), this, SLOT(repaint()));

 //   connect(timer, SIGNAL(timeout),this,SLOT(timerrepaint()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_verticalScrollBar_valueChanged(int value)
{
    setYBegin(value);
}


void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
      setXBegin(value);
}

void MainWindow::repaint()
{
    h=xEnd/20;

    ui->widget->xAxis->setRange(xBegin,xEnd);
    ui->widget->yAxis->setRange(yBegin,yEnd);

    ui->widget->clearGraphs();

    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(Qt::red));

    ui->widget->addGraph();
    ui->widget->graph(1)->setPen(QPen(Qt::green));

    ui->widget->addGraph();
    ui->widget->graph(2)->setPen(QPen(Qt::yellow));

    ui->widget->addGraph();
    ui->widget->graph(2)->setPen(QPen(Qt::blue));

    if (ui->rbXX->isChecked())
    {
    for (X=xBegin;X<=xEnd;X+=h)
    {
        x.push_back(X);
        y.push_back(X*X);
    }
    ui->widget->graph(0)->addData(x,y);
    }

    x.clear();
    y.clear();
    if (ui->rb2x->isChecked())
    {
    for (X=xBegin;X<=xEnd;X+=h)
    {
        x.push_back(X);
        y.push_back(2*X);
    }
    ui->widget->graph(1)->addData(x,y);
    }
    x.clear();
    y.clear();

    if (ui->rbsinx->isChecked())
    {
    for (X=xBegin;X<=xEnd;X+=h)
    {
        x.push_back(X);
        y.push_back(qSin(X));
    }
    ui->widget->graph(2)->addData(x,y);
    x.clear();
    y.clear();
    }

    if (ui->rbsqrt->isChecked())
    {
    for (X=xBegin;X<=xEnd;X+=h)
    {
        x.push_back(X);
        y.push_back(qSqrt(X));
    }
    ui->widget->graph(3)->addData(x,y);
    x.clear();
    y.clear();
    }

    ui->widget->replot();

}

void MainWindow::timerrepaint()
{

}

void MainWindow::setXBegin(double x)
{
    xBegin=-x;
    xEnd=x;
    repaint();
}

void MainWindow::setYBegin(double y)
{
    yBegin=-y;
    yEnd=y;

    repaint();
}

