//#include<iostream>
using namespace std;
//
//class JaggedArray
//{
//	private:
//		int** jagged;
//		int rows;
//	public:
//		JaggedArray(int row)
//		{
//			this->rows = row;
//			jagged = new int*[row];
//		}		
//		void input()
//		{
//			for(int i=0 ; i<rows ; i++)
//			{
//				int cols;
//				cout << "Enter number of columns for row : " << i+1 << endl;
//				cin >> cols;
//				jagged[i] = new int[cols];
//				cout << "Enter values : " << endl;
//				for(int j=0 ; j<cols ; j++)
//				{
//					cin >> jagged[i][j];
//				}
//			}
//		}
//		void display()
//		{
//			for(int i=0 ; i<rows ; i++)
//			{
//				for(int j=0 ; j<rows ; j++)
//				{
//					cout << jagged[i][j] <<  "  ";
//				}
//				cout << endl;
//			}
//		}
//		~JaggedArray()
//		{
//			for(int i=0 ; i<rows ; i++)
//			{
//				delete[] jagged[i];
//			}
//			delete[] jagged;
//		}
//};
//
//int main()
//{
//	cout << "Enter number of rows : ";
//	int row;
//	cin >> row;
//	JaggedArray j(row);
//	j.input();
//	j.display();
//	j.~JaggedArray();
//}

#include <iostream>

int main() {
    int numRows;
    std::cout << "Enter the number of rows: ";
    std::cin >> numRows;

    // Create a jagged array
    int** jaggedArray = new int*[numRows];

    // Initialize each row
    for (int i = 0; i < numRows; i++) {
        int numCols;
        std::cout << "Enter the number of columns for row " << i << ": ";
        std::cin >> numCols;

        jaggedArray[i] = new int[numCols];

        std::cout << "Enter values for row " << i << ":" << std::endl;
        for (int j = 0; j < numCols; j++) {
            std::cin >> jaggedArray[i][j];
        }
    }

    // Access and print the elements
    std::cout << "Jagged Array values:" << std::endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows; j++) {
            std::cout << jaggedArray[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate memory
    for (int i = 0; i < numRows; i++) {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;

    return 0;
}
