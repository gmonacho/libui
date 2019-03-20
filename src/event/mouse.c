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

/*int is_in_rect(t_rect r, int x, int y)
{
  return ((x >= r.x) && (y >= r.y) &&
         (x < r.x + r.w) && (y < r.y + r.h));
}*/

/*
** @brief is_btn_clicked
** @note  recupere les coordonnes de la souris et verifie que l'utilisateur clique sur le boutton.
** @param SDL event
** @param Les boutons.
** @retVal 1 ou 0.
*/
void is_btn_clicked(SDL_Event event, t_btn *btn, SDL_Renderer	*rend)
{
	int x;
	int y;
	int i;
	t_frame_dep dep;

	i = 0;
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if(event.button.button == SDL_BUTTON_LEFT)
		{
			x = (int)event.button.x;
			y = (int)event.button.y;

			while (i < btn->count_pos)
			{
				// si on est bien dans un des boutons.
				if ((x >= btn->pos[i]->pos.x) && (y >= btn->pos[i]->pos.y)
				&& (x < btn->pos[i]->pos.x + (int)btn->pos[i]->pos.w)
				&& (y < btn->pos[i]->pos.y + (int)btn->pos[i]->pos.h))
				{
					if (btn->type == ARROW && i == 1)
					{
						btn->value++;
						ui_set_draw_color(rend, 0x7f827a, 255);
						ui_load_arrow_texture(btn, rend);
						dep.r = btn->pos[0]->pos;
		      	dep.f_r = (t_rect){0, 0, 600, 600};
						//texture = ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", rend);
						//SDL_SetRenderTarget(rend, texture);
		      	//ui_draw_texture(rend, texture, UI_ABSOLUTE, dep);
						ui_draw_rend(rend);
					}
					if (btn->type == ARROW && i == 2 && btn->value > 0)
					{
						btn->value--;
						dep.r = btn->pos[0]->pos;
						dep.f_r = (t_rect){0, 0, 600, 600};
						ui_set_draw_color(rend, 0x7f827a, 255);
						ui_load_arrow_texture(btn, rend);
						//ui_draw_texture(rend, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", rend), UI_ABSOLUTE, dep);
						ui_draw_rend(rend);
					}
				}
				i++;
			}
		}
	}
}


// le bouton de le souris est relache --- ex : drag and drop.
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
