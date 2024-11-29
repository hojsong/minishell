/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:36:33 by hoslim            #+#    #+#             */
/*   Updated: 2023/02/14 12:33:52 by hoslim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//heredoc 환경변수
//자식 프로세스의 sigign

extern int	g_exit_code;

int	main(int ac, char **av, char **envp)
{
	t_info	*info;

	if (ac != 1)
	{
		write(2, "minishell: ", 12);
		write(2, av[1], ft_strlen(av[1]));
		write(2, ": No such file or directory\n", 29);
		return (127);
	}
	info = init_info(envp);
	if (!info)
		return (error(NULL, "Failed to initailzie\n", -1));
	start_shell(info);
	free_info(info);
	return (0);
}
