#include <bits/stdc++.h>

using namespace std;

long long brute_solve(vector<long long> &weights)
{
    int num_elements = weights.size();
    long long weights_sum = accumulate(weights.begin(), weights.end(), (long long)0);
    long long min_weight_diff = numeric_limits<long long>::max();
    int curr_bit;
    long long curr_weight_diff = 0;
    for (int i = 1; i < (1 << num_elements); i++)
    {
        for (int j = 0; j < num_elements; j++)
        {
            curr_bit = i >> j;
            if ((curr_bit & 1) == 1)
                curr_weight_diff += weights[j];
        }

        long long other_half = weights_sum - curr_weight_diff;
        curr_weight_diff = abs(other_half - curr_weight_diff);

        if (curr_weight_diff < min_weight_diff)
        {
            min_weight_diff = curr_weight_diff;
            if (min_weight_diff == 0)
                break;
        }
        curr_weight_diff = 0;
    }

    return min_weight_diff;
}

int main()
{
    int n;
    cin >> n;

    vector<long long>
        apple_weights;

    long long x;
    while (n > 0)
    {
        n--;
        cin >> x;
        apple_weights.push_back(x);
    }

    long long min_weight_diff = brute_solve(apple_weights);
    cout << min_weight_diff << "\n";

    return 0;
}