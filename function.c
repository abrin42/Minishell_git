#include "minishell.h"

void ft_putchar(char c)
{
    write(1, &c,1);
}

void ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(1, str, len);
}

int ft_strlen(char  *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int	ft_strcmp2(char *s1, char *s2, int start)
{
	int	i;
	int	u;
    int g;

	u = 0;
	i = 0;
    g = 0;
    while (start != 0)
    {
        i++;
        start--;
    }
    while (ft_strlen(s2) > g)
	{
		if (s2[g] == s1[i])
			u++;
		if (s2[g] != '\0')
		{
			if (u == ft_strlen(s2))
				return (1);
		}
		i++;
        g++;
	}
	return (0);
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

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dst;
	int		len;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	dst = malloc (sizeof(char) * len + 1);
	if (dst == 0)
		return (NULL);
	while (s[i] && s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char    *ft_strjoin(char *s1, char *s2)
{
    size_t    i;
    size_t    c;
    char    *str;

    if (!s1)
    {
        s1 = (char *)malloc(1 * sizeof(char));
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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