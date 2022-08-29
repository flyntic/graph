#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_verticalScrollBar_valueChanged(int value);
    void on_horizontalScrollBar_valueChanged(int value);
    void repaint();
    void timerrepaint();
signals :
public:
private:
    Ui::MainWindow *ui;
    double xBegin=-5,xEnd=5,yBegin=-5,yEnd=5,h=0.1,X;
    int N;

    QVector<double>  x,y;
    QTimer timer;
public:
  void setXBegin (double x);
  void setYBegin (double y);

};
#endif // MAINWINDOW_H
