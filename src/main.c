#include "ui.h"
#include <stdio.h>



int		main()
{
	t_win			*win;
	SDL_Event		event;
	int				loop;
	t_frame			*frame;
	SDL_Texture		*ftexture;
	SDL_Texture		*btexture;
	SDL_Texture		*htexture;
	SDL_Texture		*simple_btn_texture;
	t_btn			*btn;
	t_rect			tmp;

	//	initialisation de la SDL
	if(ui_init(SDL_INIT_VIDEO, IMG_INIT_JPG | IMG_INIT_PNG) < 0)
        return (1);

	//	ouverture fenetre et rendu
	if (!(win = ui_open_window("test", (t_dot){200, 200}, (t_len){2000, 1000}, UI_WIN_RESIZABLE)))
		return (1);
	//	creation des textures frames
	if (!(ftexture = ui_create_empty_texture(win->rend, (t_len){300, 300})))
		return (1);	
	if (!(btexture = ui_create_empty_texture(win->rend, (t_len){300, 300})))
		return (1);	
	if (!(htexture = ui_create_empty_texture(win->rend, (t_len){50, 50})))
		return (1);
	//	creation des texture btn
	if (!(simple_btn_texture = ui_create_empty_texture(win->rend, (t_len){50, 50})))
		return (1);
	
	//	ecriture sur les textures personnalisees
	ui_set_render_target(win->rend, ftexture);
	ui_fill_rect(win->rend, (t_rect){1, 1, 298, 298}, 0x444444FF);
	ui_draw_rect(win->rend, (t_rect){0, 0, 300, 300}, 1, 0x000000FF);
	ui_set_render_target(win->rend, btexture);
	ui_fill_rect(win->rend, (t_rect){1, 1, 298, 298}, 0xAAAAAAFF);
	ui_draw_rect(win->rend, (t_rect){0, 0, 300, 300}, 1, 0x000000FF);
	ui_set_render_target(win->rend, htexture);
	ui_fill_rect(win->rend, (t_rect){0, 0, 50, 50}, 0xFFF5F5AA);
	ui_set_render_target(win->rend, simple_btn_texture);
	ui_fill_rect(win->rend, (t_rect){0, 0, 50, 50}, 0xFFF5F5AA);
	ui_set_render_target(win->rend, NULL);
	//	creation de frames
	//		frame centre
	if (!(frame = ui_new_frame((t_rect){win->size.x / 4, 0, win->size.x - 2 * (win->size.x / 4), win->size.y}, btexture)))
		return (1);
	ui_add_frame_to_win(win, frame);
	//		frame gauche
	if (!(frame = ui_new_frame((t_rect){0, 0, win->size.x / 4, win->size.y}, ftexture)))
		return (1);
	ui_add_frame_to_win(win, frame);	
	//		frame droite
	if (!(frame = ui_new_frame((t_rect){win->size.x - win->size.x / 4, 0, win->size.x / 4, win->size.y}, ftexture)))
		return (1);
	ui_add_frame_to_win(win, frame);
	//		frame_haut
	if (!(frame = ui_new_frame((t_rect){0, 0, win->size.x, win->size.y / 50}, htexture)))
		return (1);
	ui_add_frame_to_win(win, frame);
	//			creation btn
	if (!(btn = ui_create_btn(SIMPLE, 0, "test", 0x000000FF)))
		return (1);
	tmp = frame->rect;
	ui_add_btn_pos(btn, (t_rect){0, 0, tmp.w / 20, tmp.h},
						simple_btn_texture, SIMPLE);
	ui_add_btn_pos(btn, (t_rect){0, 0, tmp.w / 20, tmp.h},
						ui_create_text("File","/ressource/police/arial.ttf", win->rend),
						TEXT);
	ui_add_button_to_frame(frame, btn);
	if (!(btn = ui_create_btn(SIMPLE, 0, "test", 0x000000FF)))
		return (1);
	ui_add_btn_pos(btn, (t_rect){tmp.w / 20, 0, tmp.w / 20, tmp.h},
						simple_btn_texture, SIMPLE);
	ui_add_btn_pos(btn, (t_rect){tmp.w / 20, 0, tmp.w / 20, tmp.h},
						ui_create_text("Edit","/ressource/police/arial.ttf", win->rend),
						TEXT);
	ui_add_button_to_frame(frame, btn);
	if (!(btn = ui_create_btn(SIMPLE, 0, "test", 0xFFFFFFFF)))
		return (1);
	ui_add_btn_pos(btn, (t_rect){tmp.w / 20 * 2, 0, tmp.w / 20, tmp.h},
						simple_btn_texture, SIMPLE);
	ui_add_btn_pos(btn, (t_rect){tmp.w / 20 * 2, 0, tmp.w / 20, tmp.h},
						ui_create_text("Window","/ressource/police/arial.ttf", win->rend),
						TEXT);
	ui_add_button_to_frame(frame, btn);
	//		window_loop
	loop = 1;
	while (loop)
	{
		ui_update_event(UI_KEY_UPDATE);
		ui_set_draw_color(win->rend, 0x666666FF);
		ui_clear_rend(win->rend);
		SDL_WaitEvent(&event);
		if (ui_is_key_pressed(SDL_SCANCODE_Q, 0))
				loop = 0;
		ui_draw_window(win);
		//ui_draw_triangle(win->rend, (t_triangle){(t_dot){300, 300}, (t_dot){300, 200}, (t_dot){400, 250}}, 0xFFFFFFAA);
		ui_draw_line(win->rend, (t_line){(t_dot){100, 200}, (t_dot){800, 400}}, 50, 0xFFFFFFAA);
		ui_draw_line(win->rend, (t_line){(t_dot){100, 800}, (t_dot){800, 600}}, 50, 0x00FFFFAA);
		ui_draw_line(win->rend, (t_line){(t_dot){100, 900}, (t_dot){800, 900}}, 50, 0x00FFFFAA);
		// ui_draw_line(win->rend, (t_line){(t_dot){600, 300}, (t_dot){800, 280}}, 50, 0xFFFFFFAA);
		// ui_draw_line(win->rend, (t_line){(t_dot){810, 300}, (t_dot){1100, 310}}, 50, 0xFFFFFFAA);
		ui_draw_rend(win->rend);
	}
	if (win->rend)
		SDL_DestroyRenderer(win->rend);
	SDL_DestroyWindow(win->ptr);
	SDL_Quit();
	return (0);
}
