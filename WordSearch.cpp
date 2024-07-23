#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(char book[][4], string search, int r, int c, int x, int y, int index) 
{
    if (x >= 0 && x < r && y >= 0 && y < c  && book[x][y] == search[index]) 
	{
        return true;
    }
    return false;
}

void Solve(char book[][4], string search, int r, int c, int x, int y, int index, string& temp) 
{
    temp.push_back(book[x][y]);
    if (temp.length() == search.length() && temp == search) 
	{
        cout << "Found !!" << endl;
        exit(0);
        return;
    }


    char ch = book[x][y];
    
    if (isSafe(book, search, r, c, x + 1, y, index + 1)) 
	{
        Solve(book, search, r, c, x + 1, y, index + 1, temp);
    }
    if (isSafe(book, search, r, c, x, y - 1, index + 1)) 
	{
        Solve(book, search, r, c, x, y - 1, index + 1, temp);
    }
    if (isSafe(book, search, r, c, x, y + 1, index + 1)) 
	{
        Solve(book, search, r, c, x, y + 1, index + 1, temp);
    }
    if (isSafe(book, search, r, c, x - 1, y, index + 1)) 
	{
        Solve(book, search, r, c, x - 1, y, index + 1, temp);  
    }

    book[x][y] = ch;
     temp.pop_back();

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r = 4, c = 4;
    char book[4][4] = 
	{
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'i', 'j', 'k', 'l'},
        {'m', 'n', 'f', 'p'}
    };
    string search = "lkjfb";
  
    

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (search[0] == book[i][j]) 
			{
                string temp;
                Solve(book, search, r, c, i, j, 0, temp);
            }
        }
    }
    cout << "Not Foud";
    

    return 0;