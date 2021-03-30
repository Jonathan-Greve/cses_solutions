#include <bits/stdc++.h>

using namespace std;

string solution_string;
int num_solutions = 0;

void add_to_string(int from, int to)
{
    solution_string += '0' + from;
    solution_string += " ";
    solution_string += '0' + to;
    solution_string += "\n";
}

void move_stack(int n, int from, int to)
{
    num_solutions += 1;
    if (n < 1)
    {
        return;
    }
    else if (n == 1)
    {
        add_to_string(from, to);
        // cout << from << " " << to << "\n";
    }
    else
    {
        int tmp_to;

        if ((from == 1 && to == 2) || (to == 1 && from == 2))
            tmp_to = 3;
        else if ((from == 1 && to == 3) || ((from == 3 && to == 1)))
            tmp_to = 2;
        else
            tmp_to = 1;

        move_stack(n - 1, from, tmp_to);
        add_to_string(from, to);
        // cout << from << " " << to << "\n";
        move_stack(n - 1, tmp_to, to);
    }
}

int main()
{
    int n;
    cin >> n;

    move_stack(n, 1, 3);

    cout << num_solutions << "\n";
    cout << solution_string;
    return 0;
}