#include "MainScene.h"

#include "BoardTile.h"
#include "SDL_rect.h"
#include "Texture.h"

#include "main.h"

MainScene::MainScene() {
    std::shared_ptr<Texture> txtr;
    
    txtr = Scene::loadTexture("board", PROJECT_ROOT + "assets/MOUSE.png");


    // txtr = Scene::loadTexture("board", "../assets/gfx/board.png");

    if (txtr->loaded()) {
        printf("LOADED");

        txtr->generateSheetTemplates({ 30, 16 });
        txtr->removeColor({ 255, 0, 255, 255 });

        m_bTile = std::make_unique<BoardTile>(
            BoardTile::ID::DARK, this
        );
    }
}
MainScene::~MainScene() {
    
}

void MainScene::input () {
    
}
void MainScene::update (float deltaTime) {
    // this->mesh->update(deltaTime);



}
void MainScene::draw () {
    // this->mesh->draw(this->plainShader, this->texture);

    // auto rect = (SDL_Rect){100, 5, 100, 100};
    // Scene::getTexture("mouse")->draw(rect);
    
    if(m_bTile)
        m_bTile->draw();
}

