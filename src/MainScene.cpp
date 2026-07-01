#include "MainScene.h"

#include <memory>
#include "SDL_rect.h"

// #include "Tile.h"
#include "Input.h"
#include "CellularAutomata.h"
#include "SDL_scancode.h"
#include "StateButton.h"
#include "Texture.h"
#include "Enums.h"

#include "main.h"

MainScene::MainScene () {
    Texture *txtr;
    
    txtr = Scene::loadTexture("tiles", PROJECT_ROOT + "assets/tiles.png");

    if (txtr->loaded()) {
        // txtr->removeColor({ 255, 0, 255, 255 });
        txtr->generateSheetTemplates(
            { Tile::TOP_TXTR_WIDTH, Tile::TOP_TXTR_HEIGHT }
        );
    }

    txtr = Scene::loadTexture("tiles_iso", PROJECT_ROOT + "assets/tiles_iso.png");

    if (txtr->loaded()) {
        txtr->removeColor({ 255, 0, 255, 255 });
        txtr->generateSheetTemplates(
            { Tile::ISO_TXTR_WIDTH, Tile::ISO_TXTR_HEIGHT }
        );
    }

    m_tileMap = new TileMap (
        (SDL_Rect) { 482, 100, 17, 17}, 
        TileType::TOP,
        this
    );

    txtr = Scene::loadTexture("state_btns", PROJECT_ROOT + "assets/state_btns.png");
    if (txtr->loaded()) {
        txtr->generateSheetTemplates({ StateButton::TXTR_WIDTH, StateButton::TXTR_HEIGHT });

        loadStateButtons();
        m_currentState = SimState::STOP;
    }

    m_celAutomata = new CellularAutomata(m_tileMap);
}

MainScene::~MainScene () {
    Debug::log("INFO", "Closing MainScene.");

    if (m_tileMap) delete m_tileMap;
    if (m_celAutomata) delete m_celAutomata;

    for (int i = 0; i < SimState::COUNT; ++i) {
        if(m_stateButtons[i])
            delete m_stateButtons[i];
    }
}

void MainScene::loadStateButtons () {
    for (int i = 0; i < SimState::COUNT; ++i) {
        SimState id = (SimState) i;

        m_stateButtons[i] = new StateButton(
            id,
            (SDL_Point) { 
                i * StateButton::TXTR_WIDTH * 2, 
                0 
            },
            this
        );
    }

}

void MainScene::input () {

    for (int i = 0; i < SimState::COUNT; ++i) {
        if(m_stateButtons[i])
            m_stateButtons[i]->input();
    }
}
void MainScene::update (float deltaTime) {
    // this->mesh->update(deltaTime);


    if(m_tileMap) {
        if (m_celAutomata) {

            switch (m_currentState) {
                case SimState::START:
                    m_celAutomata->updateTiles();
                    break;
                case SimState::STOP:
                    
                    break;
                case SimState::RESET:
                    m_celAutomata->reset();
                    m_currentState = SimState::STOP;

                    m_celAutomata->updateTiles();
                    break;
            }
        }
    }
}
void MainScene::draw () {
    // this->mesh->draw(this->plainShader, this->texture);

    // auto rect = (SDL_Rect){100, 5, 100, 100};
    // Scene::getTexture("mouse")->draw(rect);
    
    for (int i = 0; i < SimState::COUNT; ++i) {
        if(m_stateButtons[i])
            m_stateButtons[i]->draw();
    }

    m_tileMap->draw();


    // if(m_tile)
    //     m_tile->draw();
}

