/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:21:34 by lorenuar          #+#    #+#             */
/*   Updated: 2021/04/03 17:12:04 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_UTILS_H
# define DEBUG_UTILS_H

# include <stdio.h>
# include <stdint.h>

# ifndef BREAK_PAUSE
#  define BREAK_PAUSE 1
# endif

# ifndef _NEWLINE
#  define _NEWLINE 1
# endif

# if _NEWLINE == 1
#  define _DE_NL "\n"
#  define _BR_NL "\t"
# else
#  define _DE_NL " "
#  define _BR_NL " "
# endif

# ifndef _FD
#  define _FD 2
# endif

# define _print(fmt, ... ) dprintf( _FD, fmt, __VA_ARGS__ )

# define _BR(NEWLINE) _print( "< %s:%d in %s() >%s", __FILE__, __LINE__, __FUNCTION__, (NEWLINE == 1) ? ("\n") : (" "))
# define _BR_MSG(msg) _print( "{ %s } - ", #msg)

# if BREAK_PAUSE == 1
#  define BR _BR(0); getchar();
# else
#  define BR _BR(1);
# endif

# if _BREAK_PAUSE == 1
#  define BM(msg) _BR_MSG(msg); _BR(1); getchar();
# else
#  define BM(msg) _BR_MSG(msg); _BR(1);
# endif

# define _DE_AUTO(var) _Generic(((var)+0),	\
	int		: _print( "|" #var " = " "%d" _DE_NL , var),		\
	long	: _print( "|" #var " = " "%ld" _DE_NL , var),		\
	double	: _print( "|" #var " = " "%f" _DE_NL , var),		\
	float	: _print( "|" #var " = " "%f" _DE_NL , var),		\
	size_t	: _print( "|" #var " = " "%lu" _DE_NL , var),		\
	char*	: _print( "|" #var " = " "\"%s\"" _DE_NL , var),	\
	default	: _print( "|" #var " = " "%p" _DE_NL , var))

# define DE(var) _BR(0); _DE_AUTO(var);

# define DM(msg, var) _BR(0); _BR_MSG(msg); _DE_AUTO(var);

# define D_INT(var) _print( "< %s:%d in %s() > " #var " : %d" _DE_NL, __FILE__, __LINE__, __FUNCTION__, var);
# define D_LINT(var) _print( "< %s:%d in %s() > " #var " : %ld" _DE_NL, __FILE__, __LINE__, __FUNCTION__, var);
# define D_DOUB(var) _print( "< %s:%d in %s() > " #var " : %f" _DE_NL, __FILE__, __LINE__, __FUNCTION__, var);
# define D_STR(var) _print( "< %s:%d in %s() > " #var " : \"%s\"" _DE_NL, __FILE__, __LINE__, __FUNCTION__, var);
# define D_PTR(var) _print( "< %s:%d in %s() > " #var " : <%p>" _DE_NL, __FILE__, __LINE__, __FUNCTION__, var);

# define D_STR_DETAILS(str) print_str_details(strlen(str), str, #str);

static inline void	print_str_details(size_t len, char *str, const char *name)
{
	len++;
	_print( "=*= START DETAILS[%s][%p](len %ld): \n[", name, str, len);
	while (len > 0)
	{
		if (*str >= ' ' && *str < '~')
		{
			_print( "%c", *str);
		}
		else
		{
			_print( "\\%d", *str);
		}
		str++;
		len--;
		if (len > 0)
		{
			dprintf( _FD, "|");
		}
	}
	dprintf( _FD, "] END_DETAILS =*=\n");
}

#endif
