#pragma once

#include <memory>

#include "CellularAutomata.h"
#include "Debug.h"

// #include "Engine.h"
// #include "Input.h"

// // #include "ShaderProgram.h"
// #include "Texture.h"
// // #include "Mesh.h"
// // #include "Vertex.h"



// #include "Tile.h"
#include "TileMap.h"

class MainScene : public Scene {
    private :
        // std::shared_ptr<Engine::ShaderProgram> plainShader;
        // std::shared_ptr<Engine::Mesh> mesh;

        // std::unique_ptr<Tile> m_tile;

        TileMap *m_tileMap;
        CellularAutomata *m_celAutomata;

    public:
        MainScene();
        ~MainScene() override;

        void input () override;
        void update (float deltaTime) override;
        void draw () override;
};

