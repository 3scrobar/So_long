/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:58:12 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/04 15:35:48 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_if(char **remaining, char **line)
{
	char	*temp;
	char	*newline;

	newline = ft_strchr(*remaining, '\n');
	if (newline)
	{
		*line = ft_substr(*remaining, 0, newline - *remaining + 1);
		temp = ft_strdup(newline + 1);
		free(*remaining);
		*remaining = temp;
	}
	else
	{
		*line = ft_strdup(*remaining);
		free(*remaining);
		*remaining = NULL;
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*remaining = NULL;
	char		buffer[BUFFER_SIZE + 1];
	static char	*line = NULL;
	int			bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(remaining), remaining = NULL, NULL);
		buffer[bytes_read] = 0;
		if (remaining)
			remaining = ft_strjoinfree(&remaining, buffer);
		else
			remaining = ft_strdup(buffer);
		if (ft_strchr(remaining, '\n') || bytes_read == 0)
			break ;
	}
	if ((ft_strlen(remaining)) > 0)
	{
		ft_if(&remaining, &line);
		return (line);
	}
	else
		return (free(remaining), remaining = NULL, line = NULL, NULL);
}

// int main(void)
// {
//     int fd;
//     char *line;

//     // Ouvrir le fichier en lecture
//     fd = open("essai.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Erreur lors de l'ouverture du fichier");
//         return (1);int main(void)
// {
//     int fd;
//     char *line;

//     // Ouvrir le fichier en lecture
//     fd = open("essai.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Erreur lors de l'ouverture du fichier");
//         return (1);
//     }

//     // Lire et afficher chaque ligne
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }

//     // Fermer le fichier
//     close(fd);
//     return (0);
// }
//     }

//     // Lire et afficher chaque ligne
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }

//     // Fermer le fichier
//     close(fd);
//     return (0);
// }
