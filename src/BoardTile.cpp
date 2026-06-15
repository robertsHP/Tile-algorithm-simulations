#include "BoardTile.h"

#include "Engine.h"

BoardTile::BoardTile (ID id) {
    m_txtr = Engine::getInstance().getCurrentScene()->getTexture("board");

    m_id = id;
    m_rect = (SDL_Rect) {0, 0, 30, 16};
}
BoardTile::~BoardTile () {

}


void draw () {
    // m_txtr->draw();
    

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

