#include <iostream>
#include <fstream>
#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include <memory>

#include "Engine.h"
#include "MainScene.h"

int main()
{
    Engine &engine = Engine::getInstance();

    engine.init();
    engine.setCurrentScene(std::make_unique<MainScene>());
    engine.startLoop();

    engine.kill();
}

