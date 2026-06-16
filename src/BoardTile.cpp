#include "BoardTile.h"

#include "Engine.h"

BoardTile::BoardTile (ID id, Scene *scene) {
    m_associatedScene = scene;

    m_txtr = m_associatedScene->getTexture("board");

    m_id = id;
    m_rect = (SDL_Rect) {0, 0, 30, 16};
}
BoardTile::~BoardTile () {
    Debug::log("INFO", "Destroying BoardTile.");
}

void BoardTile::input () {

}

void BoardTile::update (float deltaTime) {

}

void BoardTile::draw () {

    
    m_txtr->draw(m_id, &m_rect, 0, NULL, SDL_FLIP_NONE);
    

    // &obj->sheet->tmplts[obj->txtrIndex]




    // SDL_RenderCopyEx(
    //     g_win.rend,
    //     obj->sheet->textr,
    //     &obj->sheet->tmplts[obj->txtrIndex],
    //     &obj->rect,
    //     obj->angle,
    //     &obj->anglePoint,
    //     SDL_FLIP_NONE
    // );
}

