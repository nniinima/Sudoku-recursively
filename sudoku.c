#include <stdio.h>

//global sudoku problem
int g_matrix[9][9] = {
    {6,5,0,8,7,3,0,9,0},
    {0,0,3,2,5,0,0,0,8},
    {9,8,0,1,0,4,3,5,7},
    {1,0,5,0,0,0,0,0,0},
    {4,0,0,0,0,0,0,0,2},
    {0,0,0,0,0,0,5,0,3},
    {5,7,8,3,0,1,0,2,6},
    {2,0,0,0,4,8,9,0,0},
    {0,9,0,6,2,5,0,8,1}
};

//Sudoku printer suite
void ft_sudoku_print()
{
    int i;
    int j;

    i = 0;
    while (i < 9)
    {
        j = 0;
        while (j < 9)
        {
            printf("%d ",g_matrix[i][j]);
            j++;
        }
        printf("\n");
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

int main()
{
    if (ft_backtracking_algorithm())
        ft_sudoku_print();
    else
        printf("No solution\n");
    return 0;
}
