#pragma once

#include <memory>

#include "Scene.h"
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



class Tile {
    public:
        enum ID : unsigned {
            LIGHT = 0,
            DARK,
            POS_MOV,
            IMPOS_MOV,
            TEX_SEL
        };

        static const int TXTR_WIDTH = 30;
        static const int TXTR_HEIGHT = 16;

    private:
        Scene *m_associatedScene;

        Texture *m_txtr;
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
        void setID (ID id) { m_id = id; }   

    public:
        Tile (ID id, SDL_Point pos, Scene *scene);
        ~Tile ();

        void input ();
        void update (float deltaTime);
        void draw ();
};

