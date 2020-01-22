/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:37:42 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:37:43 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
