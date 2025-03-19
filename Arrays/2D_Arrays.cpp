#include <bits/stdc++.h>
using namespace std;

// Function to print the matrix
void Matrix_Print(const vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (auto& element : row) 
            cout << element << " ";
        cout << endl;
    }
}

bool Linear_Search(const vector<vector<int>>& matrix, int key) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (matrix[i][j] == key) return true;
        }
    }
    return false;
}

bool Binary_Search(const vector<vector<int>>& matrix, int key) {
    if (matrix.empty())
      return false;

    const int m = matrix.size();
    const int n = matrix[0].size();
    int l = 0;
    int r = m * n;

    while (l < r) {
      const int mid = (l + r) / 2;
      const int i = mid / n;
      const int j = mid % n;
      if (matrix[i][j] == target)
        return true;
      if (matrix[i][j] < target)
        l = mid + 1;
      else
        r = mid;
    }

    return false;
}


void Spiral_Print(const vector<vector<int>>& matrix, int rows, int cols) {
    int startingRow = 0;
    int endingRow = rows - 1;
    int startingCol = 0;
    int endingCol = cols - 1;

    while(startingCol <= endingCol and startingRow <= endingRow){
            // Strating Row
            for (int col = startingCol; col <= endingCol; col++){
                cout<<matrix[startingRow][col]<<" ";
            }

            // Ending Column
            for (int row = startingRow + 1; row <= endingRow; row++){
                cout<<matrix[row][endingCol]<<" ";
            }

            // Ending Row
            for (int col = endingCol - 1; col >= startingCol; col--){
                if (startingRow == endingRow) break;
                cout<<matrix[endingRow][col]<<" ";
            }

            // Starting Column
            for (int row = endingRow - 1; row >= startingRow + 1; row--){
                if (startingCol == endingCol) break;
                cout<<matrix[row][startingCol]<<" ";
            }
            // Update the variables
             startingRow++;
             endingRow--;
             startingCol++;
             endingCol--;

    }
    cout<<endl;
}

void Wave_Print(const vector<vector<int>>& matrix, int nrows, int mcols){
    for (int col = 0; col < mcols; col++){
        if (col % 2 == 0){
            for (int row = 0; row<nrows; row++){
                cout<<matrix[row][col]<<" ";
            }
            // cout<<endl;
        }
        else
        {
            for (int row = nrows-1; row>=0; row--){
                cout<<matrix[row][col]<<" ";
            }
            // cout<<endl;
        }
    }
}

// Function to calculate and print the sum of each row
void Row_Sum(const vector<vector<int>>& matrix, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        cout << "Sum for Row No: " << i + 1 << " is " << sum << endl;
        sum = 0;
    }
}

// Function to calculate and print the sum of each column
void Col_Sum(const vector<vector<int>>& matrix, int rows, int cols) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        cout << "Sum for Column No " << j + 1 << " is: " << sum << endl;
        sum = 0;
    }
}

int main() {
    // Define the matrix directly
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9, 8, 7}
    };

    // Calculate rows and columns from the matrix
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Print the matrix
    cout << "Matrix:" << endl;
    Matrix_Print(matrix);

    // Print the matrix in Wave Pattern
    cout << "Wave Print:" << endl;
    Wave_Print(matrix, rows, cols);
    cout << endl;

    // Print the matrix in Spiral Pattern
    cout << "Spiral Print:" << endl;
    Spiral_Print(matrix, rows, cols);

    // Test the linear search of the matrix
    cout<<"Linear Search:"<< endl;
    cout<<Linear_Search(matrix, 150)<<endl;

    return 0;
}

