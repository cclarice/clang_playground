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
/*   Created/Updated: 2021/06/25 01:34:17  /  2021/06/25 01:34:43 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void	*thread_func(void *arg)
{
	int i;
	int loc_id;

	loc_id = *(int *)arg;
	i = 0;
	while (i < 4)
	{
		printf("Thread %i is running\n", loc_id);
		sleep(1);
		i++;
	}
	pthread_exit(NULL);
}

int	main(void)
{
	int id1;
	int id2;
	int result;
	pthread_t thread1;
	pthread_t thread2;

	id1 = 1;
	result = pthread_create(&thread1, NULL, thread_func, &id1);
	if (result != 0)
		return (write(2, "Creating the first  thread\n", 27));
	id2 = 2;
	result = pthread_create(&thread2, NULL, thread_func, &id2);
	if (result != 0)
		return (write(2, "Creating the first  thread\n", 27));
	result = pthread_join(thread1, NULL);
	if (result != 0)
		return (write(2, "Joining the first  thread\n", 26));
	result = pthread_join(thread2, NULL);
	if (result != 0)
		return (write(2, "Joining the second thread\n", 26));
	printf("Done\n");
}
