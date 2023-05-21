/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:10:12 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/20 11:11:16 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
	char	**cmd_args;
	char	**cmd_paths;
	char	*path;
	int		infile;
	int		outfile;
	int		tube[2];
}		t_pipex;

// main.c

// ft_split.c
char	**ft_split(const char *str, char c);

//utils.c
char	*get_path(char **envp);
int		ft_strncmp(const char *first, const char *second, size_t length);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);

//error&free.c
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
void	error_p(char *err);
int		error_input(char *err);

//child.c
void	second_child(t_pipex pipex, char *argv[], char *envp[]);
void	first_child(t_pipex pipex, char *argv[], char *envp[]);

//utils2.c
char	*ft_strjoin(char const *s1, char const *s2);

#endif
