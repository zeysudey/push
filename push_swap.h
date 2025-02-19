/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyilmaz <zyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:30:40 by zyilmaz           #+#    #+#             */
/*   Updated: 2025/02/18 17:16:56 by zyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <unistd.h>
#include "libft/libft.h"
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;
void	arg_count_t_plus(char **av, t_list **a, t_list **b);
void	arg_count_two(char **av, t_list **a, t_list **b);
void	free_split(char **tokens);
void	freelist(t_list **a);
void	freelists(t_list **a);
void	lst_add_end(t_list **head, int value);
void	put_err();
int		check_sort(t_list **a);
void ft_lstadd_backst(t_list **lst, t_list *new);
int ft_lstsizepush(t_list **lst);
t_list *ft_lstnews(int content);
t_list *ft_lstlaststac(t_list *lst);
void input_sort(t_list **a, t_list **b);
#endif