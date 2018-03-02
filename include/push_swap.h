/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:35:43 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/02 14:51:02 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define ARRAY_DATA(D, I) ((int*)ARRAY_START(D))[I]
# define ARRAY_DATA_DOT(D, I) ((int*)((D).data))[I]

void		pw_swap(t_array *d);
void		pw_push(t_array *source, t_array *dest);
void		pw_rotate(t_array *d);
void		pw_rev_rotate(t_array *d);
int			pw_is_sorted(t_array *d);
void		pw_print_stack(t_array *a, t_array *b);

int			pw_get_min(t_array *d);
int			pw_get_max(t_array *d);
int			pw_get_avg(t_array *d);

#endif
