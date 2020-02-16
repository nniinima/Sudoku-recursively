/**
 * @Author: nniinima
 * @Date:   2020-02-16T23:10:21+02:00
 * @Last modified by:   nniinima
 * @Last modified time: 2020-02-16T23:14:26+02:00
 */

#include "sudoku.h"

 void	ft_putchar(char c)
 {
 	write(1, &c, 1);
 }

 int	ft_strlen(char *str)
 {
 	int i;

 	i = 0;
 	while (str[i])
 		i += 1;
 	return (i);
 }
