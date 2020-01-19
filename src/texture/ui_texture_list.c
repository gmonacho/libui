#include "ui_win.h"
#include "ui_error.h"
#include "libft.h"

void			add_texture(t_texture **textures, t_texture *new_texture)
{
	if (new_texture)
	{
		new_texture->next = *textures;
		*textures = new_texture;
	}
}

t_texture		*new_texture(char *id, SDL_Texture *sdl_ptr)
{
	t_texture	*texture;

	if (!(texture = (t_texture*)ft_memalloc(sizeof(t_texture))))
	{
		return (ui_ret_null_error("new_texture",
			"texture allocation failed", NULL));
	}
	texture->id = ft_strdup(id);
	texture->sdl_ptr = sdl_ptr;
	texture->next = NULL;
	return (texture);
}
