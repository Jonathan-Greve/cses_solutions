#include <bits/stdc++.h>

using namespace std;

int find_highest10_divisor(long long n)
{
    long long best = 10;
    int exponent = 1;
    while (true)
    {
        if (n % (best * 10) == 0)
        {
            best = best * 10;
            exponent += 1;
        }
        else
        {
            break;
        }
    }
    return exponent;
}

int main()
{
    long long n;
    cin >> n;

    long long curr_product = 1;

    long long num_zeros = 0;
    for (long long k = 1; k <= n; k++)
    {
        curr_product = ((curr_product % 1000000000000000000) * (k % 1000000000000000000)) % 1000000000000000000;
        if (curr_product % 10 == 0)
        {
            num_zeros += find_highest10_divisor(curr_product);
            curr_product = 1;
        }
    }

    cout << num_zeros << "\n";
}