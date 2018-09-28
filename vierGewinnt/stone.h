#ifndef STONE_H
#define STONE_H
#include<QString>
#include<QDebug>

// #include"manager.h"
// enum class stein



class Stone
{
public:
    Stone(QString Player ,int x_position ,int y_position ,int Grid_Size);

//yomken ezouz hedhom menich bech nest7a9hom
    void setStoneXPos(int x_position);
    void setStoneYPos(int y_position);
    QString getStonePlayer();
    int getXPos();
    int getYPos();
//******************************************
    int getStoneXPos();
    int getStoneYPos();
    QString getPlayer();
//----------------- Special XPos and YPos FUNC for Drawing ---------------

    int getXPosForDrawing();

private:
    QString m_Player   ;
    int m_StoneXPos    ;
    int m_StoneYPos    ;
    int m_gridSize = 7 ;

};

#endif // STONE_H
