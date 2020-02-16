/**
 * @Author: nniinima
 * @Date:   2020-02-16T15:38:13+02:00
 * @Last modified by:   nniinima
 * @Last modified time: 2020-02-16T15:39:14+02:00
 */



#include <unistd.h>
#include <stdio.h>
int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		i2;
	int		cre_int[9][9];
	char	line[9][9];
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			line[i - 1][j] = argv[i][j];
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	i2 = 0;
	while (i2 < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (line[i2][j] == '.')
			{
				cre_int[i2][j] = 0;
			}
			else
			{
				cre_int[i2][j] = (line[i2][j] - '0');
			}
			j++;
		}
		i2++;
	}
	i2 = 0;
	while (i2 < 9)
	{
		j = 0;
		while (j < 9)
		{
			printf("%d ", cre_int[i2][j]);
			j++;
		}
		printf("\n");
		i2++;
	}
	return (0);
}
