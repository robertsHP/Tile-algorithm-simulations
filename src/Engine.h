#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

#include "SDL_render.h"
#include "Singleton.h"

#include "Debug.h"
#include "Scene.h"
#include "Input.h"

class Engine : public Singleton<Engine> {
private:
    bool m_isLooping = true;
    int  m_fps = 0;

    struct Window {
        std::string title;

        union {
            struct {
                int width;
                int height;
            };
            SDL_Point size;
        };

        SDL_Window   *winPtr;
        SDL_Renderer *rendPtr;
    } m_win;

    Input m_input;
    std::unique_ptr<Scene> m_currentScene;

public:
    Window& getWindowData () { return m_win; }

public:
    void init ();
private:
    bool initSDL ();
    bool loadWindow ();
    bool loadRenderer ();

    // void refreshInput ();

public:
    void kill ();
    void setCurrentScene (std::unique_ptr<Scene> newScene = nullptr);
    void startLoop ();
    void stopLoop () { m_isLooping = false; }

};

#endif // ENGINE_H


