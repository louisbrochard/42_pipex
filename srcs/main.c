/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:09:03 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/18 09:20:41 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main (int argc, char **argv, char **envp)
{
    t_pipex pipex;

    if (argc != 5)
        return (error_input("Error: wrong number of arguments\n"));
    pipex.infile = open(argv[1], O_RDONLY);
    if (pipex.infile < 0)
        error_p("Error: input file\n");
    pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
    if (pipex.outfile < 0)
        error_p("Error: output file\n");
    if(pipe(pipex.tube) < 0)
        error_p("Error : pipe\n");
    pipex.path = get_path(envp);
    pipex.cmd_paths = ft_split(pipex.path, ':');
    printf("Tout roule là \n");
    
    return (0);
}