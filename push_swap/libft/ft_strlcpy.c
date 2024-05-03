/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:15:19 by mchiaram          #+#    #+#             */
/*   Updated: 2024/05/03 18:39:18 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char **dst, const char *src)
{
	size_t	offset;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst || !src)
		return (srclen);
	offset = 0;
	dst[offset] = ft_calloc((srclen + 1), sizeof(char));
	while (src[offset] != '\0')
	{
		(*dst)[offset] = src[offset];
		offset++;
	}
	return (srclen);
}

/*int	main(int argc, char *argv[])
{
	char		*dst;
	size_t		result;

	dst = argv[1];
	if (argc == 4)
	{
		printf("Dst string before: %s\n", dst);
		printf("Src string to be copied in dst: %s\n", argv[2]);
		printf("Size to be copied: %s\n\n", argv[3]);
		result = ft_strlcpy(dst, argv[2], ft_atoi(argv[3]));
		printf("New dst string: %s\n", dst);
		printf("Lenght of the string I tried to create: %ld\n", result);
	}
	return (0);
}*/
/*				---MAN DESCRIPTION---
	The strlcpy() function copies strings.

	It's designed to be safer, more consistent,
	and less error prone replacement for strncpy(3).

	Unlike that function, strlcpy() takes the full size of the buffer
	(not just the length) and guarantees to NUL-terminate the result
	(as long as size is larger than 0).
	
	Note that a byte for the NUL should be included in size.
	Also note that strlcpy() only operates on true “C” strings.
	This means that src must be NUL-terminated.

    The strlcpy() function copies up to size - 1 characters from
	the NUL-terminated string src to dst, NUL-terminating the result.

	---RETURN VALUES---
    The strlcpy() function returns the total length of
	the string it tried to create.
	 
	For strlcpy() that means the length of src.
 */