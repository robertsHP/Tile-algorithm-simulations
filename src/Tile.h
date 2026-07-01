#pragma once

#include <memory>

#include "Scene.h"
#include "Texture.h"
#include "Object.h"
#include "Enums.h"

class Tile : public Object {
    public:
        enum ID : unsigned {
            GREEN = 0,
            RED,
            
            COUNT
        };

        static constexpr int ISO_TXTR_WIDTH = 30;
        static constexpr int ISO_TXTR_HEIGHT = 29;

        static constexpr int TOP_TXTR_WIDTH = 25;
        static constexpr int TOP_TXTR_HEIGHT = 25;

    private:
        Texture *m_txtr;
        ID m_id;
        TileType m_tileType;

    public:
        void setID (ID id) { m_id = id; }   

    public:
        Tile (ID id, SDL_Point pos, TileType tileType, Scene *scene);
        ~Tile () override;

        void input () override;
        void update (float deltaTime) override;
        void draw () override;
};

class IsoTile : public Tile {

};