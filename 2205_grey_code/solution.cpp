#include <bits/stdc++.h>

using namespace std;

void sub1_all_and_update(vector<int> &counts_arr, vector<int> &print_arr){
    for (int i = counts_arr.size() -1; i >= 0; i--)
    {
        counts_arr[i] = counts_arr[i] -1;
        if (counts_arr[i] == 0){
            counts_arr[i] = pow(2, i+1);
            print_arr[i] = (print_arr[i] + 1) % 2;
        }
    }
}

void print_arr(vector<int> print_arr){
    for (int i = print_arr.size() - 1; i >= 0; i--)
    {
        cout << print_arr[i];
    }
    
}

int main(){
    int n;
    cin >> n;

    vector<int> remaining_counts;
    vector<int> curr_prints;

    for (int i = 0; i < n; i++)
    {
        remaining_counts.push_back(pow(2, i));
        curr_prints.push_back(0);
    }

    for (int i = 0; i < pow(2, n); i++)
    {
        print_arr(curr_prints);
        sub1_all_and_update(remaining_counts, curr_prints);
        cout << "\n";
    }
}