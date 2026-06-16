#pragma once

#include <memory>

#include "Debug.h"

// #include "Engine.h"
// #include "Input.h"

// // #include "ShaderProgram.h"
// #include "Texture.h"
// // #include "Mesh.h"
// // #include "Vertex.h"



#include "BoardTile.h"

class MainScene : public Scene {
    private :
        // std::shared_ptr<Engine::ShaderProgram> plainShader;
        // std::shared_ptr<Engine::Mesh> mesh;

        std::unique_ptr<BoardTile> m_bTile;

    public:
        MainScene();
        ~MainScene();

        void input () override;
        void update (float deltaTime) override;
        void draw () override;
};

