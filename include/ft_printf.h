/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:13:38 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/16 21:51:00 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
int		ft_printf(const char	*s, ...);
int		_prt_ptr(unsigned long ptr, char *base);
void	_nsx_prtint(int n);
int		_nsx_prtlint(int n);
void	_nsx_prtuint(unsigned int n);
int		_nsx_prtluint(unsigned int n);
int		_prt_ptrx(unsigned long ptr, char *base);
#endif