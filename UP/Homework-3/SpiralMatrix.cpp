#include <iostream>

using namespace std;

int main()
{

    //initialize matrix
    int n;
    cin >> n;
    int matrix[n][n];
    int index = 1;

    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            matrix[row][col] = index;
            index++;
        }
    }

   // Initialize directions
     int top = 0;
     int down = n - 1;
     int left = 0;
     int right = n - 1;

     while(true)
     {
         // Print top row
         for(int j = left; j <= right; ++j)
            {
                cout << matrix[top][j] << " ";
            }
         top++;
         if(top > down || left > right)
         {
            break;
         }

         //Print the rightmost column
         for(int i = top; i <= down; ++i)
         {
             cout << matrix[i][right] << " ";
         }
            right--;
         if(top > down || left > right)
         {
             break;
         }

         //Print the bottom row
         for(int j = right; j >= left; --j)
         {
             cout << matrix[down][j] << " ";
         }
            down--;
         if(top > down || left > right)
         {
             break;
         }

         //Print the leftmost column
         for(int i = down; i >= top; --i)
         {
             cout << matrix[i][left] << " ";
         }
            left++;
         if(top > down || left > right)
         {
             break;
         }
     }

    return 0;
}
