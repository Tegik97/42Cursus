#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			len;

	if (!s)
		return ;
	ptr = (unsigned char *)s;
	len = 0;
	while (len < n)
	{
		ptr[len] = '\0';
		len++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

int	ft_linelen(const char *str)
{
	size_t	nchar;

	nchar = 1;
	while (*str && *str != '\n')
	{
		str++;
		nchar++;
	}
	return (nchar);
}
