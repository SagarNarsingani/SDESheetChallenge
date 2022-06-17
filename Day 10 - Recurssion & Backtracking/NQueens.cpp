#include <iostream>
#include <vector>
using namespace std;

bool canPlace(int i, int j, int n, vector<vector<int>> board){
    for(int k=0; k<n; k++){
        if(board[i][k]==1){
            return false;
        }

        if(board[k][j]==1){
            return false;
        }
    }

    int k=i, l=j;
    while((k-1 >= 0) and (l-1 >= 0)){
        k--;
        l--;
        if(board[k][l]==1){
            return false;
        }
    }

    k=i, l=j;
    while((k-1 >= 0) and (l+1 < n)){
        k--;
        l++;
        if(board[k][l]==1){
            return false;
        }
    }

    return true;
}

void AddSol(vector<vector<int>> board, vector<vector<int>> &sols, int n){
    vector<int> tmp;
    for(auto i: board){
        for(int j: i){
            tmp.push_back(j);
        }
    }
    sols.push_back(tmp);
}

void GetSol(int i, int n, vector<vector<int>> board, vector<vector<int>> &sols){
    if(i==n) {
        AddSol(board, sols, n);
        return;
    }

    for(int j=0; j<n; j++){
        if(canPlace(i, j, n, board)){
            board[i][j] = 1;
            GetSol(i+1, n, board, sols);
            board[i][j] = 0;
        }
    }

    return;
}

vector<vector<int>> SolveQueens(int n){

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> sols;
    GetSol(0, n, board, sols);

    for(auto i: sols){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return sols;
}

void GetSolOpt(int i, int n, vector<int> upperDiagonal, vector<int> lowerDiagonal, vector<int> cols, vector<vector<int>> board, vector<vector<int>> &sols){
    if(i==n) {
        AddSol(board, sols, n);
        return;
    }

    for(int j=0; j<n; j++){
        if((cols[j]==0) and (upperDiagonal[i+j]==0) and (lowerDiagonal[(n-1)+(j-i)]==0)){
            board[i][j] = 1;
            cols[j]=1;
            upperDiagonal[i+j]=1;
            lowerDiagonal[(n-1)+(j-i)]=1;
            GetSolOpt(i+1, n, upperDiagonal, lowerDiagonal, cols, board, sols);
            cols[j]=0;
            upperDiagonal[i+j]=0;
            lowerDiagonal[(n-1)+(j-i)]=0;
            board[i][j] = 0;
        }
    }

    return;
}

vector<vector<int>> SolveQueensOpt(int n){

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> sols;

    // for the diagonal (left to right) (n-1) + (j-i) will remain constant
    // for other diagonal i+j will remain constant.
    // in both cases maximum value will be 2*n-1.
    // we are using this fact to reduce the time complexity here.
    vector<int> upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0), cols(n, 0);
    GetSolOpt(0, n, upperDiagonal, lowerDiagonal, cols, board, sols);

    for(auto i: sols){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return sols;
}

int main(){
    SolveQueensOpt(4);
    // cout << canPlace(2, 2, 4, {{0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}});
    return 0;
}