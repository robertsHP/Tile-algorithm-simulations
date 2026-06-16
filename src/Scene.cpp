#include "Scene.h"

#include <memory>
#include "Engine.h"

Scene::Scene () {
    Debug::log("INFO", "Starting scene.");
}

Scene::~Scene () {
    Debug::log("INFO", "Closing scene and clearing textures.");

    m_textures.clear();
}

std::shared_ptr<Texture> Scene::loadTexture (std::string title, std::string fileLoc) {
    static Engine &engine = Engine::getInstance();

    
    auto txtr = std::make_shared<Texture>(fileLoc.c_str(), engine.getWindowData().rendPtr);

    m_textures.insert(
        { title, txtr }
    );

    return txtr;
}
std::shared_ptr<Texture> Scene::getTexture (std::string title) {
    return m_textures[title];
}

