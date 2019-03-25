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
** @brief is_mouse_in_rect: verifie si la souris est dans le bouton.
**  @param  btn
** @param  x: pos en x de la souris.
** @param  y: pos en y de la souris.
** @param  type: le type du bouton.
** @return  true si la souris est dans le boutton, false dans le cas contraire.
*/
int     is_mouse_in_rect(t_btn *btn, int x, int y, int type)
{
	int i;

	i = btn->key[type] - 1;
	if (btn->key[type] != 0 && i >= 0 && i <= MAX_BTN)
	{
		return ((x >= btn->pos[i]->pos.x) && (y >= btn->pos[i]->pos.y)
		&& (x < btn->pos[i]->pos.x + (int)btn->pos[i]->pos.w)
		&& (y < btn->pos[i]->pos.y + (int)btn->pos[i]->pos.h));
	}
	return (0);
}

/*
** is_btn_clicked:
** @param  btn
** @param  event
** @return true si le bouton est cliqué, false dans le cas contraire.
*/
int      is_btn_clicked(t_btn *btn, SDL_Event event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
	{
		if (is_mouse_in_rect(btn, event.button.x, event.button.y, btn->type))
			return (1);
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
void set_click_event(SDL_Event event, t_btn *btn, SDL_Renderer *rend)
{
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if(event.button.button == SDL_BUTTON_LEFT)
		{
			if (btn->type == ARROW)
			{
				if (ui_render_arrow_btn(rend, btn, event.button.x, event.button.y) == 1)
					;
			}
			if (btn->type == CHECKBOX)
				ui_render_checkbox_btn(btn, event.button.x, event.button.y);
		}
	}
	if (btn->type == SLIDER)
	{
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			btn->state = IS_PUSHED;
		if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
			btn->state = NOT_PUSHED;
	}
	if (btn->key[SLIDER] != 0 && is_mouse_in_rect(btn, event.button.x, event.button.y, SLIDER))
	{
				if (event.type == SDL_MOUSEMOTION && btn->state == IS_PUSHED)
					ui_load_slider_texture(btn, rend, event.motion.x, event.motion.y);
				else
					ui_load_slider_texture(btn, rend, 0, 0);
	}
	else if (btn->key[SLIDER] != 0)
		ui_load_slider_texture(btn, rend, 0, 0);
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
