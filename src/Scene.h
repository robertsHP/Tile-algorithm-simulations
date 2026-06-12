#ifndef SCENE_H
#define SCENE_H

#include <map>

#include "Texture.h"

class Scene {
    private:
        std::map<std::string, std::unique_ptr<Texture>> m_textures;

    public:
        Scene ();
        ~Scene ();

        virtual void input () {}
        virtual void update (float deltaTime) {}
        virtual void draw () {}

        void loadTexture (std::string title, std::string fileLoc);
        std::unique_ptr<Texture>& getTexture (std::string title);
};

#endif // SCENE_H
