#include <bits/stdc++.h>

using namespace std;

long long extract_digit(long long num, long long index, long exp){
    // Index is the 1-based offset to the digit from left to right
    // Exp - Index - 1 is the 0 based offset to the digit from right to left
    long long offset_LtR = exp - index - 1;

    return (long long)(num / powl(10, offset_LtR)) % 10;
}

long long solve(long long k){
    long long result;

    long long exp = 1;
    long long index = 1;
    long long curr_num = 1;

    // First find the nearest 10th number and index;
    while (true){
        long long new_curr_num = 9*powl(10, exp-1);
        long long new_index = index + new_curr_num * exp;

        if (new_index > k){
            break;
        }
        else{
            exp++;
            index = new_index;
            curr_num += new_curr_num;
        }
    }

    long long index_dt = k - index;
    long long nums_dt = index_dt / exp;

    index += nums_dt * exp;
    curr_num += nums_dt;

    result = extract_digit(curr_num, k-index, exp);

    return result;
}

int main(){
    long long q;
    long long k;
    vector<long long> results;

    cin >> q;
    for (long long i = 0; i < q; i++)
    {
        cin >> k;

        long long result = solve(k);
        results.push_back(result);
    }

    for (auto &&result : results)
    {
        cout << result << "\n";
    }
    
    return 0;
}