/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:46:44 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/07 02:47:09 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_swap(t_array *d, t_array *dv)
{
	int temp;

	(void)dv;
	if (d->size < 2)
		return ;
	temp = ARRAY_DATA(d, d->size - 2);
	ARRAY_DATA(d, d->size - 2) = ARRAY_DATA(d, d->size - 1);
	ARRAY_DATA(d, d->size - 1) = temp;
}

void
	pw_push(t_array *dest, t_array *source)
{
	int temp;

	if (source->size == 0)
		return ;
	temp =ARRAY_DATA(source, source->size - 1);
	fta_popback(source, 1);
	fta_append(dest, &temp, 1);
}

void
	pw_rotate(t_array *d, t_array *dv)
{
	int temp;

	(void)dv;
	if (d->size == 0)
		return ;
	temp = ARRAY_DATA(d, 0);
	fta_popindex(d, 0, 1);
	fta_append(d, &temp, 1);
}

void
	pw_rev_rotate(t_array *d, t_array *dv)
{
	int temp;

	(void)dv;
	if (d->size == 0)
		return ;
	temp = ARRAY_DATA(d, d->size-1);
	fta_popback(d, 1);
	fta_insert(d, &temp, 1, 0);
}