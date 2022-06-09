#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Time Complexity: O(N*M) * O((N+M)*(N*M)) -- first term for traversal, second one is for making elements to -1.
void BruteForce(vector<vector<int>> &matrix){
    int n = matrix.size(), m = matrix[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==0){
                // changing cells above current cell (in column).
                int ind = i-1;
                while(ind >= 0){
                    if(matrix[ind][j]!=0){
                        matrix[ind][j] = -1;
                    }
                    ind--;
                }

                // changing cells below current cell (in column).
                ind = i+1;
                while(ind < n){
                    if(matrix[ind][j]!=0){
                        matrix[ind][j] = -1;
                    }
                    ind++;
                }

                // changing cells before current cell (in row).
                ind = j-1;
                while(ind >= 0){
                    if(matrix[i][ind]!=0){
                        matrix[i][ind] = -1;
                    }
                    ind--;
                }

                // changing cells after current cell (in row).
                ind = j+1;
                while(ind < m){
                    if(matrix[i][ind]!=0){
                        matrix[i][ind] = -1;
                    }
                    ind++;
                }
            }
        }
    }

    // making zeros.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==-1)
                matrix[i][j] = 0;
        }
    }

    return;
}

// Time Complexity: O(N^2)
// Space Complexity: O(No. of Zeros in given Matrix)
void SetMatrixZeros(vector<vector<int>> &matrix){

    // storing all coordinates having zero in given matrix.
    int n = matrix.size(), m = matrix[0].size();
    vector<pair<int, int>> coords;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==0){
                coords.push_back({i, j});
            }
        }
    }

    // for each coordinate we are making the columns and rows 0.
    for(auto coord: coords){
        for(int i=0; i<m; i++){
            matrix[coord.first][i] = 0; 
        }
        for(int i=0; i<n; i++){
            matrix[i][coord.second] = 0; 
        }
    }

    return;
}

// Time Complexity: O(2*M*N)
// Space Complexity: O(1)
// In this solution we are using 1st row and 1st col instead of storing coordinates of elements that are zero.
// This helps in reducing the space complexity.
void setZeros(vector<vector<int>> &matrix){
    int n = matrix.size(), m = matrix[0].size(), col0=1;
    for(int i=0; i<n; i++){
        // col0 is used to check if afterwards whole column 0 needs to be set to 0 or not.
        if(matrix[i][0]==0) col0=0;
        for(int j=1; j<m; j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Here we will make elements 0 based on the first row and first columns and hence we are traversing in reverse so that
    // elements of 1st row and 1st column gets updated in last.
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=1; j--){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }

        if(col0==0){
            matrix[i][0]=0;
        }
    }
    
    return;
}

int main(){
    vector<vector<int>> matrix = {
        {99,  17, 67, 46}, 
        {0, 87, 32, 53}, 
        {27, 24, 79, 71}, 
        {23, 0, 17, 0}, 
        {85, 100, 40, 0} 
    };

    setZeros(matrix);

    for(vector<int> v: matrix){
        for(int i: v){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}