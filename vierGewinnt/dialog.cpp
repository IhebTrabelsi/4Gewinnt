#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

            int nWidth = 800;
            int nHeight = 600;
            if (parent != NULL)
                setGeometry((parent->x() + parent->width()/2 - nWidth/2)*(1.4),
                    parent->y() + parent->height()/2 - nHeight/2,
                    nWidth, nHeight);
            else
                resize(nWidth, nHeight);

}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QRect rec(14,10,60,60);
    QPen framepen(Qt::red);
    framepen.setWidth(3);
    painter.setPen(framepen);
    //QBrush brush(Qt::yellow,Qt::SolidPattern);

    for(int i=0 ; i<GridRow ;i++){
        for(int j=0 ; j<GridCol ;j++){
        rec.setRect(14+j*78,10+i*78,60,60);
        //painter.fillRect(rec,brush);
        //painter.drawRect(rec);
        painter.drawEllipse(rec);
        }
    }

}

