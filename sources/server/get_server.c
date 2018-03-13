/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:40:53 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 21:36:14 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <mlx.h>
#include <stddef.h>

void					*get_server(void)
{
	static void			*server = NULL;

	if (server == NULL)
		server = mlx_init();
	return (server);
}
