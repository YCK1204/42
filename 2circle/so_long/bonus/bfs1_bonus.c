/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:49:02 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 17:49:08 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

t_bfs	*create_queue(void)
{
	t_bfs	*queue;

	queue = (t_bfs *)malloc(sizeof(t_bfs));
	queue->head = (t_node *)malloc(sizeof(t_node));
	queue->tail = (t_node *)malloc(sizeof(t_node));
	queue->head->next = queue->tail;
	queue->head->prev = NULL;
	queue->head->y = 0;
	queue->head->x = 0;
	queue->tail->next = NULL;
	queue->tail->prev = queue->head;
	queue->tail->y = 0;
	queue->tail->x = 0;
	queue->up = 0;
	queue->left = 0;
	queue->right = 0;
	queue->down = 0;
	return (queue);
}

t_node	*create_node(size_t y, size_t x)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->y = y;
	node->x = x;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*q_pop(t_bfs *queue)
{
	t_node	*d_node;
	t_node	*n_node;

	d_node = queue->head->next;
	n_node = d_node->next;
	queue->head->next = n_node;
	n_node->prev = queue->head;
	return (d_node);
}

void	insert_queue(t_bfs *queue, t_node *node)
{
	t_node	*last;

	if (queue->head->next == queue->tail)
	{
		queue->head->next = node;
		node->prev = queue->head;
	}
	else
	{
		last = queue->tail->prev;
		node->prev = last;
		last->next = node;
	}
	node->next = queue->tail;
	queue->tail->prev = node;
}
