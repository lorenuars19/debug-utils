/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:21:34 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/11 18:21:49 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_UTILS_H
# define DEBUG_UTILS_H

# include <stdio.h>
# include <stdint.h>

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
#  define _DE_NL "\t"
#  define _BR_NL " "
# endif

# define _BR(NEWLINE) printf("#<[l %d] %s:%s()>#" _BR_NL, __LINE__, __FILE__, __FUNCTION__);

# if _BREAK_PAUSE == 1
#  define BR _BR(0) getchar();
# else
#  define BR _BR(1);
# endif

# define DE(var) _Generic(((var)+0),	\
	int		: printf("[l %d] %s:%s() | " #var " = %d"  _DE_NL , __LINE__, __FILE__, __FUNCTION__, var),	\
	long	: printf("[l %d] %s:%s() | " #var " = %ld" _DE_NL , __LINE__, __FILE__, __FUNCTION__, var),	\
	double	: printf("[l %d] %s:%s() | " #var " = %f" _DE_NL , __LINE__, __FILE__, __FUNCTION__, var),	\
	float	: printf("[l %d] %s:%s() | " #var " = %f" _DE_NL , __LINE__, __FILE__, __FUNCTION__, var),	\
	size_t	: printf("[l %d] %s:%s() | " #var " = %lu" _DE_NL , __LINE__, __FILE__, __FUNCTION__, var),	\
	char*	: printf("[l %d] %s:%s() | " #var " = \"%s\"" _DE_NL , __LINE__, __FILE__, __FUNCTION__, var),	\
	default	: printf("[l %d] %s:%s() | " #var " = %p" _DE_NL , __LINE__, __FILE__, __FUNCTION__, var))

# define D_INT(var) printf("[l %d] %s:%s() | " #var " : %d" _DE_NL, __LINE__, __FILE__, __FUNCTION__, var);
# define D_LINT(var) printf("[l %d] %s:%s() | " #var " : %ld" _DE_NL, __LINE__, __FILE__, __FUNCTION__, var);
# define D_DOUB(var) printf("[l %d] %s:%s() | " #var " : %f" _DE_NL, __LINE__, __FILE__, __FUNCTION__, var);
# define D_STR(var) printf("[l %d] %s:%s() | " #var " : \"%s\"" _DE_NL, __LINE__, __FILE__, __FUNCTION__, var);
# define D_PTR(var) printf"[l %d] %s:%s() | " #var " : <%p>" _DE_NL, __LINE__, __FILE__, __FUNCTION__, var);

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
