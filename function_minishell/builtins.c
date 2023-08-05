#include "../minishell.h"

void    ft_echo(t_data *data)
{
    int    condition;
    condition = 0;
    data->token_y++;
    if (ft_strcmp(data->token[data->token_y], "-n") == 0)
    {
        condition = 1;
        data->token_y++;
    }
    else if (ft_strcmp(data->token[data->token_y], "$?") == 0)
    {
        printf("%d\n", data->error);
        data->error = 0;
        return ;
    }
    while (data->token[data->token_y][0] != '\0' && !ft_is_operator(data->token[data->token_y][0]))
    {
        ft_putstr(data->token[data->token_y]);
        write(1, " ", 1);
        data->token_y++;
    }
    if (condition == 0)
        write(1, "\n", 1);
}

void    ft_pwd(t_data *data)
{
    char    *pwd;

    if (!ft_is_operator(data->token[data->token_y + 1][0]) && data->token[data->token_y + 1][0] != '\0')
    {
        printf("Too many arguments for pwd\n");
        return ;
    }
    pwd = gc_malloc(&data->gc, sizeof(char) * 1024);
    getcwd(pwd, 1024);
    ft_putstr(pwd);
    ft_putchar('\n');
}

void ft_cd(t_data *data)
{
    data->token_y++;
    if (!ft_is_operator(data->token[data->token_y + 1][0]) && data->token[data->token_y + 1][0] != '\0')
    {
        printf("Too many arguments for cd\n");
        return ;
    }
    chdir(data->token[data->token_y]);
}

void    ft_env(t_data *data)
{
    int i;

    i = 0;
    while (data->env[i])
        printf("%s\n", data->env[i++]);
}

void    ft_exit(t_data *data)
{
    gc_clean(&data->gc);
    exit (0);
}
