#include <bits/stdc++.h>

using namespace std;

long long my_mod_pow(long long base, long long exponent, long long mod){
    if (exponent == 1){
        return base;
    }
    return ((base % mod)*(my_mod_pow(base, exponent - 1, mod) % mod)) % mod;
}

// (x * y) mod m = (x mod m * y mod m) mod m
int main(){
    long long n;
    cin >> n;

    long long result = my_mod_pow(2, n, pow(10, 9) + 7);

    cout << result << "\n";
}