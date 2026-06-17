#pragma once

#include <memory>

#include "Tile.h"

class TileMap {
    public:
        enum View {
            ISOMETRIC, TOP
        };

    private:
        Scene *m_associatedScene;
        
        std::map<int, std::unique_ptr<Tile>> m_tiles;

        // Piece *wPieces;
        // Piece *bPieces;

        union {
            struct {
                int m_x, m_y;
                unsigned m_w, m_h;
            };
            SDL_Rect m_rect;
        };

        int m_gapWidth, m_gapHeight;

    public:
        SDL_Rect& getRect () { return m_rect; }
        std::unique_ptr<Tile>& getTile (SDL_Point pos) { 
            return m_tiles[pos.y * m_w + pos.x]; 
        }

    public:
        TileMap (SDL_Point pos, SDL_Point size, Scene *scene);
        ~TileMap ();

        void input ();
        void update (float deltaTime);
        void draw ();
};

