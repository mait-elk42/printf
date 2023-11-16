/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _nsx_dig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:07:09 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/16 11:36:45 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	_nsx_diglen(unsigned long nmb, size_t baselen)
{
	size_t	i;

	i = 0;
	while (nmb)
	{
		i++;
		nmb /= baselen;
	}
	return (i);
}