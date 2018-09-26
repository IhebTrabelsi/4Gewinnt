#include "stone.h"


Stone::Stone(QString Player, int x_position, int y_position, int Grid_Size):m_Player(Player)
  ,m_StoneXPos(x_position)
  ,m_StoneYPos(y_position)
  ,m_gridSize(Grid_Size)
{
    /*****
     * by construction of a Stone object we call Paint //MAYBE//
     * and we pass all Stone parameter  Or actually we don't have to we
     * just send the event , and dependent to the Paint implementation
     * the function go draw directly from the Grid
    *****/
}

void Stone::setStoneXPos(int x_position)
{
    m_StoneXPos=x_position;
}

void Stone::setStoneYPos(int y_position)
{
    m_StoneYPos=y_position;
}

QString Stone::getStonePlayer()
{
    return m_Player;
}

int Stone::getXPos()
{
    return m_StoneXPos;
}

int Stone::getYPos()
{
    return m_StoneYPos;
}

int Stone::getStoneXPos()
{
    return m_StoneXPos;
}

int Stone::getStoneYPos()
{
    return m_StoneYPos;
}

int Stone::getXPosForDrawing()
{
    switch (m_StoneXPos) {

        case 6 :{if(m_gridSize==7)return 0;                                                                  break;}
        case 5 :{if(m_gridSize==7)return 1;if(m_gridSize==6)return 0;                                        break;}
        case 4 :{if(m_gridSize==7)return 2;if(m_gridSize==6)return 1; if(m_gridSize==5)return 0;             break;}
        case 3 :{if(m_gridSize==7)return 3;if(m_gridSize==6)return 2; if(m_gridSize==5)return 1;             break;}
        case 2 :{if(m_gridSize==7)return 4;if(m_gridSize==6)return 3; if(m_gridSize==5)return 2;             break;}
        case 1 :{if(m_gridSize==7)return 5;if(m_gridSize==6)return 4; if(m_gridSize==5)return 3;             break;}
        case 0 :{if(m_gridSize==7)return 6;if(m_gridSize==6)return 5; if(m_gridSize==5)return 4;             break;}
    default:qDebug()<<"out of scopeeeeee";


    }
}

int Stone::getYPosForDrawing()
{
    /*

        hne yomken ki nrakah el SCALING nwali nda5el les valeurs toul fel SWITCH

    */

    /*

    switch (m_StoneYPos) {

        case 6 :{return 0;break;}
        case 5 :{return 1;break;}
        case 4 :{return 2;break;}
        case 3 :{return 3;break;}
        case 2 :{return 4;break;}
        case 1 :{return 5;break;}
        case 0 :{return 6;break;}
    default:qDebug()<<"out of scopeeeeee";


    }*/
}
