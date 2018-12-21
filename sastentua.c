/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/08 20:53:39 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 20:33:56 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(int c);

struct	s_pyramid
{
	int w;
	int h;
	int size;
};
typedef struct s_pyramid	t_pyramid;

struct	s_door
{
	int x;
	int y;
	int s;
	int dolx;
	int doly;
};
typedef struct s_door	t_door;

void	print_door(t_door *door, int i, int j)
{
	if (j == door->dolx && i == door->doly)
		ft_putchar('$');
	else
		ft_putchar('|');
}

void	print_line(int step_width, int i, int *offset, t_door *door)
{
	int j;

	j = -1;
	while (++j < *offset + step_width)
	{
		if (j < *offset)
			ft_putchar(' ');
		else if (j < *offset + step_width)
		{
			ft_putchar('/');
			while (j++ <= *offset + step_width - 1)
			{
				if (j >= door->x && i >= door->y &&
					j < door->x + door->s && i < door->y + door->s)
				{
					print_door(door, i, j);
				}
				else
					ft_putchar('*');
			}
			ft_putchar('\\');
		}
	}
}

void	print_all(t_pyramid *pyramid, t_door *door)
{
	int i;
	int cur_step;
	int ofs;
	int step_height;
	int step_width;

	ofs = (pyramid->w / 2) - 1;
	step_width = 1;
	step_height = 3;
	i = 0;
	while (i < pyramid->h)
	{
		cur_step = -1;
		while (++cur_step < step_height)
		{
			print_line(step_width, i, &ofs, door);
			ft_putchar('\n');
			step_width += 2;
			ofs -= 1;
			++i;
		}
		step_height++;
		step_width += 4;
		ofs -= 2;
	}
}

void	set_door_data(int size, t_pyramid *pyramid, t_door *door)
{
	door->s = (size % 2) ? size : size - 1;
	door->x = (pyramid->w / 2) - (door->s / 2);
	door->y = pyramid->h - door->s;
	if (size > 4)
	{
		door->dolx = (pyramid->w / 2) + (door->s / 2) - 1;
		door->doly = pyramid->h - (door->s / 2) - 1;
	}
	else
	{
		door->dolx = -1;
		door->doly = -1;
	}
}

void	sastentua(int size)
{
	int			i;
	int			j;
	int			step_size;
	t_pyramid	pyramid;
	t_door		door;

	if (size < 1)
		return ;
	pyramid.w = 3;
	pyramid.h = 0;
	step_size = 3;
	j = -1;
	while (++j < size)
	{
		if (j)
			pyramid.w += 6;
		i = 0;
		while (++i < step_size)
			pyramid.w += 2;
		pyramid.h += step_size;
		step_size++;
	}
	set_door_data(size, &pyramid, &door);
	print_all(&pyramid, &door);
}
