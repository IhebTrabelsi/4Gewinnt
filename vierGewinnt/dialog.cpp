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
    /*
     * Hne 3malt Grid mta3 Pointers bech add mta3 stones ysir dynamically ( [][] = new Stone ...
     *
     */
    m_StartPointer = new Stone **[m_GridCol];
    for (int i=0 ; i<m_GridCol ;++i)
    {
        m_StartPointer[i] = new Stone* [m_GridRow];
        for(int j=0 ; j<m_GridRow ; ++j)
            m_StartPointer[i][j] = nullptr ;
    }

    qDebug()<< m_GridCol <<"   "<< m_GridRow ;
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



void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QRect rec(14,10,60,60);
    QPen framepen(Qt::red);
    framepen.setWidth(3);
    painter.setPen(framepen);
    QBrush brush(Qt::yellow,Qt::SolidPattern);

    for(int i=0 ; i<m_GridCol ;i++){
        for(int j=0 ; j<m_GridRow ;j++){
        rec.setRect(14+i*78,10+j*78,60,60);
        painter.drawEllipse(rec);
        //if(i==1&&j==1)painter.drawRect(rec); this was for testing in which rheinfolge does the circles get drawn
        if(m_StartPointer[i][j]!=nullptr)
        {

            painter.fillRect(rec, brush);



            /*QRect rec2(-42+(m_StartPointer[i][j]->getXPosForDrawing())*60 ,(m_StartPointer [i][j]->getStoneYPos())*60 ,60,60 );
            painter.drawRect(rec2);*/

            //QRect rec2((-42+i*80),(380-j*80),60,60);
            //painter.drawRect(rec2);
            qDebug()<<"Stone XPOS"<<m_StartPointer [i][j]->getXPosForDrawing()<<
                      "Stone YPOS"<<m_StartPointer [i][j]->getStoneYPos()<<
                      "Value i"<<i<<"    "<<"Value J"<<j;

            //painter.drawRect(rec);
        }




        //painter.fillRect(rec,brush);
        //painter.drawRect(rec);

        }
    }

}

void Dialog::on_bSet1_clicked()
{   qDebug()<<"Clicked";
    QString _NameHolder;
    if(m_Globalcnt%2)
        _NameHolder="Player 1";
    else
        _NameHolder="Player 2";
    static int pushCnt_bSet1 = 1;
    if(pushCnt_bSet1<m_GridCol+1){
        qDebug()<<"entred to if";
        addStoneInXYPos(_NameHolder,m_GridCol-1,pushCnt_bSet1-1);// Badalt el 6 bel 5 juste bech njarreb
        repaint(0,0,800,600);

    }
    qDebug()<<"EXIT FROM if";
    if(pushCnt_bSet1<m_GridRow+1)
    {   qDebug()<<"entred to second IF";
        Stone* StoneTestPointer;
        StoneTestPointer = accessStoneInXYPos(m_GridCol-1,pushCnt_bSet1-1);
        qDebug()<<m_GridCol-1<<"    "<<pushCnt_bSet1-1;
        qDebug()<<StoneTestPointer->getStonePlayer()<<"   "<<
                  StoneTestPointer->getStoneXPos()<<"    "<<
                  StoneTestPointer->getStoneYPos();
        /*----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *
         *       nokhrej ennik sigarou ou narja3 man9oul l zok ommek el 9a7ba
         *Le 22/09/2018 20:18 avec Amir Bouazizi à l' EIKON TUM
         *----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *

         *
         *----------------------------------------------------------------------
         *---------------------------------------------------------------------*/
     }
    pushCnt_bSet1++;
    m_Globalcnt++;

}

void Dialog::on_bSet2_clicked()
{
    QString _NameHolder;
    if(m_Globalcnt%2)
        _NameHolder="Player 1";
    else
        _NameHolder="Player 2";
    static int pushCnt_bSet2 = 1;
    if(pushCnt_bSet2<m_GridCol+1){
        qDebug()<<"entred to if";
        addStoneInXYPos(_NameHolder,m_GridCol-2,pushCnt_bSet2-1);// EL m_GridCol-2<---- el 2 nafs ennoumrou mtaa bouton
        repaint(0,0,800,600);

    }
    //-----------------------TEST of the second button ------------------

    if(pushCnt_bSet2<m_GridRow+1)
    {   qDebug()<<"entred to second IF";
        Stone* StoneTestPointer;
        StoneTestPointer = accessStoneInXYPos(m_GridCol-2,pushCnt_bSet2-1);// KIF KIF YETBADEL nafs noumrou l bouton hne
        qDebug()<<m_GridCol-2<<"    "<<pushCnt_bSet2-1;                    // HNE ZEDA
        qDebug()<<StoneTestPointer->getStonePlayer()<<"   "<<
                  StoneTestPointer->getStoneXPos()<<"    "<<
                  StoneTestPointer->getStoneYPos();
        /*----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *
         *       nokhrej ennik sigarou ou narja3 man9oul l zok ommek el 9a7ba
         *Le 22/09/2018 20:18 avec Amir Bouazizi à l' EIKON TUM
         *----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *

         *
         *----------------------------------------------------------------------
         *---------------------------------------------------------------------*/
     }















    pushCnt_bSet2++;
    m_Globalcnt++;
}

