#include <bits/stdc++.h>

using namespace std;

bool is_clockwise(int k){
    return k % 2 == 0;
}

int main(){
    // Even spiral runs clockwise
    // Odd spiral runs counter-clockwise

    int t;
    long long x;
    long long  y;
    cin >> t;

    long long diagonal = 0;
    for (int i = 0; i < t; i++){
        cin >> y;
        cin >> x;
        if (x >= y){
            diagonal = x*x - x + 1;
            if (is_clockwise(x)){
                cout << diagonal - (x-y) << "\n";
            }
            else{
                cout << diagonal + (x-y) << "\n";
            }
        }
        else{
            diagonal = y*y - y + 1;
            if (is_clockwise(y)){
                cout << diagonal + (y-x) << "\n";
            }
            else{
                cout << diagonal - (y-x) << "\n";
            }
        }
    }
}