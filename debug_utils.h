/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:21:34 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/11 16:05:45 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_UTILS_H
# define DEBUG_UTILS_H

# include <stdio.h>

# ifndef BREAK_PAUSE
#  define BREAK_PAUSE 1
# endif

# define _BR_NOPAUSE printf("[%d]:%s:%s()\n", __LINE__, __FILE__, __FUNCTION__);
# define _BR_PAUSE printf("[%d]:%s:%s()", __LINE__, __FILE__, __FUNCTION__); getchar();

# if BREAK_PAUSE == 0
#  define BR _BR_NOPAUSE
# else
# define BR _BR_PAUSE
#endif

# define BR_(var) _Generic((var),	\
	int		:  printf("[%d]:%s:%s() :" #var " : %d\n", __LINE__, __FILE__, __FUNCTION__, (int)var),	\
	long	:  printf("[%d]:%s:%s() :" #var " : %ld\n", __LINE__, __FILE__, __FUNCTION__, (long)var),	\
	double	:  printf("[%d]:%s:%s() :" #var " : %f\n", __LINE__, __FILE__, __FUNCTION__, (double)var),	\
	float	:  printf("[%d]:%s:%s() :" #var " : %f\n",  __LINE__, __FILE__, __FUNCTION__, (float)var),	\
	default	 : printf("[%d]:%s:%s() :" #var " : %p Other type\n", __LINE__, __FILE__, __FUNCTION__, (void)var))		 		\

# define D_INT(var) printf(#var " : %d\n", var);
# define D_LINT(var) printf(#var " : %ld\n", var);
# define D_DOUB(var) printf(#var " : %f\n", var);

# define D_STR(var) printf(#var " : '%s'\n", var);
# define D_PTR(var) printf(#var " : <%p>\n", var);

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
