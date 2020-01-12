#include "ui_win.h"
#include "ui.h"

void	ui_free_ui(t_ui *ui)
{
	if (ui->frames)
		ui_free_frames(&ui->frames);
	ui->on_mouse_button = NULL;
	ui->clicked_button = NULL;
	if (ui->button_font)
		TTF_CloseFont(ui->button_font);
	if (ui->textures)
		ui_free_textures(&ui->textures);
}