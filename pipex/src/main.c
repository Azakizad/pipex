/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakizad <azakizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 05:10:40 by azakizad          #+#    #+#             */
/*   Updated: 2022/06/30 16:16:04 by azakizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		ft_error("wrong amount of arguments");
	if (pipe(fd) < 0)
		ft_error("Error");
	pid1 = fork();
	if (pid1 < 0)
		ft_error("Error");
	if (pid1 == 0)
		cmd1_executer(fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		ft_error("Error");
	if (pid2 == 0)
		cmd2_executer(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
