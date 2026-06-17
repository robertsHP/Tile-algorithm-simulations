#include "Input.h"
#include "Engine.h"

#include <algorithm>


std::vector<SDL_Event> Input::keyEvents;
std::vector<SDL_Event> Input::mouseEvents;
uint8_t               *Input::keyBoardState;
uint32_t               Input::mouseState;

void Input::update () {
    
    if(!mouseEvents.empty())
        mouseEvents.clear();  ///!!!!maybe doesnt need to be checked
    if(!keyEvents.empty())
        keyEvents.clear();

    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch(event.type){
            case SDL_QUIT :
                Engine::getInstance().stopLoop();
                return;
            case SDL_MOUSEBUTTONDOWN :
            case SDL_MOUSEBUTTONUP :
                Input::mouseEvents.push_back(event);
                break;
            case SDL_KEYDOWN :
            case SDL_KEYUP :
                Input::keyEvents.push_back(event);
                break;
            default : break;
        }
        event = {};
    }
    Input::keyBoardState = (uint8_t*) SDL_GetKeyboardState(NULL);
//     mouseState = SDL_GetMouseState(&Cursor::rect.x, &Cursor::rect.y);
}
bool Input::ifCondApplyToKeyEventCont (uint32_t inputType, uint8_t scanCode, uint8_t repeatAmount) {
    return std::find_if(
        Input::keyEvents.begin(),
        Input::keyEvents.end(),
        [&inputType, &scanCode, &repeatAmount](const SDL_Event &event) {
            return event.type == inputType && event.key.repeat == repeatAmount && event.key.keysym.scancode == scanCode;
        }
    ) != std::end(Input::keyEvents);
}
bool Input::ifCondApplyToMouseEventCont (uint32_t inputType, uint8_t scanCode, uint8_t clickAmount) {
    return std::find_if(
        Input::mouseEvents.begin(),
        Input::mouseEvents.end(),
        [&inputType, &scanCode, &clickAmount](const SDL_Event &event) {
            return event.type == inputType && event.button.clicks == clickAmount && event.button.button == scanCode;
        }
    ) != std::end(Input::mouseEvents);
}
bool Input::keyPressed (uint8_t scanCode) {
    return ifCondApplyToKeyEventCont(SDL_KEYDOWN, scanCode, 0);
}
bool Input::keyReleased (uint8_t scanCode) {
    return ifCondApplyToKeyEventCont(SDL_KEYUP, scanCode, 0);
}
bool Input::keyHeldDown (uint8_t scanCode) {
    return keyBoardState[scanCode];
}
bool Input::mousePressed (uint8_t scanCode) {
    return ifCondApplyToMouseEventCont(SDL_MOUSEBUTTONDOWN, scanCode, 1);
}
bool Input::mouseReleased (uint8_t scanCode) {
    return ifCondApplyToMouseEventCont(SDL_MOUSEBUTTONUP, scanCode, 1);
}
bool Input::mouseHeldDown (uint8_t mask) {
    return (Input::mouseState & mask) != 0;
}
