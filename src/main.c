#include "ui.h"
#include "ui_error.h"

void	incre_value(void *value)
{
	int	*int_value;

	int_value = value;
	*int_value += 1;
}

void	assign_value(void *dst, char *value)
{
	*((int*)dst) = ft_atoi(value);
}

void 	assign_char_value(void *dst, char *value)
{
	*((char**)dst) = ft_strdup(value);
}

int		main()
{
	t_win		*win;
	int			loop;

	if (ui_init(SDL_INIT_VIDEO) < 0)
		return (1);


	/////////////////////////////////////////////////////////
	//////////////////////// WINDOW. ////////////////////////
	/////////////////////////////////////////////////////////

	if (!(win = ui_new_win("libui",
							(t_rect){SDL_WINDOWPOS_CENTERED,
							SDL_WINDOWPOS_CENTERED,
							900,
							900},
							SDL_WINDOW_RESIZABLE,
							SDL_RENDERER_ACCELERATED)))
		return (1);


	SDL_Texture	*texture;
	
	if (!(win->ui.button_font = ui_load_font("font/Raleway-Regular.ttf", 100)))
		return (1);
	if (!(texture = ui_new_text(win->rend, win->ui.button_font, "button", &(SDL_Color){255, 255, 255, 255})))
		return (1);

	/////////////////////////////////////////////////////////
	///---------------------------------------------------///
	/////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////
	/////////////////////// UI_LOAD /////////////////////////
	/////////////////////////////////////////////////////////


	/////////////////////////////////////////////////////////
	///---------------------------------------------------///
	/////////////////////////////////////////////////////////

	// /////////////////////////////////////////////////////////
	// ////////////////////// ADD_FRAMES ///////////////////////
	// /////////////////////////////////////////////////////////

	// SDL_Texture		*frame_texture;

	// frame_texture = ui_load_image(win->rend, "textures/ui_frame.png");

	// ui_add_frame(&win->ui.frames, 
	// 				ui_new_frame(UI_FRAME_SIMPLE, 
	// 								UI_RESIZE_ALL_LINEAR, 
	// 								(t_frect){0.05, 0.05, 0.7, 0.5},
	// 								ui_new_simple_frame("frame",
	// 													(t_frect){0.1, 0.1, 0.09, 0.03},
	// 													frame_texture,
	// 													NULL)));

	// /////////////////////////////////////////////////////////
	// ///---------------------------------------------------///
	// /////////////////////////////////////////////////////////

	// /////////////////////////////////////////////////////////
	// ////////////////////// ADD_BUTTONS //////////////////////
	// /////////////////////////////////////////////////////////

	// int					value = 0;
	// char				*text_entry_value = NULL;
	// t_simple_set		simple_set;
	// t_text_entry_set	text_entry_set;

	// simple_set.normal = ui_load_image(win->rend, "textures/ui_normal_button.png");
	// simple_set.clicked = ui_load_image(win->rend, "textures/ui_clicked_button.png");
	// simple_set.on_mouse = ui_load_image(win->rend, "textures/ui_on_mouse_button.png");
	// ui_add_button(&win->ui.frames->buttons,
	// 			  ui_new_button(UI_BUTTON_SIMPLE, UI_RESIZE_ALL_LINEAR,
	// 			  (t_frect){0.1, 0.1, 0.09, 0.03},
	// 			  ui_new_simple_button(UI_MOUSE_LEFT,
	// 			  					   &incre_value,
	// 								   &value,
	// 								   simple_set)));
	// ((t_simple_button*)win->ui.frames->buttons->data)->text = "button";

	// ui_add_button(&win->ui.frames->buttons,
	// 			  ui_new_button(UI_BUTTON_SIMPLE, UI_RESIZE_ALL_LINEAR,
	// 			  (t_frect){0.1, 0.3, 0.09, 0.03},
	// 			  ui_new_simple_button(UI_MOUSE_LEFT,
	// 			  					   &incre_value,
	// 								   &value,
	// 								   simple_set)));
	// ((t_simple_button*)win->ui.frames->buttons->data)->text = "button";

	// text_entry_set.name_side_texture = NULL;
	// if (!(text_entry_set.normal_box_texture = ui_load_image(win->rend, "textures/ui_text_entry_button_normal.png")) ||
	// 	!(text_entry_set.writting_box_texture = ui_load_image(win->rend, "textures/ui_text_entry_button_writting.png")) ||
	// 	!(text_entry_set.name_side_texture = ui_load_image(win->rend, "textures/ui_text_entry_button_normal.png")))
	// 	return (ui_ret_error("main", SDL_GetError(), -1));
	// text_entry_set.current_box_texture = NULL;
	// ui_add_button(&win->ui.frames->buttons,
	// 			  ui_new_button(UI_BUTTON_TEXT_ENTRY,
	// 			  UI_RESIZE_ALL_LINEAR,
	// 			  (t_frect){0.4, 0.1, 0.09, 0.03},
	// 			  ui_new_text_entry_button("nom", &assign_char_value, &text_entry_value, 15)));
	// ((t_text_entry_button*)win->ui.frames->buttons->data)->textures = text_entry_set;
	// // ((ui_text_entry_button*)win->ui.buttons->data)->text_type = UI_TEXT_TYPE_DIGITAL;
	// ui_update_buttons_rect(win, SDL_TRUE);

	/////////////////////////////////////////////////////////
	///---------------------------------------------------///
	/////////////////////////////////////////////////////////
	

	/////////////////////////////////////////////////////////
	///////////////////////// LOOP. /////////////////////////
	/////////////////////////////////////////////////////////

	// while (f)
	// {
	// 	printf("f = %p\n", f);
	// 	b = f->buttons;
	// 	while (b)
	// 	{
	// 		printf("b = %p\ntext = %s\n", b, b->id);
	// 		b = b->next;
	// 	}
	// 	f = f->next;
	// }
	// printf("f->ratio = %f, %f, %f, %f\n", f->ratio.x, f->ratio.y, f->ratio.w, f->ratio.h);
	if (ui_load("test_ui/ui.txt", win))
	{
		loop = 1;
		while (loop)
		{
			ui_set_draw_color(win->rend, &(SDL_Color){50, 50, 50, 255});
			ui_clear_win(win);
			ui_display_frames(win, win->ui.frames);
			// SDL_RenderCopy(win->rend, texture, NULL, NULL);
			// ui_draw_text(win->rend, font, &(ui_text){"voilatrucmuch on s'ammuse\ngrosse ambiance putain\nCordialement\n",
			// 										20,
			// 										&(SDL_Color){200, 200, 255, 255},
			// 										(ui_dot){200, 200}, TEXT_ALIGN_LEFT});
			ui_set_draw_color(win->rend, &(SDL_Color){255, 0, 0, 255});
			// ui_draw_rect(win->rend, &(t_rect){400, 200, 200, 25});
			// ui_draw_text_in_rect(win->rend, &(t_text){"1111111111111111122222222222",
			// 										20,
			// 										win->ui.button_font,
			// 										(SDL_Color){200, 200, 200, 255},
			// 										(t_dot){200, 200},
			// 										TEXT_ALIGN_LEFT | TEXT_ALIGN_V_MIDDLE},
			// 										(t_rect){400, 200, 200, 25}, UI_DRAW_TEXT_HIDE_RIGHT);
			ui_draw_rend(win);
			ui_wait_event(&win->event);
			ui_update_ui(win);
			// printf("text_entry_value = %s\n", text_entry_value);
			if (win->event.type == SDL_QUIT)
				loop = 0;
		}
	}
	ui_free_win(&win);
	ui_quit();
	win = NULL;
	/////////////////////////////////////////////////////////
	///---------------------------------------------------///
	/////////////////////////////////////////////////////////
	return (0);
}


 
    // button
    // {
    //     id : "button2"
    //     type : UI_BUTTON_SIMPLE
    //     resize_type : UI_RESIZE_ALL_LINEAR
    //     ratio : 0.4 0.1 0.09 0.03
    //     data
    //     {
    //         text : "puet"
    //         texture_normal : "textures/ui_normal_button.png"
    //         texture_clicked : "textures/ui_clicked_button.png"
    //         texture_on_mouse : "textures/ui_on_mouse_button.png"
    //         clicked_condition : UI_MOUSE_LEFT
    //     }
    // }
    // button
    // {
    //     id : "button3"
    //     type : UI_BUTTON_TEXT_ENTRY
    //     resize_type : UI_RESIZE_ALL_LINEAR
    //     ratio : 0.7 0.3 0.15 0.05
    //     data
    //     {
    //         name : "puet"
    //         text : ""
    //         max_text_size : 4
    //         min_int : 0
    //         max_int : 9000
    //         name_side_texture : "textures/ui_text_entry_button_normal.png"
    //         normal_box_texture : "textures/ui_text_entry_button_normal.png"
    //         writting_box_texture : "textures/ui_text_entry_button_writting.png"
    //         text_side : UI_TEXT_SIDE_LEFT
    //         text_type : UI_TEXT_TYPE_DIGITAL
    //     }
    // }