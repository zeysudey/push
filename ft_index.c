/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyilmaz <zyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:07:18 by zyilmaz           #+#    #+#             */
/*   Updated: 2025/02/18 18:43:03 by zyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_i(t_list **a)
{
	t_list	*current;

	if (!a || !(*a))
		return;//burda free bak
	current = *a;
	while (current)
	{
		current->index = -1; // Başlangıçta tüm indeksleri -1 yap
		current = current->next;
	}
}

static t_list	*find_min(t_list **a)
{
	t_list	*current;
	t_list	*min_node;
	int		min_val;

	min_val = 2147483647; // INT_MAX
	min_node = NULL;
	current = *a;
	while (current)
	{
		if (current->index == -1 && current->val < min_val)
		{
			min_val = current->val;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

void ft_index (t_list **a)
{
    t_list	*min_node;
    int		i;
	int		list_len;

    if (!a || !(*a))
		return;
    reset_i(a);
	i = 0;
	list_len = list_size(*a); // Listenin boyutunu al

	while (current_index < list_len)
	{
		min_node = find_min(a);
		if (!min_node)
			break;
		min_node->index = i;
		i++;
    }
    
}
