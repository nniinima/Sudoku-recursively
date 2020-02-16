/**
 * @Author: nniinima
 * @Date:   2020-02-16T15:33:52+02:00
 * @Last modified by:   nniinima
 * @Last modified time: 2020-02-16T23:11:54+02:00
 */



#include "sudoku.h"

int matrix[9][9];

void	ft_sudoku_print(int **matrix)
{
	int x;
	int y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			ft_putchar(matrix[x][y] + '0');
			if (y != 8)
				ft_putchar(' ');
			y += 1;
		}
		ft_putchar('\n');
		x += 1;
	}
}

int ft_check_number(int **matrix, int r, int c, int value)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		if ((matrix[i][c] == value) || (matrix[r][i] == value))
			return (0);
		i += 1;
	}
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (matrix[r - (r % 3) + i][c - (c % 3) + j] == value)
				return (0);
			j += 1;
		}
		i += 1;
	}
	return (1);
}

int ft_backtracking_algorithm(int **matrix, int value)
{
	int i;
	int x;
	int y;

	i = 1;
	x = value / 9;
	y = value % 9;
	if (value == 81)
		return (1);
	if (matrix[x][y] != 0)
		return (ft_backtracking_algorithm(matrix, value + 1));
	while (i < 10)
	{
		if (ft_check_number(matrix, x, y, i))
		{
			matrix[x][y] = i;
			if (ft_backtracking_algorithm(matrix, value + 1))
				return (1);
			else
				matrix[x][y] = 0;
		}
		i += 1;
	}
	return (0);
}

int		**read_numbers(char** argv)
{
	int x;
	int y;
	int** matrix;

	x = 0;
	matrix = (int **)malloc(sizeof(int *) * 9 + 1);
	while (x < 9)
	{
		if (ft_strlen(argv[x]) != 9)
			return (0);
		matrix[x] = (int *)malloc(sizeof(int) * 9 + 1);
		y = 0;
		while (y < 9)
		{
			if (argv[x][y] == '.')
				matrix[x][y] = 0;
			else if (argv[x][y] >= '1' && argv[x][y] <= '9')
				matrix[x][y] = argv[x][y] - '0';
			else
				return (0);
			y += 1;
		}
		x += 1;
	}
	return (matrix);
}

int		main(int argc, char **argv)
{
	int **matrix;

	if (argc == 10)
	{
		matrix = read_numbers(&argv[1]);
		if (!matrix)
			write(1, "Error\n", 6);
		else if (ft_backtracking_algorithm(matrix, 0))
			ft_sudoku_print(matrix);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
