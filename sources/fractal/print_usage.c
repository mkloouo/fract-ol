/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:14:55 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/24 17:15:03 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <ftio.h>

void					print_usage(char *name)
{
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putendl(" fractal-type\nWhere fractal-type:\n\tMandelbrot");
}
