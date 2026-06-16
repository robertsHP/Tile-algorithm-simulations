#ifndef TEXTURE_H
#define TEXTURE_H

#include <memory>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"

#include "Debug.h"

// #include "ShaderProgram.h"

class Texture {
    private:
        std::string  m_fileLoc;
        SDL_Texture *m_textr;
        SDL_Surface *m_surface;

        // size_t m_shSize;
        std::vector<SDL_Rect> m_tmplts;

        SDL_Renderer *m_rendPtr;
    public:
        // Texture () = delete;
        Texture (std::string fileLoc, SDL_Renderer *rend);
        ~Texture ();

        void reload (std::string fileLoc, SDL_Renderer *rend);
        void generateSheetTemplates (SDL_Point templSize);
        void removeColor(SDL_Color color);

        void draw (
            unsigned templID,
            SDL_Rect *drawShape,
            double angle,
            SDL_Point *anglePoint,
            SDL_RendererFlip flip = SDL_FLIP_NONE
        );
        void draw (
            SDL_Rect *drawShape,
            double angle,
            SDL_Point *anglePoint,
            SDL_RendererFlip flip = SDL_FLIP_NONE
        );

        bool loaded () { return m_surface != nullptr; }
};

// class TextureSheet : public Texture {
//     private:
//         size_t m_shSize;
//         std::vector<SDL_Rect> m_tmplts;

//     public:
//         TextureSheet (std::string fileLoc, SDL_Point templSize, SDL_Renderer *rend);

//         void draw (
//             SDL_Rect src_rect,
//             SDL_Rect dst_rect,
//             double angle,
//             SDL_Point anglePoint
//         );
// };

#endif // TEXTURE_H

