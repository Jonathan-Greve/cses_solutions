#include <bits/stdc++.h>

using namespace std;

static const int n = 8;
unordered_map<int, char> occupiedFields;
long long num_solutions = 0;
bool diag1[2 * n];
bool diag2[2 * n];
bool cols[n];

void solve(int row)
{
    if (row > n)
    {
        num_solutions += 1;
    }
    else
    {
        for (int col = 1; col <= n; col++)
        {
            if (occupiedFields.find((row - 1) * n + col - 1) != occupiedFields.end())
            {
                continue;
            }
            else
            {
                int currDiag1 = row + col - 1;
                int currDiag2 = n + col - row;

                if (!diag1[currDiag1 - 1] && !diag2[currDiag2 - 1] && !cols[col - 1])
                {
                    diag1[currDiag1 - 1] = true;
                    diag2[currDiag2 - 1] = true;
                    cols[col - 1] = true;
                    // cout << "diag1: " << currDiag1 << "\n";
                    // cout << "diag2: " <<currDiag2 << "\n";
                    // cout << "col  : " <<col << "\n";
                    solve(row + 1);
                    diag1[currDiag1 - 1] = false;
                    diag2[currDiag2 - 1] = false;
                    cols[col - 1] = false;
                }
            }
        }
    }
}

int main()
{
    char inChar = ' ';
    for (int i = 0; i < n * n; i++)
    {
        cin >> inChar;
        if (inChar == '*')
        {
            occupiedFields[i] = inChar;
        }
    }

    solve(1);

    cout << num_solutions << "\n";

    return 0;
}