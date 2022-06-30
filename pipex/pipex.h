/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakizad <azakizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 05:13:02 by azakizad          #+#    #+#             */
/*   Updated: 2022/06/30 16:04:32 by azakizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_meh {
	char	**all_paths;
	char	*temp;
	char	*path;
	char	*line;
	int		i;
} t_meh;

#include "Libft/libft.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>

int		main(int argc, char *argv[], char *envp[]);
void	cmd1_executer(int *fd, char *argv[], char *envp[]);
void	cmd2_executer(int *fd, char *argv[], char *envp[]);
char	*path_finder(char *cmd, char **envp);
char	*ft_get_line(char *envp[]);
void	ft_error(char *str);

#endif
