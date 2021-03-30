#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    if (n == 1){
        cout << 1;
    }
    else if (n < 4)
        cout << "NO SOLUTION";
    else{
        // Print even
        for (int i = 1; i < ceil(n/2)+1; i++){
            cout << i*2 << " ";
        }

        // Print odd 
        for (int i = 0; i < ceil(n/2)+1; i++){
            cout << i*2 + 1 << " ";
        }
    }
}