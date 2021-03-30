#include <bits/stdc++.h>

using namespace std;

int main(){
    char prev_char = '0';
    long long best_streak = 1;
    long long curr_streak = 1;

    string s;
    getline(cin, s);

    for (char c : s){
        if (prev_char != c){
            curr_streak = 1;
        }
        else{
            curr_streak += 1;
            if (curr_streak > best_streak){
                best_streak = curr_streak;
            }
        }
        prev_char = c;
    }
    cout << best_streak;
}