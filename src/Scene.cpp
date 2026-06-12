#include "Scene.h"

#include <memory>
#include "Engine.h"

Scene::Scene () {
    Debug::log("INFO", "Starting scene.");
}

Scene::~Scene () {
    Debug::log("INFO", "Closing scene.");

    m_textures.clear();
}

void Scene::loadTexture (std::string title, std::string fileLoc) {
    static Engine &engine = Engine::getInstance();

    m_textures.insert(
        {
            title, 
            std::make_unique<Texture>(fileLoc.c_str(), engine.getWindowData().rendPtr)
        }
    );
}
std::unique_ptr<Texture>& Scene::getTexture (std::string title) {
    return m_textures[title];
}

