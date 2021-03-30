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

print_solution(int n){
    cout << solutions[n-1] << "\n";
}

void move_stack(int n, int from, int to)
{
    if (n < 1){
        return;
    }
    else if (n == 1)
    {
        cout << from << " " << to << "\n";
    }
    else if (n == 2)
    {
        if (from == 1)
        {
            if (to == 2)
            {
                cout << 1 << " " << 3 << "\n";
                cout << 1 << " " << 2 << "\n";
                cout << 3 << " " << 2 << "\n";
            }
            if (to == 3)
            {
                cout << 1 << " " << 2 << "\n";
                cout << 1 << " " << 3 << "\n";
                cout << 2 << " " << 3 << "\n";
            }
        }
        else if (from == 2)
        {
            if (to == 1)
            {
                cout << 2 << " " << 3 << "\n";
                cout << 2 << " " << 1 << "\n";
                cout << 3 << " " << 1 << "\n";
            }
            if (to == 3)
            {
                cout << 2 << " " << 1 << "\n";
                cout << 2 << " " << 3 << "\n";
                cout << 1 << " " << 3 << "\n";
            }
        }
        else if (from == 3)
        {
            if (to == 1)
            {
                cout << 3 << " " << 2 << "\n";
                cout << 3 << " " << 1 << "\n";
                cout << 2 << " " << 1 << "\n";
            }
            if (to == 2)
            {
                cout << 3 << " " << 1 << "\n";
                cout << 3 << " " << 2 << "\n";
                cout << 1 << " " << 2 << "\n";
            }
        }
        else
        {
            cout << "ERROR\n";
            throw;
        }
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
        cout << from << " " << to << "\n";
        move_stack(n - 1, tmp_to, to);
    }
}

int main()
{
    int n;
    cin >> n;

    find_number_solutions(n);
    print_solution(n);

    int tmp_from = 2;
    int tmp_to = -1;
    for (int i = 0; i < n; i++)
    {
        tmp_from = ((tmp_from + 2) % 2) + 1;
        if (tmp_from == 2)
        {
            tmp_to = 1;
        }
        else if (tmp_from == 1)
        {
            tmp_to = 2;
        }
        move_stack(n - i - 1, tmp_from, tmp_to);
        cout << tmp_from << " " << 3 << "\n";
    }

    return 0;
}