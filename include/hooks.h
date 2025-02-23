#ifndef HOOKS_H
# define HOOKS_H

# include <mlx.h>
# include "fdf.h"

int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		close_window(t_data *data);

#endif
