#include "MainScene.h"

#include <memory>
#include "SDL_rect.h"

// #include "Tile.h"
#include "CellularAutomata.h"
#include "Texture.h"

#include "main.h"

MainScene::MainScene () {
    // std::shared_ptr<Texture> txtr;
    
    Texture *txtr = Scene::loadTexture("board", PROJECT_ROOT + "assets/board.png");

    if (txtr->loaded()) {
        txtr->removeColor({ 255, 0, 255, 255 });
        txtr->generateSheetTemplates({ Tile::TXTR_WIDTH, Tile::TXTR_HEIGHT });

        // m_tile = std::make_unique<Tile>(
        //     Tile::ID::LIGHT, this
        // );

        m_tileMap = new TileMap (
            (SDL_Point) { 600, 100 }, (SDL_Point) {10, 10}, this
        );
    }

    m_celAutomata = new CellularAutomata(m_tileMap);
}
MainScene::~MainScene () {
    Debug::log("INFO", "Closing MainScene.");

    if (m_tileMap) delete m_tileMap;
    if (m_celAutomata) delete m_celAutomata;
}

void MainScene::input () {
    
}
void MainScene::update (float deltaTime) {
    // this->mesh->update(deltaTime);


    if(m_tileMap) {
        if (m_celAutomata) {
            m_celAutomata->updateTiles();
        }
    }
}
void MainScene::draw () {
    // this->mesh->draw(this->plainShader, this->texture);

    // auto rect = (SDL_Rect){100, 5, 100, 100};
    // Scene::getTexture("mouse")->draw(rect);
    


    m_tileMap->draw();


    // if(m_tile)
    //     m_tile->draw();
}

