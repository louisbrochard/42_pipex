/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:27:15 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/18 08:35:47 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int    error_input(char *err)
{
    write(2, err, ft_strlen(err));
    return (1);
}

void   error_p(char *err)
{
    perror(err);
    exit (1);
}