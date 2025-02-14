/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_out_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarie <tmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 08:30:20 by abrin             #+#    #+#             */
/*   Updated: 2023/08/15 03:18:09 by tmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	search_in_avance(t_data *data)
{
	data->add = 0;
	while (data->token[data->token_y][0] != '|')
	{
		data->add++;
		data->token_y++;
	}
	data->count_pipe--;
	data->token_y++;
	data->add++;
}

void	dup2_search_in_pipe(t_data	*data, int *pipe_sio, int *fd_pipe)
{
	close(pipe_sio[1]);
	close(fd_pipe[0]);
	dup2(pipe_sio[0], 0);
	dup2(fd_pipe[1], 1);
	malloc_args(data);
	init_args(data);
	execute(data);
	close(pipe_sio[0]);
	close(fd_pipe[1]);
	exit(0);
}

void	error_search_in_pipe(t_data *data)
{
	if (command_exist(data) == 0 || command_exist(data) == 1)
		data->error = 0;
	else
		data->error = 130;
}

void	execute_search_in_pipe(t_data *data, int *fd_pipe)
{
	int		pipe_sio[2];
	pid_t	pid;
	pid_t	pid2;
	ssize_t	bytes_read;

	if (check_in_out(data) == -1)
		return ;
	g_condition_error = 42;
	pipe(pipe_sio);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_sio[0]);
		promt_in_out(data, pipe_sio, bytes_read);
		close(pipe_sio[1]);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	if (g_condition_error == 1)
		return ;
	srch_pipe2(data, pid2, pipe_sio, fd_pipe);
}

void	execute_search_in_pipe_end(t_data *data, int *fd_pipe)
{
	int		pipe_sio[2];
	pid_t	pid;
	pid_t	pid2;
	ssize_t	bytes_read;

	if (check_in_out(data) == -1)
		return ;
	g_condition_error = 42;
	pipe(pipe_sio);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_sio[0]);
		promt_in_out(data, pipe_sio, bytes_read);
		close(pipe_sio[1]);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	if (g_condition_error == 1)
		return ;
	srch_end2(data, pid2, pipe_sio, fd_pipe);
}
