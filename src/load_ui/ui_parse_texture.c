#include "ui.h"
#include "ui_error.h"

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
		return (ui_ret_null_error("new_texture", "texture allocation failed", NULL));
	texture->id = id;
	texture->sdl_ptr = sdl_ptr;
	texture->next = NULL;
	return (texture);
}

SDL_Texture		*get_texture_ptr(t_texture *textures, const char *id)
{
	t_texture	*t;

	t = textures;
	while (t)
	{
		if (ft_strcmp(t->id, id) == 0)
			return (t->sdl_ptr);
		t = t->next;
	}
	return (NULL);
}

SDL_Texture		*parse_texture(SDL_Renderer *rend, t_texture **textures, const char *expected_name, char *line)
{
	char		*path;
	SDL_Texture	*texture;

	if (!check_line_name(line, expected_name) || !(path = parse_str(line)))
		return (ui_ret_null_error("parse_texture", "\"<?> : <path>\" expected", NULL));
	if ((texture = get_texture_ptr(*textures, path)))
		return (texture);
	if (!(texture = ui_load_image(rend, path)))
		return (ui_ret_null_error("parse_texture", "ui_load_image failed", NULL));
	add_texture(textures, new_texture(path, texture));
	return (texture);
}

void			ui_free_texture(t_texture **texture)
{
	t_texture	*t;

	t = *texture;
	if (t)
	{
		if (t->id)
			ft_strdel(&t->id);
		if (t->sdl_ptr)
			SDL_DestroyTexture(t->sdl_ptr);
		t->next = NULL;
		free(t);
	}
	*texture = NULL;
}

void			ui_free_textures(t_texture **textures)
{
	t_texture	*t;
	t_texture	*next;

	t = *textures;
	while (t)
	{
		next = t->next;
		ui_free_texture(&t);
		t = next;
	}
	*textures = NULL;
}