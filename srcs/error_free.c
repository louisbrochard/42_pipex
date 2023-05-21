/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:59:18 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/20 11:01:10 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

int	error_input(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	error_p(char *err)
{
	perror(err);
	exit (1);
}
