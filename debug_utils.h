/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:21:34 by lorenuar          #+#    #+#             */
/*   Updated: 2021/04/01 23:45:26 by lorenuar         ###   ########.fr       */
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
#  define _DE_NL "\t"
#  define _BR_NL " "
# endif

# define _BR(NEWLINE) printf("< %s:%d in %s() >%s", __FILE__, __LINE__, __FUNCTION__, (NEWLINE == 1) ? ("\n") : (" "));
# define _BR_MSG(msg) printf("{ " #msg " } - ");

# if BREAK_PAUSE == 1
#  define BR _BR(0) getchar();
# else
#  define BR _BR(1);;
# endif

# if _BREAK_PAUSE == 1
#  define BM(msg) _BR_MSG(msg) _BR(0); getchar();
# else
#  define BM(msg) _BR_MSG(msg) _BR(1);
# endif

#define _CONV(var)

# define _DE_AUTO(var) _Generic(((var)+0),	\
	int		: printf("|" #var " = " "%d" _DE_NL , var),		\
	long	: printf("|" #var " = " "%ld" _DE_NL , var),	\
	double	: printf("|" #var " = " "%f" _DE_NL , var),		\
	float	: printf("|" #var " = " "%f" _DE_NL , var),		\
	size_t	: printf("|" #var " = " "%lu" _DE_NL , var),	\
	char*	: printf("|" #var " = " "\"%s\"" _DE_NL , var),	\
	default	: printf("|" #var " = " "%p" _DE_NL , var));

# define DE(var) _BR(0) _DE_AUTO(var);

# define DM(msg, var) _BR(0) _BR_MSG(msg) _DE_AUTO(var);

# define D_INT(var) printf("< %s:%d in %s() > " #var " : %d" _DE_NL, __FILE__, __LINE__, __FUNCTION__, var);
# define D_LINT(var) printf("< %s:%d in %s() > " #var " : %ld" _DE_NL, __FILE__, __LINE__, __FUNCTION__, var);
# define D_DOUB(var) printf("< %s:%d in %s() > " #var " : %f" _DE_NL, __FILE__, __LINE__, __FUNCTION__, var);
# define D_STR(var) printf("< %s:%d in %s() > " #var " : \"%s\"" _DE_NL, __FILE__, __LINE__, __FUNCTION__, var);
# define D_PTR(var) printf("< %s:%d in %s() > " #var " : <%p>" _DE_NL, __FILE__, __LINE__, __FUNCTION__, var);

# define D_STR_DETAILS(str) print_str_details(strlen(str), str, #str)

static inline void	print_str_details(size_t len, char *str, const char *name)
{
	len++;
	printf("=*= START DETAILS[%s][%p](len %ld): \n[", name, str, len);
	while (len > 0)
	{
		if (*str >= ' ' && *str < '~')
		{
			printf("%c", *str);
		}
		else
		{
			printf("\\%d", *str);
		}
		str++;
		len--;
		if (len > 0)
		{
			printf("|");
		}
	}
	printf("] END_DETAILS =*=\n");
}

#endif