void Dialog::on_bSet3_clicked()
{
    QString _NameHolder;
    if(m_Globalcnt%2)
        _NameHolder="Player 1";
    else
        _NameHolder="Player 2";
    static int pushCnt_bSet3 = 1;
    if(pushCnt_bSet3<m_GridCol+1){
        qDebug()<<"entred to if";
        addStoneInXYPos(_NameHolder,m_GridCol-3,pushCnt_bSet3-1);// EL m_GridCol-2<---- el 2 nafs ennoumrou mtaa bouton
        repaint(0,0,800,600);

    }
    //-----------------------TEST of the second button ------------------

    if(pushCnt_bSet3<m_GridRow+1)
    {   qDebug()<<"entred to second IF";
        Stone* StoneTestPointer;
        StoneTestPointer = accessStoneInXYPos(m_GridCol-3,pushCnt_bSet3-1);// KIF KIF YETBADEL nafs noumrou l bouton hne
        qDebug()<<m_GridCol-3<<"    "<<pushCnt_bSet3-1;                    // HNE ZEDA
        qDebug()<<StoneTestPointer->getStonePlayer()<<"   "<<
                  StoneTestPointer->getStoneXPos()<<"    "<<
                  StoneTestPointer->getStoneYPos();
        /*----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *
         *       nokhrej ennik sigarou ou narja3 man9oul l zok ommek el 9a7ba
         *Le 22/09/2018 20:18 avec Amir Bouazizi à l' EIKON TUM
         *----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *

         *
         *----------------------------------------------------------------------
         *---------------------------------------------------------------------*/
     }


    pushCnt_bSet3++;
    m_Globalcnt++;
}

void Dialog::on_bSet4_clicked()
{
    QString _NameHolder;
    if(m_Globalcnt%2)
        _NameHolder="Player 1";
    else
        _NameHolder="Player 2";
    static int pushCnt_bSet4 = 1;
    if(pushCnt_bSet4<m_GridCol+1){
        qDebug()<<"entred to if";
        addStoneInXYPos(_NameHolder,m_GridCol-4,pushCnt_bSet4-1);// EL m_GridCol-2<---- el 2 nafs ennoumrou mtaa bouton
        repaint(0,0,800,600);

    }
    //-----------------------TEST of the second button ------------------

    if(pushCnt_bSet4<m_GridRow+1)
    {   qDebug()<<"entred to second IF";
        Stone* StoneTestPointer;
        StoneTestPointer = accessStoneInXYPos(m_GridCol-4,pushCnt_bSet4-1);// KIF KIF YETBADEL nafs noumrou l bouton hne
        qDebug()<<m_GridCol-4<<"    "<<pushCnt_bSet4-1;                    // HNE ZEDA
        qDebug()<<StoneTestPointer->getStonePlayer()<<"   "<<
                  StoneTestPointer->getStoneXPos()<<"    "<<
                  StoneTestPointer->getStoneYPos();
        /*----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *
         *       nokhrej ennik sigarou ou narja3 man9oul l zok ommek el 9a7ba
         *Le 22/09/2018 20:18 avec Amir Bouazizi à l' EIKON TUM
         *----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *

         *
         *----------------------------------------------------------------------
         *---------------------------------------------------------------------*/
     }


    pushCnt_bSet4++;
    m_Globalcnt++;
}

