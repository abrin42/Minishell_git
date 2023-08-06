#include "../minishell.h"

void ft_putstr_error(t_data *data, char *str)
{
	int	len;

	data->error = 127;
	len = 0;
	while (str[len] != '\0')
		len++;
	write(2, str, len);
	write(2, ": command not found\n", 20);
}

char	*ft_strjoin2(char *s1, char *s2, t_data *data)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = gc_malloc(&data->gc, (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	//gc_free(&data->gc, s1);
	return (str);
}

char    *ft_strjoin(char *s1, char *s2, t_data *data)
{
    size_t    i;
    size_t    c;
    char    *str;

    if (!s1)
    {
        s1 = gc_malloc(&data->gc, 1 * sizeof(char));
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    str = gc_malloc(&data->gc, (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    i = -1;
    c = 0;
    if (s1)
        while (s1[++i] != '\0')
            str[i] = s1[i];
    while (s2[c] != '\0')
        str[i++] = s2[c++];
    str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    return (str);
}

char    *ft_strjoin3(char *s1, char *s2, t_data *data, int p)
{
    size_t    i;
    size_t    c;
    char    *str;
    if (!s1)
    {
        s1 = gc_malloc(&data->gc, 1 * sizeof(char));
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
	while (data->buffer[p] != '\0' && data->buffer[p] != ' ')
                p++;
    while (data->buffer[p] != '/')
        p--;
	p++;
    i = -1;
    c = 0;
    if (s1)
        while (s1[++i] != '\0')
            str[i] = s1[i];
    while (s2[p] != '\0' && s2[p] != ' ')
        str[i++] = s2[p++];
    str[i] = '\0';
    return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] != '\0')
		{
			if (s2[i] == '\0')
			{
				return (s1[i] - s2[i]);
			}
			else
			{
				i++;
			}
		}
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			return (0);
		}
	}
	return (s1[i] - s2[i]);
}

int	ft_strcmp2(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] != '\0')
		{
			if (s2[i] == '\0')
			{
				return (s1[i] - s2[i]);
			}
			else
			{
				i++;
			}
		}
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			return (0);
		}
	}
	if (s1[i] == ' ')
		return (0);
	return (s1[i] - s2[i]);
}
