/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:43:58 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 23:11:06 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_up(t_map *fdf)
{
	int x;
	int y;

	if (fdf->mid_y < 0)
		return ;
	y = 0;
	while (y < fdf->h)
	{
		x = 0;
		while (x < fdf->w)
		{
			fdf->points[y][x].y -= MOVE;
			x++;
		}
		y++;
	}
	fdf->mid_y -= MOVE;
}

void	ft_down(t_map *fdf)
{
	int x;
	int y;

	if (fdf->mid_y > HIGHT)
		return ;
	y = 0;
	while (y < fdf->h)
	{
		x = 0;
		while (x < fdf->w)
		{
			fdf->points[y][x].y += MOVE;
			x++;
		}
		y++;
	}
	fdf->mid_y += MOVE;
}

void	ft_left(t_map *fdf)
{
	int x;
	int y;

	if (fdf->mid_x < 0)
		return ;
	y = 0;
	while (y < fdf->h)
	{
		x = 0;
		while (x < fdf->w)
		{
			fdf->points[y][x].x -= MOVE;
			x++;
		}
		y++;
	}
	fdf->mid_x -= MOVE;
}

void	ft_right(t_map *fdf)
{
	int x;
	int y;

	if (fdf->mid_x > WIDTH)
		return ;
	y = 0;
	while (y < fdf->h)
	{
		x = 0;
		while (x < fdf->w)
		{
			fdf->points[y][x].x += MOVE;
			x++;
		}
		y++;
	}
	fdf->mid_x += MOVE;
}
