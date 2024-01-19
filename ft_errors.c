/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:35:08 by rrimonte          #+#    #+#             */
/*   Updated: 2024/01/11 12:04:09 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_check_arguments(int argc, char **argv, int bmode)
{
	if (bmode == 0)
	{
		if (argc < 5 || argc > 6 || (ft_atoi(argv[1])) <= 0)
		{
			if (argc < 5 || argc > 6)
				printf("invalid number of arguments\n");
			else if ((ft_atoi(argv[1])) <= 0)
				printf("number of philosophers incorrect\n");
			exit (1);
		}
	}
	else
	{
		printf("invalid arguments\n");
		exit(1);
	}
}
