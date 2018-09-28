#ifndef STONE_H
#define STONE_H
#include<QString>
#include<QDebug>

// #include"manager.h"
// enum class stein

/**
 * @file Stone.hpp Header file for Stone class
 * @author Iheb Ben Said
 **/


class Stone
{
public:
    /**
     * @brief Stone
     * @param Player
     * @param x_position
     * @param y_position
     * @param Grid_Size
     */
    Stone(QString Player ,int x_position ,int y_position ,int Grid_Size);

//yomken ezouz hedhom menich bech nest7a9hom
    /**
     * @brief setStoneXPos
     * @param x_position
     */
    void setStoneXPos(int x_position);
    /**
     * @brief setStoneYPos
     * @param y_position
     */
    void setStoneYPos(int y_position);
    /**
     * @brief getStonePlayer
     * @return
     */
    QString getStonePlayer();
    /**
     * @brief getXPos
     * @return
     */
    int getXPos();
    /**
     * @brief getYPos
     * @return
     */
    int getYPos();
//******************************************
    /**
     * @brief getStoneXPos
     * @return
     */
    int getStoneXPos();
    /**
     * @brief getStoneYPos
     * @return
     */
    int getStoneYPos();
    /**
     * @brief getPlayer
     * @return
     */
    QString getPlayer();
//----------------- Special XPos and YPos FUNC for Drawing ---------------
    /**
     * @brief getXPosForDrawing
     * @return
     */
    int getXPosForDrawing();

private:
    QString m_Player   ;
    int m_StoneXPos    ;
    int m_StoneYPos    ;
    int m_gridSize = 7 ;

};

#endif // STONE_H
