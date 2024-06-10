#include "libft.h"

char	*ft_stringlcopy(char *dst, const char *src, size_t size)
{
	size_t	offset;

	if (!src || !size)
		return (NULL);
	dst = ft_calloc((ft_strlen(src) + 1), sizeof(char));
	offset = 0;
	while (*(src + offset) != '\0' && offset < (size - 1))
	{
		*(dst + offset) = *(src + offset);
		offset++;
	}
	*(dst + offset) = '\0';
	return (dst);
}
