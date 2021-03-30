#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    long long x;
    cin >> n;

    long long sum_1_to_n = (n*(n+1))/2;
    long long sum = 0;

    for(int i = 0; i < n-1; i++){
        cin >> x;
        sum += x;
    }

    int missing_number = sum_1_to_n - sum;
    cout << missing_number;
}
