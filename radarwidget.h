#ifndef RADARWIDGET_H
#define RADARWIDGET_H

#include <QWidget>
#include <QPainter>


class RadarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RadarWidget(QWidget *parent = nullptr);


protected:
    void paintEvent(QPaintEvent *event) override;  // 重载paintEvent以自定义绘制

private:
    int angle;
    QTimer* timer;

signals:

};

#endif // RADARWIDGET_H
