/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:37:28 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/14 18:38:52 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <server.h>

int						main(int ac, char **av)
{
	t_fwin				fw;

	if (ac == 2 && (fw.type = get_fractal_type(av[1])) != -1)
	{
		fw = init_fw(ac, av);
		start_server();
	}
	print_fractol_usage(av[0]);
    return (1);
}
