/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakizad <azakizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:14:04 by azakizad          #+#    #+#             */
/*   Updated: 2022/06/30 16:15:44 by azakizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_finder(char *cmd, char **envp)
{
	t_meh	a;

	a.line = ft_get_line(envp);
	if (a.line == NULL)
		a.line = ".";
	a.all_paths = ft_split(a.line + 5, ':');
	a.i = 0;
	if (ft_strchr(cmd, '/') != 0)
		return (ft_strdup(cmd));
	while (a.all_paths[a.i])
	{
		a.temp = ft_strjoin(a.all_paths[a.i], "/");
		a.path = ft_strjoin(a.temp, cmd);
		free(a.temp);
		if (access(a.path, F_OK | X_OK) == 0)
			return (a.path);
		free(a.path);
		a.i++;
	}
	free(a.all_paths);
	free(cmd);
	return (cmd);
}

void	cmd1_executer(int *fd, char *argv[], char *envp[])
{
	int		fd_in;
	char	**tmp;
	char	*path;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		ft_error("Error");
	dup2(fd_in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fd_in);
	tmp = ft_split(argv[2], ' ');
	path = path_finder(tmp[0], envp);
	if (execve(path, tmp, envp) == -1)
		ft_error("Error");
	free(tmp);
}

void	cmd2_executer(int *fd, char *argv[], char *envp[])
{
	int		fd_out;
	char	**tmp;

	fd_out = open(argv[4], O_WRONLY | O_TRUNC
			| O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_out < 0)
		ft_error("Error");
	dup2(fd_out, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	tmp = ft_split(argv[3], ' ');
	if (execve(path_finder(tmp[0], envp), tmp, envp) == -1)
		ft_error("Error");
	free(tmp);
}

char	*ft_get_line(char *envp[])
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnstr(envp[i], "PATH=", 5);
	while (str == 0 && envp[i] != NULL)
	{
		str = ft_strnstr(envp[i], "PATH=", 5);
		i++;
	}
	return (str);
}

void	ft_error(char *str)
{
	perror(str);
	exit(0);
}
