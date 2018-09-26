/*
#include "dialog.h"
#include <QApplication>
#include "connector.hpp"
*/

#include "manager.hpp"


/**
 * @file main.cpp mainfuction for corelogik test
 * @author Simon Näther
 **/

int main(int argc, char *argv[])
{


    Manager manager;
    bool running = true;
    manager.setSingleplayer();
    manager.printGrid();

    while (running){
        running= manager.testSinglePlayer();

    }
    std::cout<<"Enter something to close:"<<std::endl;
    int hold;
    std::cin>>hold;
    return 0;
}

