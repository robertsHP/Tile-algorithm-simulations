#include "Scene.h"

#include <memory>
#include "Engine.h"

Scene::Scene () {
    Debug::log("INFO", "Starting scene.");
}

Scene::~Scene () {
    Debug::log("INFO", "Closing scene and clearing textures.");

    for (auto pair : m_textures) {
        Texture *txtr = pair.second;
        
        if(txtr) delete txtr;
    }

    m_textures.clear();
}

Texture* Scene::loadTexture (std::string title, std::string fileLoc) {
    static Engine &engine = Engine::getInstance();

    Texture* txtr = new Texture (fileLoc.c_str(), engine.getWindowData().rendPtr);

    m_textures.insert({ title, txtr });

    return txtr;
}
Texture* Scene::getTexture (std::string title) {
    return m_textures[title];
}

