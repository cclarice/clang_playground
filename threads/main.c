/* ************************************************************************** */
/*                                                                            */
/*       ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::  */
/*     :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+: */
/*    +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+  */
/*   +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:   */
/*  +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+           */
/* #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#     */
/*  ######    ######  ############## ###    ### ###   ######    #######       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   main.c                                   cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/28 23:36:59  /  2021/06/28 23:37:00 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void	*thread_func(void *arg)
{
	int i;
	char loc_id;
	char chars[6];

	loc_id = *(char *)arg;
	chars[0] = '\033';
	chars[1] = '[';
	chars[2] = '3';
	chars[3] = loc_id;
	chars[4] = 'm';
	chars[5] = loc_id;
	i = 0;
	while (i < 0xffff)
	{
		write(1, chars, 6);
		//usleep(loc_id);
		i++;
	}
	pthread_exit(NULL);
}

int	main(void)
{
	char		id[8];
	pthread_t 	thread[8];
	int			ptr;

	ptr = 0;
	write(1, "\033[1m", 4);
	while (ptr < 1)
	{
		id[ptr] = ptr + '0';
		pthread_create(&thread[ptr], NULL, thread_func, &id[ptr]);
		ptr++;
	}
	ptr = 0;
	while (ptr < 1)
		//pthread_join(thread[ptr++], NULL);
	usleep(1000000);
	write(1,"\nDone\n", 6);
	return (0);
}
