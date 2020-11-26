#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    MyCircle *c;

    c = new MyCircle(0, this);

    ui->setupUi(this);

    ui->verticalLayout->addWidget(c);

    QObject::connect(ui->hSlider,SIGNAL(valueChanged(int)),c,SLOT(setValue(int)));

}


MainWindow::~MainWindow()
{
    delete ui;
}

MyCircle::MyCircle(int value, QWidget *parent) : QWidget(parent)
{
    m_value = value;
}

int MyCircle::heightForWidth(int width) const
{
    return width;
}

QSize MyCircle::sizeHint() const
{
    return QSize(100, 100);
}

int MyCircle::value() const
{
    return m_value;
}

void MyCircle::setValue(int value)
{
    if (value < 0)
        value = 0;
    if (value > 100)
        value = 100;
    if (m_value == value)
        return;

    m_value = value;
    update();
    emit valueChanged(m_value);
}


void MyCircle::paintEvent(QPaintEvent *event)
{
    drawMyFigure();
}

void MyCircle::drawMyFigure()
{
    int radius = width()/2;
    double factor = value()/100.0;

    QPainter p(this);
    p.setPen(Qt::black);
    p.drawEllipse(0,0,width()-1,width()-1);
    p.setBrush(Qt::black);
    p.drawEllipse(
                (int)(radius*(1.0-factor)),
                (int)(radius*(1.0-factor)),
                (int)((width()-1)*factor)+1,
                (int)((width()-1)*factor)+1);
}




