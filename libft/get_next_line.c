/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 13:54:26 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 15:41:12 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

static int		errorgnl(const int fd, char *buf)
{
	if (BUFF_SIZE < 0 || fd == -1)
		return (-1);
	if (read(fd, buf, 0))
		return (-1);
	return (0);
}

static char		*readline(char **str, int ret, const int fd, char *buf)
{
	char		*tmp;

	buf[ret] = '\0';
	if (str[fd] == NULL)
		str[fd] = ft_strdup(buf);
	else
	{
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buf);
		free(tmp);
	}
	return (str[fd]);
}

static int		ft_instrchr(const char *s, int c)
{
	int			start;

	start = 0;
	if (!s)
		return (-1);
	while (s[start])
	{
		if (s[start] == c)
			return (start);
		start++;
	}
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*str[1024];
	int			start;
	char		*tmp;

	if (errorgnl(fd, buf) == -1)
		return (-1);
	while ((ft_instrchr(str[fd], '\n') == -1) &&
			(ret = read(fd, buf, BUFF_SIZE)) > 0)
		str[fd] = readline(str, ret, fd, buf);
	if (ret == 0 && str[fd][0] == '\0')
		return (0);
	start = ft_instrchr(str[fd], '\n');
	if (start == -1)
		start = ft_strlen(str[fd]);
	*line = ft_strsub(str[fd], 0, start);
	if (str[fd] != NULL)
	{
		tmp = str[fd];
		str[fd] = ft_strsub(str[fd], start + 1, ft_strlen(str[fd]) - start);
		free(tmp);
	}
	return (1);
}
