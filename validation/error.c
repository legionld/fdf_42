/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:56:46 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/03 22:28:59 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_free(t_map *fdf)
{
	int y;

	y = 0;
	if (fdf)
	{
		while (y < fdf->h && fdf->points && fdf->points[y])
		{
			ft_memdel((void **)&(fdf->points[y]));
			y++;
		}
		y = -1;
		while (++y < fdf->h && fdf->points && fdf->points[y])
			ft_memdel((void **)&(fdf->points[y]));
		ft_memdel((void **)&(fdf->points));
		ft_memdel((void **)&(fdf));
	}
}

void			ft_error(int a, t_mlx *mlx, t_map *fdf)
{
	if (a == 2)
	{
		write(1, "Invalid map\n", 12);
		if (fdf)
			ft_free(fdf);
		if (mlx)
		{
			ft_free(mlx->map);
			ft_memdel((void **)&(mlx));
		}
	}
	if (a == 1)
		write(1, "usage: ./fdf <filename>\n", 25);
	if (a == 0)
	{
		write(1, "error\n", 6);
		if (fdf)
			ft_free(fdf);
		if (mlx)
		{
			ft_free(mlx->map);
			ft_memdel((void **)&(mlx));
		}
	}
	exit(0);
}
