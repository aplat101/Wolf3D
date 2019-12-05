/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 15:37:42 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 19:26:47 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_parser(char **av, t_win *w)
{
	int	fd;
	int	res;
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
	if (!(w->map = (int**)malloc(sizeof(int*) * (w->nbline))))
		return (EXIT_FAILURE);
	if (!(w->nbwalls = malloc(sizeof(int) * w->nbline)))
		return (EXIT_FAILURE);
	while ((res = get_next_line(fd, &line)) == 1 && fd > 0)
	{
		w->nbwalls[++i] = ft_countwords(line, ' ');
		if (!(w->map[i] = malloc(sizeof(int) * (w->nbwalls[i]))))
			return (EXIT_FAILURE);
		w->map[i] = ft_stock_map(i, line, w->map[i], w);
		free(line);
	}
	return (EXIT_SUCCESS);
}

int		*ft_stock_map(int nbline, char *line, int *map, t_win *w)
{
	int	i;
	int	j;

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

void	ft_set_cam_pos(t_win *w, int nbline, int j)
{
	if (!(w->pos_cam = malloc(sizeof(t_point))))
		return ;
	w->pos_cam->x = j;
	w->pos_cam->y = nbline;
}

void	ft_init_values(t_win *w, int ac, char **av)
{
	w->h_cam = HH / 2;
	w->fov = 60;
	if (!(w->dir_cam = malloc(sizeof(t_vec))))
		return ;
	ft_set_cam_dir(ac, av, w);
}