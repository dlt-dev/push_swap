/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:53:41 by jdelattr          #+#    #+#             */
/*   Updated: 2025/07/26 12:41:50 by jdelattr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node	t_node;
struct s_node
{
	int		value;
	int		index;
	int		cost_a;
	int		cost_b;
	int		total_cost;
	t_node	*next;
	t_node	*prev;
};

//-> split_args.c//
int		count_data(const char *str);
char	**ft_allocsplit(int count_data);
char	**ft_freesplit(char **split, int j);
char	**ft_fillsplit(char **split, char const *str);
char	**split_args(char const *str);
//-> parsing_utils.c//
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *source, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atol_secure(const char *str, int *error);
//-> parsing.c//
int		valid_check(char **tab_args);
int		*convert_valid_int(char **tab_args, int count_ar, int *error);
int		how_many_twins(int *int_tab, int to_check, int count_ar);
int		twins_check(int *int_tab, int count_ar);
int		count_args(char **tab);
//−> stack.c//
t_node	*create_stack(int *int_tab, int size);
void	my_index(t_node *stack);
void	free_stack(t_node *stack);
//−> stack_utils.c//
t_node	*ft_lstnew(int arg_val);
void	push(t_node **head, int arg_val);
int		ft_lstsize(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);
//-> sort.c//
int		is_sorted(t_node *stack);
void	sort_three_val(t_node **stack);
t_node	*find_biggest(t_node *stack);
t_node	*find_last(t_node *stack);
void	under_one_fifty(t_node **stack_a, t_node **stack_b);
//-> algorithme.c//
int		median_stack(t_node *stack);
void	insert_in_a(t_node **stack_a, t_node **stack_b);
void	final_rotate(t_node **stack_a);
void	step_one(t_node **stack_a, t_node **stack_b);
void	push_swap_algo(t_node **stack_a, t_node **stack_b);
//-> algorithm_utils.c//
int		find_min(t_node *stack_a);
int		find_max(t_node *stack_a);
int		find_insert_pos(t_node *stack_a, int index_top_b);
//-> sort_utils.c//
void	swap_a(t_node **stack, bool print);
void	swap_b(t_node **stack, bool print);
void	swap_a_b(t_node **stack_a, t_node **stack_b, bool print);
void	rot_a(t_node **stack, bool print);
void	rot_b(t_node **stack, bool print);
void	rot_a_b(t_node **stack_a, t_node **stack_b, bool print);
void	rev_rot_a(t_node **stack, bool print);
void	rev_rot_b(t_node **stack, bool print);
void	rev_rot_a_b(t_node **stack_a, t_node **stack_b, bool print);
void	push_a(t_node **stack_a, t_node **stack_b, bool print);
void	push_b(t_node **stack_b, t_node **stack_a, bool print);
//-> cost.c//
int		abso_val(int n);
void	calculate_costs(t_node *stack_a, t_node *stack_b);
t_node	*find_cheapest_move(t_node *stack_b);
void	do_rotate(t_node **stack_a, t_node **stack_b, int *cost_a, int *cost_b);
void	execute_move(t_node **stack_a, t_node **stack_b, t_node *node);
//-> main.c//
int		main(int ac, char **av);
t_node	*init(int ac, char **av, int *error);

#endif
