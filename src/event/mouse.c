#include "SDL.h"
#include "ui_btn.h"
#include "ui_draw.h"
#include "ui_event.h"

/*
** @brief  ui_is_mouse_pressed
** @note   recuperation de l'etat souris
** @param  mouse_flags: les boutons testes
** @param  *x: pointeur x pour recuperer la position x de la souris
** @param  *y: pointeur y pour recuperer la position y de la souris
** @retval
*/
int		ui_is_mouse_pressed(Uint32 mouse_flags, int *x, int *y)
{
	int		i;

	if (!(mouse_flags & UI_AT_LEAST_ONE))
	{
		if (SDL_GetMouseState(x , y) & mouse_flags)
			return (1);
	}
	else
	{
		i = 1;
		while (i < 6)
		{
			if (SDL_GetMouseState(x,y) & i++)
				return (1);
		}
	}
	return (0);
}

/*
** @brief set_click_event
** @note  recupere les actions associees aux boutons et applique les textures au rendu.
** @param SDL event
** @param t_btn: le bouton sur lequel on va cliquer.
** @param rend: le rendu avec les textures.
** @retVal NONE.
*/
void set_click_event(SDL_Event event, t_btn *btn, SDL_Renderer	*rend)
{
	rend = NULL;
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if(event.button.button == SDL_BUTTON_LEFT)
		{
			if (btn->type == ARROW)
			{
				if (ui_render_arrow_btn(rend, btn, event.button.x, event.button.y) == 1)
					;
			}
			/*if (btn->type == SLIDER)
			{
				ui_render_slider_btn(rend, btn, event.button.x, event.button.y);
			}*/
		}
	}
	/*if (event.type == SDL_MOUSEBUTTONUP)
	{
		if(event.button.button == SDL_BUTTON_LEFT)
		{
			if (btn->type == SLIDER)
			{
				ui_render_slider_btn(rend, btn, event.button.x, event.button.y);
			}
		}
	}*/
}

// ------------------ TODO DRAG & DROP --------------------

//le bouton de le souris est relache --- ex : drag and drop.
/*if( event.type == SDL_MOUSEBUTTONUP )
    {
        //si c'est le bouton gauche de la souris qui est relache
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Recuperation des coordonnees de la souris
            x = event.button.x;
            y = event.button.y;

            //Si la souris est dans le bouton
            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
            {
                //Mise à jour du sprite du bouton
                clip = &clips[ CLIP_MOUSEUP ];
            }
        }
}*/
