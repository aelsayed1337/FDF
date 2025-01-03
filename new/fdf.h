#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdio.h>
#include "../minilibx-linux/mlx.h"
#include "../ft_libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../Get_next_line/get_next_line.h"
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846

typedef struct s_coordinates
{
    int X0;
    int Y0;
    int X1;
    int Y1;
    int **color;
    int c;
    int **tab;
    int lines;
    int columns;
}               t_vec;


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int     ft_color(const char *s);

#endif