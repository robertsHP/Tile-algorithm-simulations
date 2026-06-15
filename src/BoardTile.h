#pragma once

#include <memory>

#include "Texture.h"


// class Object {
//     private:
//         std::unique_ptr<Texture> txtr;

//         unsigned int txtrIndex;
//         union {
//             struct { Uint8 r, g, b, a; };
//             SDL_Color color;
//         };
//         union {
//             struct {
//                 int x, y;
//                 int w, h;
//             };
//             SDL_Rect rect;
//         };
//         int       xVel, yVel;
//         double    angle;
//         SDL_Point anglePoint;

//         //Position on the gameMap
//         union {
//             struct { 
//                 unsigned int xGM, yGM; 
//             };
//             SDL_Point posGM;
//         };

//     public:


// };



class BoardTile {
    public:
        enum ID {
            LIGHT = 0,
            DARK,
            POS_MOV,
            IMPOS_MOV,
            TEX_SEL
        };

    private:
        std::shared_ptr<TextureSheet> m_txtr;
        unsigned m_txtrSheetIndex;

        ID m_id;
    
        // std::unique_ptr<Texture> txtr;
        // unsigned txtrIndex;

        // union {
        //     struct { Uint8 r, g, b, a; };
        //     SDL_Color color;
        // };
        union {
            struct {
                int m_x, m_y;
                unsigned int m_w, m_h;
            };
            SDL_Rect m_rect;
        };

        // int          xVel, yVel;
        // double       angle;
        // SDL_Point    anglePoint;

        // //Position on the gameMap
        // union {
        //     struct { unsigned int xGM, yGM; };
        //     SDL_Point posGM;
        // };

    public:
        BoardTile (ID id);
        ~BoardTile ();
};

