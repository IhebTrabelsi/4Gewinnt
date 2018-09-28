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
    /**
     * @brief Dialog
     * @param parent
     * @param GridCol
     * @param GridRow
     * @param flagbSet6
     * @param flagbSet7
     */
    explicit Dialog(QWidget *parent = nullptr ,int GridCol=7 ,int GridRow=7 ,bool flagbSet6 = false ,bool flagbSet7 = false);  //
    ~Dialog();
    /**
     * @brief addStoneInXYPos
     * @param playerName
     * @param x_Pos
     * @param y_Pos
     */
    void addStoneInXYPos(QString playerName ,int x_Pos ,int y_Pos);

    Stone *accessStoneInXYPos(int x_Pos ,int Y_Pos);
    /**
     * @brief starPointX
     * @return
     */
    int starPointX();
    /**
     * @brief starPointY
     * @return
     */
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
    Stone*** m_StartPointer; // array where every stone is called/stored

    int _pushCnt_bSet[7];

protected:
    /**
     * @brief paintEvent
     * @param e
     */
    void paintEvent(QPaintEvent *e);
signals:
    /**
     * @brief sendZug
     */
    void sendZug(quint8);
    /**
     * @brief nextRound
     */
    void nextRound();
public slots:
    /**
     * @brief on_bSet7_clicked
     */
    void on_bSet7_clicked();
    /**
     * @brief on_bSet4_clicked
     */
    void on_bSet4_clicked();
    /**
     * @brief on_bSet5_clicked
     */
    void on_bSet5_clicked();
    /**
     * @brief on_bSet6_clicked
     */
    void on_bSet6_clicked();
    /**
     * @brief on_bSet1_clicked
     */
    void on_bSet1_clicked();
    /**
     * @brief on_bSet2_clicked
     */
    void on_bSet2_clicked();
    /**
     * @brief on_bSet3_clicked
     */
    void on_bSet3_clicked();
    /**
     * @brief on_bSet1_pressed
     */
    void on_bSet1_pressed();
    /**
     * @brief addStone
     * @param x
     */
    void addStone(int x);
    /**
     * @brief gewonnen
     */
    void gewonnen(QString);
    /**
     * @brief setRunde
     * @param number
     */
    void setRunde(quint8 number);
    /**
     * @brief setRunde2
     * @param number
     */
    void setRunde2(quint8 number);
    /**
     * @brief setPunkteIch
     * @param number
     */
    void setPunkteIch(quint8 number);
    /**
     * @brief setPunkteGegner
     * @param number
     */
    void setPunkteGegner(quint8 number);
    /**
     * @brief disableNextRoundButton
     * @param yesNo
     */
    void disableNextRoundButton(bool yesNo);
    /**
     * @brief toggleNextButton
     * @param yesNo
     */
    void toggleNextButton(bool yesNo);
   // void on_pushButton_clicked();
private slots:
    /**
     * @brief on_newRound_clicked
     */
    void on_newRound_clicked();
};

#endif // DIALOG_H
