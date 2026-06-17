#pragma once

#include "Scene.h"
#include "Texture.h"

class StateButton {
    public:
        enum ID : unsigned {
            START = 0,
            END,
            RESET,
            
            COUNT
        };

        static const int TXTR_WIDTH = 24;
        static const int TXTR_HEIGHT = 24;

    private:
        Scene *m_associatedScene;
        Texture *m_txtr;
        ID m_id;

        union {
            struct {
                int m_x, m_y;
                unsigned int m_w, m_h;
            };
            SDL_Rect m_rect;
        };
    public:
        void setID (ID id) { m_id = id; }

    public:
        StateButton (ID id, SDL_Point pos, Scene *scene);
        ~StateButton ();

        void input ();
        void update (float deltaTime);
        void draw ();

        bool ifHoveredOver (bool advanced) {
            bool hoverX, hoverY;
            int mouseX, mouseY;

            SDL_GetMouseState(&mouseX, &mouseY);

            hoverX = m_x < mouseX && (m_x + m_w) > mouseX;
            hoverY = m_y < mouseY && (m_y + m_h) > mouseY;

            // if(hoverX && hoverY) {

            // }

            return hoverX && hoverY;
        }

    private:
        void startAction ();
        void endAction ();
        void resetAction ();

};

