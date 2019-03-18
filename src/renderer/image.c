#include "SDL.h"
#include "SDL_image.h"
#include "ui_error.h"
#include "ui_image.h"

SDL_Texture *ui_load_img(const char *path, Uint32 img_format, SDL_Renderer *rend)
{
    SDL_Surface     *surface;
    SDL_Texture     *texture;
    SDL_RWops       *rwop;
    
    surface = NULL;
    rwop = SDL_RWFromFile(path, "rb");
    if (img_format & UI_PNG)
        surface = IMG_LoadPNG_RW(rwop);
    else if (img_format & UI_JPG)
        surface = IMG_LoadJPG_RW(rwop);
    else if (img_format & UI_GIF)
        surface = IMG_LoadGIF_RW(rwop);
    else
        return (ui_null_error("bad img_format in ui_load_img"));
    texture = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    return (texture);
}