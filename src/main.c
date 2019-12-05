/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 17:01:37 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 16:08:23 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "wolf3d.h"

int     main(int ac, char **av)
{
    t_win   *w;

    if (ac != 2)
        ft_putstr("Wolf3d need only one argument!\n");
    if (!(w = malloc(sizeof(t_win) + 1)))
        return (EXIT_FAILURE);
    w->cam_error = 0;
    if (ft_checkerror(ac, av, w) < 0)
		return (EXIT_FAILURE);
    ft_parser(ac, av, w);
    ft_print_map(w);
    return(0);
}