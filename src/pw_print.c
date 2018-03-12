/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:58:58 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/12 16:00:25 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	pw_color(t_array *v, int i, int d)
{
	if (!g_iscolor)
		return (EOC);
	if (ARRAY_DATA(v, i) == pw_get_max(v))
		return (RED);
	if (ARRAY_DATA(v, i) == ARRAY_DATA(v, i + 1) + d ||
		ARRAY_DATA(v, i) == ARRAY_DATA(v, i - 1) - d ||
		ARRAY_DATA(v, i) == ARRAY_DATA(v, i + 1) ||
		ARRAY_DATA(v, i) == ARRAY_DATA(v, i - 1))
		return (GREEN);
	else
		return (EOC);
}

void
	pw_print_stack(t_array *a, t_array *b)
{
	int			i;
	int			max;

	if (g_isanimated)
	{
		system("sleep 0.1");
		system("clear");
	}
	max = (pw_get_max(a) > pw_get_max(b) ? pw_get_max(a) : pw_get_max(b));
	i = a->size + b->size + 1;
	while (i >= 0)
	{
		if (i < (int)a->size)
			ft_printf("%*w%3d %*Q%*Q%w\t", pw_color(a, i, 1), ARRAY_DATA(a, i),
			ABS(ARRAY_DATA(a, i)), '-', max - ABS(ARRAY_DATA(a, i)), ' ');
		else
			ft_printf("%*Q\t", max + 4, ' ');
		if (i < (int)b->size)
			ft_printfln("%*w%3d %*Q%*Q%w", pw_color(b, i, -1), ARRAY_DATA(b, i),
			ABS(ARRAY_DATA(b, i)), '-', max - ABS(ARRAY_DATA(b, i)), ' ');
		else
			ft_printf("\n");
		i--;
	}
}