/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:13:38 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/17 18:03:16 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char	*s, ...);
int	_prt_pointer(unsigned long ptr);

int	_nsx_strlen(char *s);
int	_prt_char(char c);
int	_prt_str(char *s);

int	_prt_uint(unsigned int i);
int	_prt_int(int i);
int	_prt_uinthex(unsigned int ptr,	char form);
#endif