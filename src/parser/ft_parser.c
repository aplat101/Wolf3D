/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:37:42 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 11:09:01 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_parser(char **av, t_win *w)
{
	int		fd;
	int		res;
	char	*line;
	int		i;

	i = -1;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Wolf3d need an existing argument!\n");
		close(fd);
		return (-1);
	}
	if (ft_parser_alloc(w) == -1)
		return (-1);
	while ((res = get_next_line(fd, &line)) == 1 && fd > 0)
	{
		w->nbwalls[++i] = ft_countwords(line, ' ');
		if (!(w->map[i] = malloc(sizeof(int) * (w->nbwalls[i]))))
			return (EXIT_FAILURE);
		w->map[i] = ft_stock_map(i, line, w->map[i], w);
		free(line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int			*ft_stock_map(int nbline, char *line, int *map, t_win *w)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
			return (map);
		map[j] = ft_atoi(&line[i]);
		if (map[j] == 2)
			ft_set_cam_pos(w, nbline, j);
		j++;
		i++;
	}
	return (map);
}

void		ft_set_cam_pos(t_win *w, int nbline, int j)
{
	if (j == w->nbwalls[0] - 1 || nbline == w->nbline - 1
		|| j == 0 || nbline == 0)
	{
		ft_putstr("Invalid Camera!\n");
		exit(0);
	}
	if (!(w->pos_cam = malloc(sizeof(t_vec))))
		return ;
	w->pos_cam->x = j + 0.5;
	w->pos_cam->y = nbline + 0.5;
	if (!(w->pos_map = malloc(sizeof(t_point))))
		return ;
	w->pos_map->x = (int)w->pos_cam->x;
	w->pos_map->y = (int)w->pos_cam->y;
}

void		ft_init_values(t_win *w, int ac, char **av)
{
	w->h_cam = HH / 2;
	w->cam_x = 0;
	w->h_wall = HH;
	w->h_wall_max = HH / 2;
	w->fov = 60;
	if (!(w->dir_cam = malloc(sizeof(t_vec))))
		return ;
	if (!(w->plane = malloc(sizeof(t_vec))))
		return ;
	ft_set_cam_dir(ac, av, w);
	if (!(w->raydir = malloc(sizeof(t_vec))))
		return ;
	if (!(w->side = malloc(sizeof(t_vec))))
		return ;
	if (!(w->delta = malloc(sizeof(t_vec))))
		return ;
	if (!(w->step = malloc(sizeof(t_point))))
		return ;
	if (!(w->t = malloc(sizeof(t_point))))
		return ;
	w->dir_wall = 0;
	w->touch = 0;
	w->x = -1;
	w->x_wall = 0;
	w->texture = 0;
}
