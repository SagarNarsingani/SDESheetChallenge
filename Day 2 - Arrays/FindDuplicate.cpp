#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int GetDuplicate(vector<int> arr){
    unordered_set<int> s;
    for(int i: arr){
        if(s.find(i)!=s.end()){
            return i;
        }
        s.insert(i);
    }

    return -1;
}

int main(){
    cout << GetDuplicate({1, 2, 2, 3, 4, 5, 6});
    return 0;
}