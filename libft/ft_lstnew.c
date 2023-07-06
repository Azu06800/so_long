/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:44:44 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/18 17:45:03 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(long content)
{
	t_list	*dst;

	dst = malloc(sizeof(t_list));
	if (!dst)
		return (NULL);
	dst->index = 0;
	dst->next = NULL;
	dst->content = content;
	return (dst);
}
