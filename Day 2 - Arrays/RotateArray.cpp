#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N^2)
// Space Complexity: O(1)
void RotateMatrix(vector<vector<int>> &matrix){
    int n = matrix.size(), m = matrix[0].size();
    int temp, copy;

    if(m==1 or n==1) return;

    int it = min(n, m);

    // here we are moving layer by layer.
    for(int i=0; i<it/2; i++){
        temp = matrix[i][i];

        // rotating first row
        for(int j=i; j<m-i-1; j++){
            copy = matrix[i][j+1];
            matrix[i][j+1] = temp;
            temp = copy; 
        }
        
        // rotating last column
        for(int j=i; j<n-i-1; j++){
            copy = matrix[j+1][m-i-1];
            matrix[j+1][m-i-1] = temp;
            temp = copy; 
        }

        // rotating last row
        for(int j=m-i-1; j>i; j--){
            copy = matrix[n-i-1][j-1];
            matrix[n-i-1][j-1] = temp;
            temp = copy;
        }

        // rotating first column
        for(int j=n-i-1; j>i; j--){
            copy = matrix[j-1][i];
            matrix[j-1][i] = temp;
            temp = copy; 
        }
    }

    return;
}
int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {9, 10, 11, 12, 13, 14, 15, 16}
    };

    cout << "hello" << endl;
    RotateMatrix(matrix);
    cout << endl << "there" ;

    for(auto i: matrix){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}


// {5, 5, -9, 3}, 
// {3, -5, -5, 6},
// {8, 5, 10, -10}, 
// {9, -5, -4, 0},
// {10, -8, -6, -7}, 
// {-10, -1, -9, -6},
// {-6, 7, -10, 4}, 
// {4, -2, 8, -8}


// Desired
// 3 5 5 -9 
// 8 5 -5 3 
// 9 -5 -5 6 
// 10 -8 10 -10 
// -10 -1 -4 0 
// -6 7 -6 -7 
// 4 -10 -9 -6 
// -2 8 -8 4

// our o/p
// 3 5 5 -9 
// 8 5 -5 3 
// 9 -5 10 6 
// 10 -5 -4 -10 
// -10 -8 7 0 
// -6 -1 -6 -7 
// 4 -10 -9 -6 
// -2 8 -8 4 
