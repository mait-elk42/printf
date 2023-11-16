/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:13:38 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/16 10:40:53 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char	*s, ...);
size_t	_prt_char(char c);
size_t	_prt_str(const char *s);
size_t	_prt_ptr(unsigned long ptr, char *base);
size_t	_prt_dec(int n);

size_t	_nsx_strlen(const char *s);

size_t	_nsx_diglen(unsigned long nmb, size_t baselen);
#endif