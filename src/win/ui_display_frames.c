#include "ui_win.h"
#include "ui_frame.h"
#include "ui_draw.h"
#include "ui_texture.h"

void			ui_display_frames(t_win *win, t_frame *frames)
{
	t_frame	*f;

	f = frames;
	while (f)
	{
		if (f->type == UI_FRAME_SIMPLE)
			ui_display_simple_frame(win, (t_simple_frame*)f->data, &f->rect);
		ui_display_buttons(win, f->buttons);
		f = f->next;
	}
}

void			ui_display_simple_frame(t_win *win, t_simple_frame *simple_frame, const t_rect *rect)
{
	// SDL_Texture	*text_texture;
	// t_frect		text_ratio;

	// text_ratio = simple_frame->text_ratio;
	if (simple_frame->texture)
		SDL_RenderCopy(win->rend, simple_frame->texture,
						NULL, (SDL_Rect*)rect);
	else
	{
		ui_set_draw_color(win->rend, &(SDL_Color){200, 200, 200, 255});
		ui_draw_rect(win->rend, rect);
	}
	// if (simple_frame->text)
	// {
	// 	if (win->ui.button_font)
	// 	{
	// 		if ((text_texture = ui_new_text(win->rend,
	// 				win->ui.button_font, simple_frame->text,
	// 				&win->ui.button_text_color)))
	// 			ui_display_simple_draw_text(win, simple_frame, (t_rect){rect->w * text_ratio.x,
	// 																	rect->h * text_ratio.y,
	// 																	rect->w * text_ratio.w,
	// 																	rect->h * text_ratio.h});
	// 		else
	// 			ui_ret_error("ui_display_simple_frame", "ui_new_text failed", 0);
	// 	}
	// 	else
	// 		ui_ret_error("ui_display_simple_frame",
	// 						"(ui_win)->(TTF_Font*)button_font is not set", 0);
	// }
}