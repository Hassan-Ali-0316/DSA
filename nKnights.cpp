#include<iostream>
using namespace std;                                      // crashing on maze > 7

bool isSafe(int row, int col, int **Board, int n) 
{
    int x,y;
    x = row - 2;
    y = col + 1;
    if (x >= 0 && y >= 0 && x < n && y < n && Board[x][y] == 1) 
	{
        return false;
    }

    x = row - 2;
    y = col - 1;
    if (x >= 0 && y >= 0 && x < n && y < n && Board[x][y] == 1) 
	{
        return false;
    }

    x = row - 1;
    y = col + 2;
    if (x >= 0 && y >= 0 && x < n && y < n && Board[x][y] == 1) 
	{
        return false;
    }

    x = row - 1;
    y = col - 2;
    if (x >= 0 && y >= 0 && x < n && y < n && Board[x][y] == 1) 
	{
        return false;
    }
    
    return true;
}


bool Solve(int** board, int n, int x, int y, int& Knights) 
{
    if (Knights == 0) 
	{
        return true; 
    }

    for (int i = x; i < n; i++) 
	{
        for (int j = (i == x) ? y : 0; j < n; j++) 
		{
            if (isSafe(i, j, board, n)) 
			{
                board[i][j] = 1;
                Knights--;
                if (Solve(board, n, i, j + 1, Knights)) 
				{
                    return true; 
                }

                board[i][j] = 0;
                Knights++;
            }
        }
    }
    return false; 
}
int main()
{
	int s = 5;
	int **board = new int *[s];
	for(int i = 0 ; i < s ; i++)
	{
	    board[i] = new int[s];
	}
	for(int i = 0; i < s ; i++)
	{
	    for(int j=0 ; j < s ; j++)
		{
	        board[i][j] = 0;
	    }
	}
	int knights = 0;
	if(s%2 == 0)
	{
		knights = ((s*s)/2);
	}
	else
	{
		knights = ((s*s+1)/2);
	}
	Solve(board,s,0,0,knights);
	 	
	for(int i = 0; i < s ; i++)
	{
	    for(int j=0 ; j < s ; j++)
		{
	        cout << board[i][j] << "   ";
	    }
	    cout << endl;
	} 
}