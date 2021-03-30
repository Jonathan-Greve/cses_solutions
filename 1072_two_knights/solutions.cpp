#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    cout << 0 << "\n";
    if (n > 1){
        cout << 6 << "\n";
    }
    if (n > 2){
        cout << 28 << "\n";
    }
    if (n > 3){
        cout << 96 << "\n";
    }

    long long prev_solution = 96;
    long long curr_sol = 0;
    for (long long k = 5; k < n+1; k++){
        curr_sol = prev_solution + 3*(k*k - 3) + 4*(k*k - 4) + max(0, (2*(int)k-8))*(k*k-5) - ((2*k-2)*(2*k-1))/2 + 2;
        // // Test if k has to be a long long 64 bit int
        // int c = (int)k;
        // long long test = prev_solution + 3*(c*c - 3) + 4*(c*c - 4) + max(0, (2*c-8))*(c*c-5) - ((2*c-2)*(2*c-1))/2 + 2;
        // if (test != curr_sol){
        //     cout << "WRONG SOLUTION" << "\n";
        //     break;
        // }
        cout << curr_sol << "\n";
        prev_solution = curr_sol;
    }
}