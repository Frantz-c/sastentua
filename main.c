/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/21 20:32:49 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 20:51:35 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

long	ft_atol(const char *);
void	sastentua(int);

int		print_usage(void)
{
	write(1, "usage: sastentua [int (min 0x0, max 0x7fffffff)]\n", 49);
	return (-1);
}

int		main(int argc, char **argv)
{
	long			size;

	if (argc != 2)
		return (print_usage());
	if ((size = ft_atol(argv[1])) < 1 || size > 0x7fffffff)
		return (print_usage());
	sastentua((int)size);
	return (0);
}
