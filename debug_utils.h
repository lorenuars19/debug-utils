/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:21:34 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/04 23:57:33 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	V2.2
*/

#ifndef DEBUG_UTILS_H
# define DEBUG_UTILS_H

# include <stdio.h>
# include <stdint.h>
# include <string.h>

# ifndef _VAR_WIDTH
#  define _VAR_WIDTH 2
# endif

# ifndef _MSG_WIDTH
#  define _MSG_WIDTH 2
# endif

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

# ifndef _NO_COLORS
#  define _CL_BR_FADE "\033[37;2m"
#  define _CL_BR "\033[38;1m"
#  define _CL_MSG "\033[33;1m"
#  define _CL_VAR "\033[36;1m"
#  define _CL_RST "\033[0m"
# else
#  define _CL_BR_FADE ""
#  define _CL_BR ""
#  define _CL_MSG ""
#  define _CL_VAR ""
#  define _CL_RST ""
# endif

# define _print(fmt, ... ) dprintf( _FD, fmt, __VA_ARGS__ )

# define _BR(NEWLINE) _print("%s< %s:%d in %s() >" _CL_RST "%s",((NEWLINE) ? (_CL_BR) : (_CL_BR_FADE)), __FILE__, __LINE__, __FUNCTION__, (NEWLINE == 1) ? ("\n") : (" "))
# define _BR_MSG(msg) _print( _CL_MSG "{%*s} " _CL_RST , _MSG_WIDTH,  #msg)

# if BREAK_PAUSE == 1
#  define BR _BR(1); getchar();
# else
#  define BR _BR(1);
# endif

# if _BREAK_PAUSE == 1
#  define BM(msg) _BR_MSG(msg); _BR(1); getchar();
# else
#  define BM(msg) _BR_MSG(msg); _BR(1);
# endif

# define _DE_AUTO(var) _Generic(((var)+0),	\
	int		: _print( _CL_VAR #var " = " "%*d"     _CL_RST _DE_NL , _VAR_WIDTH ,var),	\
	long	: _print( _CL_VAR #var " = " "%*ld"    _CL_RST _DE_NL , _VAR_WIDTH ,var),	\
	double	: _print( _CL_VAR #var " = " "%*f"     _CL_RST _DE_NL , _VAR_WIDTH ,var),	\
	float	: _print( _CL_VAR #var " = " "%*f"     _CL_RST _DE_NL , _VAR_WIDTH ,var),	\
	size_t	: _print( _CL_VAR #var " = " "%*lu"    _CL_RST _DE_NL , _VAR_WIDTH ,var),	\
	char*	: _print( _CL_VAR #var " = " "\"%*s\"" _CL_RST _DE_NL , _VAR_WIDTH ,var),	\
	default	: _print( _CL_VAR #var " = " "%*p"     _CL_RST _DE_NL , _VAR_WIDTH ,var))

# define DE(var) _BR(0); _DE_AUTO(var);

# define DM(msg, var) _BR(0); _BR_MSG(msg); _DE_AUTO(var);

# define D_INT(var)  _BR(0); _print(_CL_VAR  #var " : %d"     _DE_NL , var);
# define D_LINT(var) _BR(0); _print( _CL_VAR #var " : %ld"    _DE_NL , var);
# define D_DOUB(var) _BR(0); _print(_CL_VAR  #var " : %f"     _DE_NL , var);
# define D_STR(var)  _BR(0); _print(_CL_VAR  #var " : \"%s\"" _DE_NL , var);
# define D_PTR(var)  _BR(0); _print(_CL_VAR  #var " : <%p>"   _DE_NL , var);

# define D_STR_DETAILS(str) _BR(0); print_str_details(strlen(str), str, #str);

# define D_STR_DETAILS_LEN(str, len) _BR(0); print_str_details(len, str, #str);

static inline void	print_str_details(size_t len, char *str, const char *name)
{
	len++;
	_print( "=*= str_details : %s [%p](len %ld): \n[", name, str, len);
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
	dprintf( _FD, "] END =*=\n");
}

#endif
