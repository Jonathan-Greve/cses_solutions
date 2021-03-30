#include <bits/stdc++.h>

using namespace std;

vector<int> solutions(16, 0);

int find_number_solutions(int n)
{
    if (n == 1)
    {
        solutions[0] = 1;
        return 1;
    }

    int num_solutions = n;
    for (int i = 1; i < n; i++)
    {
        if (solutions[n - i - 1] == 0)
        {
            num_solutions += find_number_solutions(n - i);
        }
        else
        {
            num_solutions += solutions[n - i-1];
        }
    }
    solutions[n-1] = num_solutions;
    return num_solutions;
}

void print_solutions(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "n: " << i + 1 << " --> " << solutions[i] << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    find_number_solutions(n);
    print_solutions(n);
}