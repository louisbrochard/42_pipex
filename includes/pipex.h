/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:10:12 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/18 09:24:07 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipex
{
    char    **cmd;
    char    **cmd_args;
    char    **cmd_paths;
    char    *path;
    int     infile;
    int     outfile;
    int     tube[2];
}t_pipex;

// main.c

// ft_split.c
char	**ft_split(const char *str, char c);

//utils.c
char    *get_path(char **envp);
int	ft_strncmp(const char *first, const char *second, size_t length);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);

//error.c
void   error_p(char *err);
int    error_input(char *err);


#endif