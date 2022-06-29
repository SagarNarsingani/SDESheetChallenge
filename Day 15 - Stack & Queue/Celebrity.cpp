#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// To run this code locally, set this mat(of NxN size) with appropiate values.
vector<vector<int>> mat = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

bool knows(int A, int B){
    return mat[A][B];
}

// Time Complexity: O(N).
// Space Complexity: O(N).
int FindCeleb(int n){
    stack<int> s;
    for(int i=0; i<n; i++){
        s.push(i);
    }

    while(s.size()>1){
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();

        // If A knows B, A can't be celeb.
        if(knows(A, B)){
            s.push(B);
        // If A doesn't know B, B can't be celeb.
        } else {    
            s.push(A);
        }
    }

    // will asume last remaining int as Celeb.
    int C = s.top();
    
    // Verifying C as celeb.
    for(int i=0; i<n; i++){
        if(i==C) continue;
        // if i doesn't know C or C knows i then C can't be celeb.
        if(!knows(i, C) || knows(C, i))
            return -1;
    }

    return C;
}

// Time Complexity: O(N).
// Space Complexity: O(1).
int FindCelebOpt(int n){
    int A = 0, B = n-1;
    while(A<B){
        // A can't be celeb.
        if(knows(A, B)){
            A++;
        } else {    // B can't be celeb.
            B--;
        }
    }

    int C = A;

    // Verifying C as celeb.
    for(int i=0; i<n; i++){
        if(i==C) continue;
        // if i doesn't know C or C knows i then C can't be celeb.
        if(!knows(i, C) || knows(C, i))
            return -1;
    }

    return C;
}