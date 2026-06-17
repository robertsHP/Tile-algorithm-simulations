#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include "SDL.h"

// #include "Singleton.h"

class Input {
    private:
        static std::vector<SDL_Event> keyEvents;
        static std::vector<SDL_Event> mouseEvents;
        static uint8_t *keyBoardState;
        static uint32_t mouseState;
    public:
        Input() = delete;
        ~Input () = delete;

        static void update ();
        static bool ifCondApplyToKeyEventCont (uint32_t inputType, uint8_t scanCode, uint8_t repeatAmount);
        static bool ifCondApplyToMouseEventCont (uint32_t inputType, uint8_t scanCode, uint8_t clickAmount);
        static bool keyPressed (uint8_t scanCode);
        static bool keyReleased (uint8_t scanCode);
        static bool keyHeldDown (uint8_t scanCode);
        static bool mousePressed (uint8_t scanCode);
        static bool mouseReleased (uint8_t scanCode);
        static bool mouseHeldDown (uint8_t mask);
};

#endif // INPUT_H
