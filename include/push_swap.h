#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}				t_stack;

typedef struct s_util
{
	int		max;
	int		chunk1;
	int		chunk2;
	int		chunk3;
	int		chunk4;
	int		chunk5;
	int		chunk6;
	int		chunk7;
	int		chunk8;
	int		chunk9;
	int		chunk10;
	int		chunk11;
	int		chunk12;
	int		hold1;
	int		hold2;
	int		index1;
	int		index2;
	int		mid;
	int		len;
	int		i;
	int		counter;
	int		go;
	int		lenstack;
	int		small;
	int		save;
	t_stack	*sta;
	t_stack	*stb;
	t_stack	*head_a;
}				t_util;

int		getAt(t_stack *st, int pos);
int		is_empty(t_stack *st);
void	addAt(t_util *util, int data, int pos);
void	addAt_B(t_util *util, int data, int pos);
t_stack	*createCell(int data);
void	printStack(t_stack *st);
void	freeList(t_util *util);
int		lenStack(t_stack *st);
void	freeAt(t_util *util, int pos);
void	freeAt_B(t_util *util, int pos);
void	push_b(t_util *util);
void	push_a(t_util *util);
void	rra(t_util *util);
void	rrb(t_util *util);
void	ra(t_util *util);
void	rb(t_util *util);
void	sa(t_util *util);
void	initStack(t_util *util, char *argv);
int		test_double(char **argv, int argc);
int		test_argv(char **argv, int argc);
int		ft_find_biggest(t_stack *sta);
void	ft_set_chunks(t_stack *sta, t_util *util);
void	ft_scan(t_util *util, int min, int max);
void	ft_parser(t_stack *sta, t_stack *stb, t_util *util);
void	ft_move_chunks(t_util *util);
int		still_chunk(t_util *util, int min, int max);
int		ft_find_smallest(t_stack *sta, t_util *util);
void	sort_b(t_stack *stb, t_util *util);
int		is_sorted(t_stack *st);
int		ft_find_small(t_stack *st, t_util *util);
void	sort_very_small(t_util *util);
void	sort_small(t_util *util);
int		is_a_sorted(t_util *util);
void	ft_check_double_arg(int	*arr, int count, t_util *util);
void	ft_parse_arg(char **argv, t_util *util);
void	ft_set_chunks_big(t_stack *sta, t_util *util);
void	parse_medium(t_util *util);
void	parse_big(t_util *util);
void	parse_big_2(t_util *util);
void	parse_big_3(t_util *util);
void	parse_big_4(t_util *util);
void	ft_scan2(t_util *util, int min, int max, t_stack *tmp);
void	parse_medium2(t_util *util);
void	ft_move_chunks2(t_util *util, int i);
void	addAt2(t_stack	*cell, t_stack *prec, int pos, t_stack *current);
void	addAt_B2(t_stack	*cell, t_stack *prec, int pos, t_stack *current);
void	ft_main_sequel(t_util *util);
int		test_int_max(char **argv, int *tab, int i, int j);
void	addnew(t_util *util, int data);
void	addnew_b(t_util *util, int data);

#endif
