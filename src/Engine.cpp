#include "Engine.h"

#include "main.h"

void Engine::init () {
    Debug::log("INFO", "Starting engine and loading window.");

    if(!this->initSDL()) {
        return;
    }

    m_win.title = WIN_TITLE;
    m_win.width = WIN_WIDTH;
    m_win.height = WIN_HEIGHT;

    if(!this->loadWindow()) {
        Debug::log("ERROR", "Failed to initialize window data.");
        return;
    }
    if(!this->loadRenderer()) {
        Debug::log("ERROR", "Failed to load renderer.");
        return;
    }
    // if(!this->loadOpenGL(width, height)) {
    //     Debug::log("ERROR", "Failed to initialize the OpenGL context.");
    //     return;
    // }

}
bool Engine::initSDL () {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::string errMessage = SDL_GetError();
        Debug::log("ERROR", "SDL2 Could not initialize! SDL_Error: "+errMessage);
        return false;
    }

    if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        std::string errMessage = IMG_GetError();
        Debug::log("ERROR", "SDL_image Could not initialize! IMG_Error: "+errMessage);
        return false;
    }
    return true;
}
bool Engine::loadWindow () {
    m_win.winPtr = SDL_CreateWindow(
        m_win.title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        m_win.width,
        m_win.height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );
    return m_win.winPtr;
}

bool Engine::loadRenderer () {
    m_win.rendPtr = SDL_CreateRenderer(m_win.winPtr, -1, 0);

    return m_win.rendPtr;
}


// void Engine::refreshInput () {
//     m_input.update();
// }



void Engine::kill () {
    if(m_currentScene) 
        delete m_currentScene;

    Debug::log("INFO", "Closing window and killing engine.");

    if(m_win.rendPtr) SDL_DestroyRenderer(m_win.rendPtr);
    if(m_win.winPtr) SDL_DestroyWindow(m_win.winPtr);

    SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
    IMG_Quit();
    SDL_Quit();
}

void Engine::setCurrentScene (Scene *newScene) {
    if (m_currentScene)
        delete m_currentScene;

    m_currentScene = newScene;
}
void Engine::startLoop () {
    const int FRAME_DELAY = 1000 / 60;
    
    int deltaTime = 0;
    int lastFrame, frameCount = 0, lastTime = 0;

    // printf("isLooping = %d", m_isLooping);

    while(m_isLooping) {
        try {
            lastFrame = SDL_GetTicks();
            if(lastFrame >= (lastTime + 1000)) {
                lastTime = lastFrame;
                m_fps = frameCount;
                frameCount = 0;
            }

            SDL_RenderClear(m_win.rendPtr);

            m_input.update();

            m_currentScene->input();
            m_currentScene->update(deltaTime);
            m_currentScene->draw();

            SDL_RenderPresent(m_win.rendPtr);

            frameCount++;

            deltaTime = SDL_GetTicks() - lastFrame;
            if(FRAME_DELAY > deltaTime){
                SDL_Delay(FRAME_DELAY - deltaTime);
            }

        } catch(std::exception &e) {

            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), 0);
        }

    }
}


