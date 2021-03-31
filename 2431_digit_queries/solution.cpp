#include <bits/stdc++.h>

using namespace std;

int extract_digit(long long num, int index, int exp){
    while (exp > index){
        num /= 10;
        exp--;
    }
}

int solve(int k){
    int result;

    int exp = 1;
    long long index = 1;
    long long curr_num = 1;

    // First find the nearest 10th number and index;
    while (true){
        long long new_curr_num = 9*pow(10, exp-1);
        long long new_index = new_curr_num * exp;

        if (new_index >= k){
            break;
        }
        else{
            exp++;
            index += new_index;
            curr_num += new_curr_num;
        }
    }

    long long index_dt = k - index;
    long long nums_dt = floor(index_dt / exp);

    index += nums_dt * exp;
    curr_num += nums_dt;

    if (k-index > exp){
        cout << "Something is wrong: " << k - index << "\n";
    }
    result = extract_digit(curr_num, k-index, exp);

    return result;
}

int main(){
    int q;
    long long k;
    vector<int> results;

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> k;

        int result = solve(k);
        results.push_back(result);
    }

    for (auto &&result : results)
    {
        cout << result << "\n";
    }
    
}