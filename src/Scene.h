#ifndef SCENE_H
#define SCENE_H

#include <map>

#include "Texture.h"

class Scene {
    private:
        std::map<std::string, std::shared_ptr<Texture>> m_textures;

    public:
        Scene ();
        ~Scene ();

        virtual void input () {}
        virtual void update (float deltaTime) {}
        virtual void draw () {}

        void loadTexture (std::string title, std::string fileLoc);
        std::shared_ptr<Texture> getTexture (std::string title);
};

#endif // SCENE_H
