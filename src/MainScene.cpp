#include "MainScene.h"

#include "SDL_rect.h"
#include "Texture.h"

#include <memory>

MainScene::MainScene() {
    
    Scene::loadTexture("board", "../assets/gfx/board.png");

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

    auto rect = (SDL_Rect){100, 5, 100, 100};

    Scene::getTexture("mouse")->draw(rect);
    
}

