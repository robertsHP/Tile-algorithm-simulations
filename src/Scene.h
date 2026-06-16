#ifndef SCENE_H
#define SCENE_H

#include <map>

#include "Texture.h"

class Scene {
    private:
        std::map<std::string, Texture*> m_textures;

    public:
        Scene ();
        ~Scene ();

        virtual void input () {}
        virtual void update (float deltaTime) {}
        virtual void draw () {}

        Texture* loadTexture (std::string title, std::string fileLoc);
        Texture* getTexture (std::string title);
};

#endif // SCENE_H
