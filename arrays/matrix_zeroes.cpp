#include<bits/stdc++.h>
using namespace std;


void setZeroes(vector<vector<int>>& matrix) {  //TC =O(M*N*(M+N))
            int m = matrix.size();
        int n = matrix[0].size();
                for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If current cell is zero
                if (matrix[i][j] == 0) {
                    // Mark all elements in this row as -1 (except existing zeros)
                    for (int col = 0; col < n; col++) {
                        if (matrix[i][col] != 0)
                            matrix[i][col] = -1;
                    }
                    // Mark all elements in this column as -1 (except existing zeros)
                    for (int row = 0; row < m; row++) {
                        if (matrix[row][j] != 0)
                            matrix[row][j] = -1;
                    }
                }
            }
        }
                for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }


void setZeroesbetter(vector<vector<int>>& matrix){ //TC=(M*N)
            int m = matrix.size();
        // Get number of columns
        int n = matrix[0].size();

        // Create row marker array
        vector<int> row(m, 0);
        // Create column marker array
        vector<int> col(n, 0);

        // First pass: mark rows and columns that need to be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If element is zero, mark its row and column
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }


        // Second pass: set cells to zero based on markers
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the row or column is marked, set cell to zero
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

void setzeroesoptimal(vector<vector<int>>& matrix){
    int colo =1;
    int m = matrix.size();
    int n = matrix[0].size();

        bool firstrowZero = false;
        bool firstcolumnZero = false;

        // Check if first row contains zero
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) {
                firstrowZero = true;
            }
        }

        // Check if first column contains zero
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                firstcolumnZero = true;
            }
        }

        // Use first row and first column as markers
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {

                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeroes using markers
        for(int i = m - 1; i >= 1; i--) {
            for(int j = n - 1; j >= 1; j--) {

                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstrowZero) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if(firstcolumnZero) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }






int main(){
    int n,m;
    cout<< "Enter no of rows and columns:";
    cin >> n >>m;
        vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix elements:";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    setzeroesoptimal(matrix);

    cout << "Result:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}




