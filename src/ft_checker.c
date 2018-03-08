/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:36 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/08 11:38:17 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int g_isverbose;

#include "push_swap.h"

void
	pw_checker(char *line, t_array *a, t_array *b)
{
	int			i;
	int			index;
	const char	*c = "spr";
	const void	*op[] = {
		&pw_swap, &pw_push, &pw_rotate, &pw_rev_rotate
	};

	i = 0;
	index = 1;
	while (c[i] != '\0' && line[0] != c[i])
		i++;
	if (ft_strlen(line) == 3)
	{
		i = 3;
		index++;
	}
	if (line[index] == 'a' || line[index] == 'r')
		(((void (*)())op[i])(a, b));
	if (line[index] == 'b' || line[index] == 'r')
		(((void (*)())op[i])(b, a));
}

int
	main(int ac, char **av)
{
	int			i;
	char		*line;
	t_array		a;
	t_array		b;
	int			num;

	a = NEW_ARRAY(int);
	b = NEW_ARRAY(int);
	i = pw_getoptions(av, &g_isverbose);
	if (ac > 1)
	{
		while (i < ac)
		{
			num = atoi(av[i]);
			fta_append(&a, &num, 1);
			i++;
		}
		while (get_next_line(0, &line))
		{
			pw_checker(line, &a, &b);
			if (g_isverbose)
			{
				pw_print_stack(&a, &b);
				printf("Exec %s:\n", line);
			}
		}
		if (b.size == 0 && pw_is_sorted(&a))
			ft_printfln("OK");
		else
			ft_printfln("KO");
	}
}