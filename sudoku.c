/**
 * @Author: nniinima
 * @Date:   2020-02-16T15:33:52+02:00
 * @Last modified by:   nniinima
 * @Last modified time: 2020-02-16T22:03:07+02:00
 */

#include "sudoku.h"

//global sudoku problem


int g_matrix[9][9] = {
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
};

/**
 * @Author: nniinima
 * @Date:   2020-02-16T15:38:13+02:00
 * @Last modified by:   nniinima
 * @Last modified time: 2020-02-16T22:03:07+02:00
 */




//Sudoku printer suite
void ft_sudoku_print()
{
	int i;
	int n;
	int result_matrix[9][9];

		i=0;
		while(i<9)
		{
			n=0;
			while(n<9)
			{
				result_matrix[i][n] = (g_matrix[i][n] + '0');
				n++;
			}
			i++;
		}
		i = 0;
		while(i < 9)
		{
			n= 0;
			while (n < 9)
			{
				write(1,&result_matrix[i][n],1);
				n++;
			}
			write(1, "\n", 1);
			i++;
		}
}

//here we check if the cells are assigned or not//
int ft_cell_unassigned(int *row, int *col)
{
    int num_unassign = 0;
    int i;
    int j;

    i = 0;
    while (i < 9)
    {
        j = 0;
        while (j < 9)
        {
            //cell is unassigned
            if(g_matrix[i][j] == 0)
            {
                //changing the values of row and col
                *row = i;
                *col = j;
                //there is one or more unassigned cells
                num_unassign = 1;
                return num_unassign;
            }
            j++;
        }
        i++;
    }
    return num_unassign;
}

//number checker, can we assign a particular number or not?
int ft_check_number(int n, int r, int c)
{
    int i;
    int j;
    int row_start;
    int col_start;

    i = 0;
    while (i < 9)
    {
        //there is a cell with same value
        if(g_matrix[r][i] == n)
            return 0;
        i++;
    }
    //checking column
    i = 0;
    while (i < 9)
    {
        //there is a cell with the value equal to i
        if(g_matrix[i][c] == n)
            return 0;
        i++;
    }
    //checking sub g_matrix
    row_start = (r/3)*3;
    col_start = (c/3)*3;

    i = row_start;
    while (i < row_start + 3)
    {
        j = col_start;
        while(j < col_start + 3)
        {
            if(g_matrix[i][j]==n)
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

//function to solve sudoku
//using backtracking
int ft_backtracking_algorithm()
{
    int n;
    int i;
    int row;
    int col;
    //if all cells are assigned then the sudoku is already solved
    //pass by reference because ft_cell_unassigned will change the values of row and col
    if(ft_cell_unassigned(&row, &col) == 0)
        return 1;
    //number between 1 to 9
    i = 1;
    while (i <= 9)
    {
        //if we can assign i to the cell or not
        //the cell is g_matrix[row][col]
        if(ft_check_number(i, row, col))
        {
            g_matrix[row][col] = i;
            //backtracking
            if(ft_backtracking_algorithm())
                return 1;
            //if we can't proceed with this solution
            //reassign the cell
            g_matrix[row][col]=0;
        }
        i++;
    }
    return 0;
}

int main(int argc, char* argv[])
{
	int		i;
	int		j;
	int		i2;
	char	line[9][9];
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			line[i - 1][j] = argv[i][j];
			j++;
		}
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
				g_matrix[i2][j] = 0;
			}
			else
			{
				g_matrix[i2][j] = (line[i2][j] - '0');
			}
			j++;
		}
		i2++;
	}
    if (ft_backtracking_algorithm())
        ft_sudoku_print();
    else
        write(1, "No solution\n", 15);
    return 0;
}
