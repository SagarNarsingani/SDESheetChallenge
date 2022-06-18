#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double multiply(double num, int n){
    double ans = 1.0; 
    while(n > 0){
        if(n&1){
            ans = ans * num;
        }
        n = n >> 1;
    }

    return ans;
}

// Time Complexity: O(N * LogM)
double GetNthRoot(int n, long long m){
    double low = 1, high = m;
    double eps = 1e-6;

    double mid = (high+low)/2.0;
    while(abs(pow(mid, n)-m) >= eps){
        double tmp = pow(mid, n);
        if(tmp < m){
            low = mid;
        } else{
            high = mid;
        }
        mid = (high+low)/2.0;
    }


    return mid;
}

// Newton Raphson Method of finding root.
double NewtonRaphson(int n, long long m){
    // based on the precision we want in answer, here we wanted 6 correct decimals. 
    double err = 1e-7;

    // maximum initially. Basically shows difference between current guess and previous guess.
    double diff = 1e18;

    // initial guess or X0 according to method. (Don't know the logic but 0 and 1 didn't give right answer)
    double xn = 2;

    // till difference is greater than error.
    while(diff > err){

        // finding next assumpsion.
        double xn1 = ((n-1) * pow(xn, n) + m) / (n *  pow(xn, n-1));

        // difference between current and previous asumpsion.
        diff = abs(xn1 - xn);

        // changin the previous assumption to current, for next iteration.
        xn = xn1;
    }

    cout.precision(7);
    return xn;
}

int main(){
    cout << NewtonRaphson(2, 3);
    // cout << (12 >> 1) << endl;
    return 0;
}