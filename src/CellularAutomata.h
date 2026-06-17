#pragma once

#include <iostream>
#include <cstdlib>
#include <cstring>

#include <memory>

#include "TileMap.h"
#include "Timer.h"

class CellularAutomata {
    private:
        const int MAP_WIDTH = 70;
        const int MAP_HEIGHT = 50;

        int *m_output;
        int *m_state;

        TileMap *m_tileMap;
        Timer m_timer;

    public:
        CellularAutomata (TileMap *tileMap);
        ~CellularAutomata ();

        void updateTiles ();
        // void draw();
        // void input();
};


