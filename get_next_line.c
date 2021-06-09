/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:04:50 by abensett          #+#    #+#             */
/*   Updated: 2021/06/09 18:31:59 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUF_SIZE 4096



int main(void)
{

	int fd;
	int txt;
	char buf[BUF_SIZE + 1];
	
	fd = open("extrait.txt",O_RDONLY); /* RETURN  AN INT THAT IS LINKED TO A FILE*/
	if (fd == -1)
	{
		printf(("open() error"));
		return(-1);
	}
	txt = read(fd, buf, BUF_SIZE);	/* RETURN : -1 = ERROR     INT = NB OF OCTETS*/
	if (txt == -1)
		return  (-1);
	buf[txt] = '\0';
	printf("%s",buf);

	return(0);
}

