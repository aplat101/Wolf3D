/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 17:01:37 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 20:11:22 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "wolf3d.h"

int     main(int ac, char **av)
{
    t_win   *w;

    if (ac != 2 && ac != 3)
        ft_putstr("Wolf3d need one or two argument!\n");
    if (!(w = malloc(sizeof(t_win) + 1)))
        return (EXIT_FAILURE);
    w->cam_error = 0;
    if (ft_checkerror(ac, av, w) < 0)
		return (EXIT_FAILURE);
    ft_parser(av, w);
    ft_print_all(w);
    w->ptr = mlx_init();
	ft_create_window(w);
    ft_init_values(w, ac, av);
    ft_render(w);
    mlx_put_image_to_window(w->img, w->win, w->img_ptr, 0, 0);
    ft_mlx(w);
    return(0);
}