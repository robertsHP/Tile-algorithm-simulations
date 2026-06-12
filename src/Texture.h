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

    public:
        // Texture () = delete;
        Texture (std::string fileLoc, SDL_Renderer *rend);
        ~Texture ();

        void removeColor(SDL_Color color);
        void draw (SDL_Rect &renderRect);

    // public :
    //     // GLuint id;
    //     int width, height;
    //     std::string dir;

    //     // GLenum type;
    // public :
    //     Texture (std::string dir, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
    //     ~Texture ();

    //     void texUnit (std::shared_ptr<ShaderProgram> shader, const char* uniform, GLuint unit);
    //     void bind ();
    //     void unbind ();
};

// class TextureSheet : public Texture {
//     private:
//         size_t m_shSize;
//         std::vector<SDL_Rect> m_tmplts;

//     public:
//         TextureSheet (const char *fileLoc, SDL_Point templSize, SDL_Renderer *rend);

//         // void draw () override;
// };

#endif // TEXTURE_H
