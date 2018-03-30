/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:37:28 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/30 20:33:33 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <server.h>

int						main(int ac, char **av)
{
	t_fractal			*f;

	if (init_fractal(&f, ac, av)) // TODO: Remove ref to f
		start_server();
	print_usage(av[0]);
	return (1);
}
