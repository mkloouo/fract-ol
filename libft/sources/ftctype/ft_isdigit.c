/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:19:57 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 18:38:52 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftctype.h>

int						ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
