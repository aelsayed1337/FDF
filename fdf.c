/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:45:31 by kali              #+#    #+#             */
/*   Updated: 2025/01/21 18:08:39 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mycmp(char *s)
{
	int	l;

	l = ft_strlen(s) - 1;
	if (l + 1 >= 5)
	{
		if (!ft_strncmp(&s[l - 3], ".fdf", 4))
			return (1);
		else
			return (0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	t_all	vars;

	i = 0;
	if (ac == 2 && mycmp(av[1]))
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (perror("Failed to open file"), 1);
		vars.file = ft_read(fd, av[1]);
		if (!vars.file)
			return (close(fd), perror("Failed to read file"), 1);
		while (vars.file[i])
			i++;
		feed_tab(vars.file, i, &vars);
		fill_scale(&vars.scale);
		draw_shape(&vars, 0);
		return (ft_free("2", vars.file), close(fd), 0);
	}
	printfd(2, "Invalid Argument\n");
	printfd(2, "\tExpected Format: ./fdf <filename.fdf>\n");
}
