/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:21:34 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/11 20:28:57 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	V3.0
*/

#ifndef DEBUG_UTILS_H
# define DEBUG_UTILS_H

# include <stdio.h>
# include <stdint.h>
# include <string.h>

# ifndef _VAR_WIDTH
#  define _VAR_WIDTH 8
# endif

# ifndef _MSG_WIDTH
#  define _MSG_WIDTH 2
# endif

# ifndef _BREAK_PAUSE
#  define _BREAK_PAUSE 1
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

# define _print(fmt, ... ) dprintf( _FD, fmt, ##__VA_ARGS__ );

# define _BR(NEWLINE) _print("%s< %s:%d in %s() >" _CL_RST "%s",((NEWLINE) ? (_CL_BR) : (_CL_BR_FADE)), __FILE__, __LINE__, __FUNCTION__, (NEWLINE == 1) ? ("\n") : (" "));
# define _BR_MSG(msg) _print( _CL_MSG "{%*s} " _CL_RST , _MSG_WIDTH,  #msg);

# if _BREAK_PAUSE == 1
#  define BR _BR(1); getchar();
# else
#  define BR _BR(1);
# endif

# if _BREAK_PAUSE == 1
#  define BMB(msg) _BR_MSG(msg) _BR(1) getchar();
# else
#  define BMB(msg) _BR_MSG(msg) _BR(1)
# endif

# define BM(msg) _BR_MSG(msg) _BR(1)

# define _DE_CONV_DEC(var) _Generic(((var)+0),	\
	char					: "%*c", \
    signed char				: "%*hhd", \
    unsigned char			: "%*hhu", \
    signed short			: "%*hd", \
    unsigned short			: "%*hu", \
    signed int				: "%*d", \
    unsigned int			: "%*u", \
    long int				: "%*ld", \
    unsigned long int		: "%*lu", \
    long long int			: "%*lld", \
    unsigned long long int	: "%*llu", \
    float					: "%*f", \
    double					: "%*f", \
    long double				: "%*Lf", \
    char *					: "%*s", \
    void *					: "%*p", \
    default					: "%*p")

# define _DE_AUTO(var) _print( _CL_VAR #var "%s", " = "); _print(_DE_CONV_DEC(var), _VAR_WIDTH, var); _print(_CL_RST "%s" , _DE_NL);

# define DE(var) _BR(0) _DE_AUTO(var)

# define DM(msg, var) _BR(0) _BR_MSG(msg) _DE_AUTO(var)

# define D_INT(var)  _BR(0) _print(_CL_VAR  #var " : %d"     _DE_NL , var);
# define D_LINT(var) _BR(0) _print( _CL_VAR #var " : %ld"    _DE_NL , var);
# define D_DOUB(var) _BR(0) _print(_CL_VAR  #var " : %f"     _DE_NL , var);
# define D_STR(var)  _BR(0) _print(_CL_VAR  #var " : \"%s\"" _DE_NL , var);
# define D_CHR(var)  _BR(0) _print(_CL_VAR  #var " : '%c'" _DE_NL , var);
# define D_PTR(var)  _BR(0) _print(_CL_VAR  #var " : <%p>"   _DE_NL , var);

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
			_print("|");
		}
	}
	_print("] END =*=\n");
}

/* ************************************************************************** */
/* ************************ RECURSIVE LINE BUILDER ************************** */
/* ************************************************************************** */

#define __FIRST(a, ...) a
#define __SECOND(a, b, ...) b

#define __EMPTY()

#define __EVAL(...) __EVAL1024(__VA_ARGS__)
#define __EVAL1024(...) __EVAL512(__EVAL512(__VA_ARGS__))
#define __EVAL512(...) __EVAL256(__EVAL256(__VA_ARGS__))
#define __EVAL256(...) __EVAL128(__EVAL128(__VA_ARGS__))
#define __EVAL128(...) __EVAL64(__EVAL64(__VA_ARGS__))
#define __EVAL64(...) __EVAL32(__EVAL32(__VA_ARGS__))
#define __EVAL32(...) __EVAL16(__EVAL16(__VA_ARGS__))
#define __EVAL16(...) __EVAL8(__EVAL8(__VA_ARGS__))
#define __EVAL8(...) __EVAL4(__EVAL4(__VA_ARGS__))
#define __EVAL4(...) __EVAL2(__EVAL2(__VA_ARGS__))
#define __EVAL2(...) __EVAL1(__EVAL1(__VA_ARGS__))
#define __EVAL1(...) __VA_ARGS__

#define __DEFER1(m) m __EMPTY()
#define __DEFER2(m) m __EMPTY __EMPTY()()
#define __DEFER3(m) m __EMPTY __EMPTY __EMPTY()()()
#define __DEFER4(m) m __EMPTY __EMPTY __EMPTY __EMPTY()()()()

#define __IS_PROBE(...) __SECOND(__VA_ARGS__, 0)
#define __PROBE() ~, 1

#define CAT(a,b) a ## b

#define __NOT(x) __IS_PROBE(CAT(_NOT_, x))
#define ___NOT_0 __PROBE()

#define __BOOL(x) __NOT(__NOT(x))

#define __IF_ELSE(condition) ___IF_ELSE(__BOOL(condition))
#define ___IF_ELSE(condition) CAT(_IF_, condition)

#define _IF_1(...) __VA_ARGS__ _IF_1_ELSE
#define _IF_0(...)             _IF_0_ELSE

#define _IF_1_ELSE(...)
#define _IF_0_ELSE(...) __VA_ARGS__

#define __HAS_ARGS(...) __BOOL(__FIRST(_END_OF_ARGUMENTS_ __VA_ARGS__)())
#define _END_OF_ARGUMENTS_() 0

#define __MAP(m, first, ...)           \
  m(first)                           \
  __IF_ELSE(__HAS_ARGS(__VA_ARGS__))(    \
    __DEFER2(_MAP)()(m, __VA_ARGS__)   \
  )(                                 \
    /* Do nothing, just terminate */ \
  )
#define _MAP() __MAP

#define _PVAR(var) _print( _CL_VAR "- " #var " "); _print(_DE_CONV_DEC(var), -_VAR_WIDTH, var); _print(" -")

#define _BUILD_LINE(...)  __EVAL(__MAP(_PVAR, ##__VA_ARGS__ ))


#define DB(...) _BR(0) _BUILD_LINE(__VA_ARGS__) _print( _CL_RST "\n");

#define DBM(msg, ...) _BR(0) _BR_MSG(msg) _BUILD_LINE(__VA_ARGS__) _print( _CL_RST "\n");

#endif
