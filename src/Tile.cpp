#include "Tile.h"

#include "Engine.h"
#include "Enums.h"
#include <string>

Tile::Tile (ID id, SDL_Point pos, TileType tileType, Scene *scene)
: Object(
    {
        pos.x, 
        pos.y, 
        ((tileType == TileType::ISOMETRIC) ? ISO_TXTR_WIDTH : TOP_TXTR_WIDTH) * 2, 
        ((tileType == TileType::ISOMETRIC) ? ISO_TXTR_HEIGHT : TOP_TXTR_HEIGHT) * 2
    }
    // {255, 255, 255, 255}
) {
    m_tileType = tileType;
    m_associatedScene = scene;

    m_txtr = m_associatedScene->getTexture(
        (tileType == TileType::ISOMETRIC) ? 
            "tiles_iso" 
            : 
            "tiles"
    );

    m_id = id;
}
Tile::~Tile () {
    // Debug::log("INFO", "Destroying Tile.");
}

void Tile::input () {

}

void Tile::update (float deltaTime) {

}

void Tile::draw () {

    
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

