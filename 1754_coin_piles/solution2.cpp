#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, a, b, tmp;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a;
        cin >> b;

        if (b > a)
            swap(a,b);
        if (a > 2*b)
            cout << "NO\n";
        else{
            if ((a+b) % 3 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}