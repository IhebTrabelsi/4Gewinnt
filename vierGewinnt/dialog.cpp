#include "dialog.h"
#include "ui_dialog.h"
#include<QDebug>
#include<QString>

Dialog::Dialog(QWidget *parent, int GridCol, int GridRow ,bool flagbSet6 ,bool flagbSet7):
    QDialog(parent)
    ,ui(new Ui::Dialog)
    ,m_GridCol(GridCol)
    ,m_GridRow(GridRow)
    ,m_flagbSet6(flagbSet6)
    ,m_flagbSet7(flagbSet7)
{
    ui->setupUi(this);
    //-----------------------dependent from flag hide apprpriate buttons -------------------
    if(m_flagbSet6)
        ui->bSet6->setStyleSheet("background-color:rgb(219,38,38,0.6);");
    if(m_flagbSet7)
        ui->bSet7->setStyleSheet("background-color:rgb(219,38,38,0.6);");

    int nWidth = 800;
    int nHeight = 600;

    if (parent != NULL)
        setGeometry((parent->x() + parent->width()/2 - nWidth/2)*(1.4),
        parent->y() + parent->height()/2 - nHeight/2,
        nWidth, nHeight);
    else
        resize(nWidth, nHeight);

    m_StartPointer = new Stone **[m_GridCol];
    for (int i=0 ; i<m_GridCol ;++i)
    {
        m_StartPointer[i] = new Stone* [m_GridRow];
        for(int j=0 ; j<m_GridRow ; ++j)
            m_StartPointer[i][j] = nullptr ;
    }
    for(int i=0; i<7; i++)
    {
     _pushCnt_bSet[i]=1;
    }
    ui->gewonnen->hide();
}

Dialog::~Dialog()
{
    for (int i=0 ; i<m_GridCol ;++i)
    {
        for(int j=0 ; j<m_GridRow ;++j)
        {
            delete m_StartPointer[i][j];
        }
    }

    for(int k=0 ; k<m_GridRow ;++k)
    {
        delete m_StartPointer[k];
    }

    delete m_StartPointer;


    delete ui;
}

void Dialog::gewonnen(QString code)
{
    ui->bSet1->setDisabled(true);
    ui->bSet2->setDisabled(true);
    ui->bSet3->setDisabled(true);
    ui->bSet4->setDisabled(true);
    ui->bSet5->setDisabled(true);
    ui->bSet6->setDisabled(true);
    ui->bSet7->setDisabled(true);
    ui->gewonnen->setText(code);
    ui->gewonnen->show();

}

void Dialog::addStoneInXYPos(QString playerName, int x_Pos, int y_Pos)
{
    /*for (int x=0 ; x<x_Pos ; ++x)
    {
        for(int y=0 ; y<y_Pos ; ++y)
            if(x==x_Pos && y==y_Pos)
            m_StartPointer[x][y] = new Stone(playerName, x,y);
        qDebug()<<"LOBJET TA3MAL";

    }*/
    qDebug()<<"9bal l hachwa";
    m_StartPointer[x_Pos][y_Pos] = new Stone(playerName, x_Pos,y_Pos,m_GridCol);// Ya Rabbi
    qDebug()<<"ba3d l hachwa";
    qDebug()<<x_Pos<<"   "<<y_Pos;
    if(m_StartPointer)
        qDebug()<<" OBJECT CREATED ****  ";

}

Stone *Dialog::accessStoneInXYPos(int x_Pos, int Y_Pos)
{
    return m_StartPointer[x_Pos][Y_Pos];
}

int Dialog::starPointX()
{
    if(m_GridCol==7)
        return 482;
    if(m_GridCol==6)
        return 404;
    if(m_GridCol==5)
        return 326;
    return 0;
}

int Dialog::starPointY()
{
    if(m_GridCol==7)
        return 478;
    if(m_GridCol==6)
        return 400;
    if(m_GridCol==5)
        return 322;
    return 0;
}





void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QRect rec(14,10,60,60);
    QPen framepen(Qt::red);
    framepen.setWidth(3);
    QBrush brush1(Qt::blue);
    QBrush brush2(Qt::yellow);
    painter.setPen(framepen);
    //QBrush brush(Qt::yellow,Qt::SolidPattern);

    for(int i=0 ; i<m_GridCol ;i++){
        for(int j=0 ; j<m_GridRow ;j++){
        rec.setRect(starPointX()-i*78,starPointY()-j*78,60,60);
        //--------->painter.drawEllipse(rec);


    if(m_StartPointer[i][j]!=nullptr)
        {

            if(m_StartPointer[i][j]->getPlayer()=="Player 1")
            {   painter.setBrush(brush1);
                painter.drawEllipse(rec);

                //for(int k=60 ; k>0 ; k--)
                //painter.drawEllipse(starPointX()-i*78,starPointY()-j*78,k,k);
            }
            else
            {
                painter.setBrush(brush2);
                painter.drawEllipse(rec);

            }


        painter.setBrush(Qt::white);

        }
    else {painter.drawEllipse(rec);}




        //painter.fillRect(rec,brush);
        //painter.drawRect(rec);

        }
    }
}

void Dialog::addStone(int x)
{
    qDebug() << "Stone ------------------- added ";
    QString _NameHolder;
    if(m_Globalcnt%2)
        _NameHolder="Player 1";
    else
        _NameHolder="Player 2";
    if(_pushCnt_bSet[x]<m_GridCol+1){
    addStoneInXYPos(_NameHolder,m_GridCol-1-x,_pushCnt_bSet[x]-1);// Badalt el 6 bel 5 juste bech njarreb
    repaint(0,0,800,600);
    }
//    if(_pushCnt_bSet[x]<m_GridRow+1)
//    {
//        Stone* StoneTestPointer;
//        StoneTestPointer = accessStoneInXYPos(m_GridCol-1-x,_pushCnt_bSet[x]-1);
//     }
    _pushCnt_bSet[x]++;
    m_Globalcnt++;

}

void Dialog::on_bSet1_clicked()
{
    //addStone(0);
    emit sendZug(0);
}

void Dialog::on_bSet2_clicked()
{
    //addStone(1);
    emit sendZug(1);
}

void Dialog::on_bSet3_clicked()
{
    //addStone(2);
    emit sendZug(2);
}

void Dialog::on_bSet4_clicked()
{
    //addStone(3);
    emit sendZug(3);
}

void Dialog::on_bSet5_clicked()
{
    //addStone(4);
    emit sendZug(4);
}

void Dialog::on_bSet6_clicked()
{
    //addStone(5);
    emit sendZug(5);
}

void Dialog::on_bSet7_clicked()
{
    //addStone(6);
    emit sendZug(6);
}

void Dialog::on_bSet1_pressed()
{
    qDebug()<<"pressed--------------------------------------------------";
}

//void Dialog::on_pushButton_clicked()
//{
//    repaint(0,0,800,600);
//}
