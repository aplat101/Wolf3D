/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 16:48:11 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 19:06:44 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int				ft_checkerror(int ac, char **av, t_win *w)
{
	int			fd;

	if (ac == 3)
	{
		if (ft_check_dir(av[2]) < 0)
		{
			ft_putstr("Invalid cardinal point!\n");
			return (-1);
		}
		fd = open(av[ac - 2], O_RDONLY);
	}
	else
		fd = open(av[ac - 1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Wolf3d need an existing argument!\n");
		close(fd);
		return (-1);
	}
	if ((w->nbline = ft_checkvalidity(fd, w)) < 3)
	{
		ft_putstr("Invalid File!\n");
		return (-1);
	}
	if (w->cam_error == 0)
	{
		ft_putstr("Camera not present in the map!\n");
		return (-1);
	}
	ft_putstr("Correct File!\n");
	return (0);
}

int				ft_checkvalidity(int fd, t_win *w)
{
	char		*line;
	int			res;
	static int	y;
	static int	nbword;
	int			tmp;

	y = 0;
	tmp = 0;
	while ((res = get_next_line(fd, &line)) == 1)
	{
		if ((nbword = ft_check_line(line, w)) < 0)
		{
			free(line);
			return (-1);
		}
		if (nbword != tmp && y != 0)
		{
			free(line);
			return (-1);
		}
		tmp = nbword;
		free(line);
		y++;
	}
	return (y);
}

int				ft_check_line(char *line, t_win *w)
{
	int			i;
	int			res;

	i = 0;
	res = ft_countwords(line, ' ');
	if (res < 3)
		return (-1);
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
			return (res);
		if (ft_valid_char(line[i], w) == 0 ||
			(ft_valid_char(line[i], w) == 1 &&
			ft_valid_char(line[i + 1], w) == 1))
			return (-1);
		i++;
	}
	return (res);
}
