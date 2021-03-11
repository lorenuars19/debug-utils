/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:21:34 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/10 23:07:46 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_UTILS_H
# define DEBUG_UTILS_H

# include <stdio.h>

# ifndef BREAK_PAUSE
#  define BREAK_PAUSE 1
# endif

# define _BR_NOPAUSE printf("[%d]:%s:%s()", __LINE__, __FILE__, __FUNCTION__);
# define _BR_PAUSE printf("[%d]:%s:%s()", __LINE__, __FILE__, __FUNCTION__); getchar();

# if BREAK_PAUSE == 0
#  define BR _BR_NOPAUSE
# else
# define BR _BR_PAUSE
#endif

# define D_INT(var) printf(#var " : %d\n", var);
# define D_LINT(var) printf(#var " : %ld\n", var);
# define D_DOUB(var) printf(#var " : %f\n", var);

# define D_STR(var) printf(#var " : '%s'\n", var);
# define D_PTR(var) printf(#var " : <%p>\n", var);

#define D_STR_DETAILS(str) print_str_details(strlen(str), str, #str)

# define DEBUG(var) _Generic((var),	\
	int		:  printf(#var " : %d\n", (int)var),	\
	long	:  printf(#var " : %ld\n",(long)var),	\
	double	:  printf(#var " : %f\n", (double)var),	\
	float	:  printf(#var " : %f\n", (float)var),	\
	default	 : printf(#var " : Hi"))		 		\

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
