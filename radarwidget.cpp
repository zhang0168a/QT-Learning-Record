#include "radarwidget.h"
#include<QTimer>

RadarWidget::RadarWidget(QWidget *parent)
    : QWidget{parent}
{

    // 设置控件的大小、样式
        // setFixedSize(500, 500);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        angle +=1;
        if(angle>360){
            angle=0;

        } update();
    });
    timer->start(30);
}

void RadarWidget::paintEvent(QPaintEvent *event)
{
    (void) event;
    QPainter painter(this);  // 创建绘制工具
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setBrush(Qt::black);  // 设置画刷颜色
    painter.drawRect(this->rect());  // 绘制一个矩形


    int side = qMin(width(),height())/2/6;
    painter.setPen(QPen(Qt::blue,4));  // 设置画刷颜色
    painter.translate(rect().center());
    painter.setBrush(Qt::NoBrush);

    for(int i=1 ; i<=6;i++){
        painter.drawEllipse(QPoint(0,0),side*i,side*i);
    }


    //绘制参考线
    //正交
    painter.drawLine(-side*6,0,side*6,0);
    painter.drawLine(0,-side*6,0,side*6);
    //斜线
    painter.drawLine(0 + (side*6) * qCos(M_PI / 4),0 + (side*6) * qSin(M_PI / 4),0 + (side*6) * qCos(M_PI *1.25),0 + (side*6) * qSin(M_PI*1.25));
    painter.drawLine(0 + (side*6) * qCos(M_PI * 0.75),0 + (side*6) * qSin(M_PI * 0.75),0 + (side*6) * qCos(M_PI *1.75),0 + (side*6) * qSin(M_PI*1.75));


    QConicalGradient  co(0,0,angle);
            co.setColorAt(0,QColor(0,255,0,200));
             co.setColorAt(0.1,QColor(0,255,0,100));
              co.setColorAt(0.2,QColor(0,255,0,0));
               co.setColorAt(1,QColor(0,255,0,0));

    painter.setPen(Qt::NoPen);
            painter.setBrush(co);
            painter.drawPie(-qMin(width(),height()/2), -qMin(width(),height()/2), qMin(width(),height()), qMin(width(),height()),angle*16,72*16 );




}