void Dialog::on_bSet5_clicked()
{
    QString _NameHolder;
    if(m_Globalcnt%2)
        _NameHolder="Player 1";
    else
        _NameHolder="Player 2";
    static int pushCnt_bSet5 = 1;
    if(pushCnt_bSet5<m_GridCol+1){
        qDebug()<<"entred to if";
        addStoneInXYPos(_NameHolder,m_GridCol-5,pushCnt_bSet5-1);// EL m_GridCol-2<---- el 2 nafs ennoumrou mtaa bouton
        repaint(0,0,800,600);

    }
    //-----------------------TEST of the second button ------------------

    if(pushCnt_bSet5<m_GridRow+1)
    {   qDebug()<<"entred to second IF";
        Stone* StoneTestPointer;
        StoneTestPointer = accessStoneInXYPos(m_GridCol-5,pushCnt_bSet5-1);// KIF KIF YETBADEL nafs noumrou l bouton hne
        qDebug()<<m_GridCol-5<<"    "<<pushCnt_bSet5-1;                    // HNE ZEDA
        qDebug()<<StoneTestPointer->getStonePlayer()<<"   "<<
                  StoneTestPointer->getStoneXPos()<<"    "<<
                  StoneTestPointer->getStoneYPos();
        /*----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *
         *       nokhrej ennik sigarou ou narja3 man9oul l zok ommek el 9a7ba
         *Le 22/09/2018 20:18 avec Amir Bouazizi à l' EIKON TUM
         *----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *

         *
         *----------------------------------------------------------------------
         *---------------------------------------------------------------------*/
     }


    pushCnt_bSet5++;
    m_Globalcnt++;
}

void Dialog::on_bSet6_clicked()
{
    QString _NameHolder;
    if(m_Globalcnt%2)
        _NameHolder="Player 1";
    else
        _NameHolder="Player 2";
    static int pushCnt_bSet6 = 1;
    if(pushCnt_bSet6<m_GridCol+1){
        qDebug()<<"entred to if";
        addStoneInXYPos(_NameHolder,m_GridCol-6,pushCnt_bSet6-1);// EL m_GridCol-2<---- el 2 nafs ennoumrou mtaa bouton
        repaint(0,0,800,600);

    }
    //-----------------------TEST of the second button ------------------

    if(pushCnt_bSet6<m_GridRow+1)
    {   qDebug()<<"entred to second IF";
        Stone* StoneTestPointer;
        StoneTestPointer = accessStoneInXYPos(m_GridCol-6,pushCnt_bSet6-1);// KIF KIF YETBADEL nafs noumrou l bouton hne
        qDebug()<<m_GridCol-6<<"    "<<pushCnt_bSet6-1;                    // HNE ZEDA
        qDebug()<<StoneTestPointer->getStonePlayer()<<"   "<<
                  StoneTestPointer->getStoneXPos()<<"    "<<
                  StoneTestPointer->getStoneYPos();
        /*----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *
         *       nokhrej ennik sigarou ou narja3 man9oul l zok ommek el 9a7ba
         *Le 22/09/2018 20:18 avec Amir Bouazizi à l' EIKON TUM
         *----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *

         *
         *----------------------------------------------------------------------
         *---------------------------------------------------------------------*/
     }


    pushCnt_bSet6++;
    m_Globalcnt++;
}

void Dialog::on_bSet7_clicked()
{
    QString _NameHolder;
    if(m_Globalcnt%2)
        _NameHolder="Player 1";
    else
        _NameHolder="Player 2";
    static int pushCnt_bSet7 = 1;
    if(pushCnt_bSet7<m_GridCol+1){
        qDebug()<<"entred to if";
        addStoneInXYPos(_NameHolder,m_GridCol-7,pushCnt_bSet7-1);// EL m_GridCol-2<---- el 2 nafs ennoumrou mtaa bouton
        repaint(0,0,800,600);

    }
    //-----------------------TEST of the second button ------------------

    if(pushCnt_bSet7<m_GridRow+1)
    {   qDebug()<<"entred to second IF";
        Stone* StoneTestPointer;
        StoneTestPointer = accessStoneInXYPos(m_GridCol-7,pushCnt_bSet7-1);// KIF KIF YETBADEL nafs noumrou l bouton hne
        qDebug()<<m_GridCol-7<<"    "<<pushCnt_bSet7-1;                    // HNE ZEDA
        qDebug()<<StoneTestPointer->getStonePlayer()<<"   "<<
                  StoneTestPointer->getStoneXPos()<<"    "<<
                  StoneTestPointer->getStoneYPos();
        /*----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *
         *       nokhrej ennik sigarou ou narja3 man9oul l zok ommek el 9a7ba
         *Le 22/09/2018 20:18 avec Amir Bouazizi à l' EIKON TUM
         *----------------------------------------------------------------------
         *----------------------------------------------------------------------
         *

         *
         *----------------------------------------------------------------------
         *---------------------------------------------------------------------*/
     }


    pushCnt_bSet7++;
    m_Globalcnt++;
}

void Dialog::on_bSet1_pressed()
{
    qDebug()<<"pressed--------------------------------------------------";
}
