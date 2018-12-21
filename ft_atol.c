/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:35:54 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 20:46:20 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#define MYNULL	(void*)0

static const char	*left_trim(const char *s, int *negative)
{
	*negative = 0;
	while ((*s > 8 && *s < 14) || *s == 32)
		s++;
	if (*s > 47 && *s < 58)
		return (s);
	if (*s == '+')
	{
		s++;
		if (*s < 48 || *s > 57)
			return (MYNULL);
	}
	else if (*s == '-')
	{
		s++;
		if (*s < 48 || *s > 57)
			return (MYNULL);
		*negative = 1;
	}
	return (s);
}

static long			ft_strtol(const char *s, int negative)
{
	unsigned long	n;

	n = 0;
	while (*s > 47 && *s < 58)
	{
		n *= 10;
		n += *(s++) - 48;
	}
	return ((negative) ? (long)(~n + 1) : (long)n);
}

extern inline long	ft_atol(const char *s)
{
	int	negative;

	if ((s = left_trim(s, &negative)) == MYNULL)
		return (0);
	return (ft_strtol(s, negative));
}
