#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> board, int row, int col, int num){
    for(int i=0; i<9; i++){
        if(board[row][i]==num)
            return false;
        
        if(board[i][col]==num)
            return false;

        if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)]==num)
            return false;
    }

    return true;
}

// Time Complexity: O(9^(N^2)) -- In worst case we have to choose for all N^2 cells out of (1 to 9) numbers.
// Space Complexity: O(1)
bool Solve(vector<vector<int>> &board){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j]==0){
                for(int k=1; k<10; k++){
                    if(isSafe(board, i, j, k)){
                        board[i][j] = k;
                        if(Solve(board)){
                            return true;
                        } else {
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> board = {
        {1, 5, 9, 0, 0, 6, 0, 3, 2},
        {2, 7, 4, 0, 0, 0, 0, 0, 0},
        {3, 8, 6, 2, 0, 0, 0, 0, 5},
        {4, 9, 2, 5, 0, 1, 0, 8, 0},
        {6, 3, 7, 0, 4, 0, 0, 0, 0},
        {5, 1, 0, 8, 2, 0, 0, 0, 0},
        {8, 2, 1, 0, 0, 0, 0, 0, 0},
        {7, 6, 0, 1, 0, 0, 4, 2, 0},
        {9, 4, 3, 0, 7, 0, 0, 6, 1}
    };

    cout << Solve(board);
    return 0;
}