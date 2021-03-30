#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int a, b;
    int tmp;

    for (int i = 0; i < t; i++)
    {
        cin >> a;
        cin >> b;

        if (a*b == 0 && (a !=0 || b != 0)){
            cout << "NO\n";
            continue;
        }

        if (b > a)
        {
            tmp = b;
            b = a;
            a = tmp;
        }
        int a_min_moves = a / 2 + a % 2;
        int b_val_after_a_min_move;

        if (a % 2 == 0){
            b_val_after_a_min_move = a_min_moves;
        }
        else{
            b_val_after_a_min_move = a_min_moves + 1; // (a_min_moves - 1) + 2
        }

        if (b_val_after_a_min_move == b || (b_val_after_a_min_move < b && (b-b_val_after_a_min_move) % 3 == 0)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}