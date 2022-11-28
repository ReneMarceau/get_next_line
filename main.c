/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:54:10 by rmarceau          #+#    #+#             */
/*   Updated: 2022/11/28 12:35:07 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

/*
No Bonus

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
*/
//---------------------------------------------------
/*
//With Bonus

int	main(void)
{
	char *ptr;
	int fd;
	int fd1;
	int fd2;

	fd = open("text.txt", O_RDONLY);
	fd1 = open("text2.txt", O_RDONLY);

	fd2 = fd;
	while ((ptr = get_next_line(fd2)))
	{
		if (fd2 == fd1)
			fd2 = fd;
		else
			fd2 = fd1;
		printf("%s", ptr);
		free(ptr);
	}
	return (0);
}
*/
