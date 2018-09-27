#ifndef DIALOG_H
#define DIALOG_H

#include<QDialog>
#include<QtGui>
#include<QtCore>
#include<vector>
#include"stone.h"
//#include<memory>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr ,int GridCol=7 ,int GridRow=7 ,bool flagbSet6 = false ,bool flagbSet7 = false);  //
    ~Dialog();

    void addStoneInXYPos(QString playerName ,int x_Pos ,int y_Pos);
    Stone *accessStoneInXYPos(int x_Pos ,int Y_Pos);
    int starPointX();
    int starPointY();


public:
    Ui::Dialog *ui;
    int m_GridCol;
    int m_GridRow;
    //------------------------FLAGS OF HIDDEN PUSH BUTTONS--------------------------------
    bool m_flagbSet6 = false;
    bool m_flagbSet7 = false;

    //-------------- Global counter to distinguish number of player-----------------------
    int m_Globalcnt =0;
    Stone* StoneTestPointer;
    Stone*** m_StartPointer; // array where every stone is called/stored

    //Stone* m_ArrayOfPointersXpos[7];// this will be handled in constructor so it can be deleted after
    //destroying it or( implement ) in destructor


    // Creation mta3 Vector of pointers ysir fi mainwindow ki sayed yekhtar 9adech men cases yheb
    // ama pour le moment lel test na3malha dima 7x7
    int _pushCnt_bSet[7];

protected:
    void paintEvent(QPaintEvent *e);
signals:
    void sendZug(quint8);
public slots:

    void on_bSet7_clicked();
    void on_bSet4_clicked();
    void on_bSet5_clicked();
    void on_bSet6_clicked();
    void on_bSet1_clicked();
    void on_bSet2_clicked();
    void on_bSet3_clicked();
    void on_bSet1_pressed();
    void addStone(int x);
   // void on_pushButton_clicked();
};

#endif // DIALOG_H
