/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:20:50 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/24 17:42:13 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct			s_vec3f
{
	float				x;
	float				y;
	float				z;
}						t_vec3f;

typedef struct			s_vec3i
{
	int					x;
	int					y;
	int					z;
}						t_vec3i;

typedef struct			s_vec2i
{
	int					x;
	int					y;
}						t_vec2i;

t_vec3f					get_vec3f(float x, float y, float z);
t_vec3f					*alloc_vec3f(float x, float y, float z);
void					del_vec3f(t_vec3f **vp);
void					set_vec3f(t_vec3f *v, float x, float y, float z);

t_vec2i					get_vec2i(int x, int y);
t_vec2i					*alloc_vec2i(int x, int y);
void					del_vec2i(t_vec2i **vp);
void					set_vec2i(t_vec2i *v, int x, int y);

t_vec3i					get_vec3i(int x, int y, int z);
t_vec3i					*alloc_vec3i(int x, int y, int z);
void					del_vec3i(t_vec3i **vp);
void					set_vec3i(t_vec3i *v, int x, int y, int z);

#endif
