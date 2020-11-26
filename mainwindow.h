#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class MyCircle: public QWidget
{
    Q_OBJECT

public:
    MyCircle(int value, QWidget *parent);
    int value() const;
    int heightForWidth(int) const;
    QSize sizeHint() const;

public slots:
    void setValue(int);

signals:
    void valueChanged(int);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_value;
    void drawMyFigure();
};

#endif // MAINWINDOW_H
