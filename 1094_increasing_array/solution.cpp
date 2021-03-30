#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int prev_val = 0;
    int curr_val = 0;
    long long moves = 0;

    for (int i = 0; i < n; i++){
        cin >> curr_val;
        if (curr_val < prev_val){
            moves += prev_val - curr_val;
        }
        else{
            prev_val = curr_val;
        }
    }

    cout << moves;
}