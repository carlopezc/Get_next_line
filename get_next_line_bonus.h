
//Header

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*get_next_line(int fd);
void	ft_free(char **str, char **str2);
char	*ft_strjoin(char *str, char *str2);
int		ft_strlen(char *str);
int		ft_search_nl(char *str);

#endif
