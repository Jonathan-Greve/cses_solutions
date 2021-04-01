#include <bits/stdc++.h>

using namespace std;
int solve(string &moves, int move_index, int x, int y);

int string_length = 48;
int grid_size = 7;
bool curr_path[48];

static int path_count = 0;

int try_move(string &moves, int move_index, int x, int y, char move)
{
    switch (move)
    {
    case 'D':
        if (y + 1 < grid_size && !curr_path[(y + 1) * grid_size + x])
            return solve(moves, move_index, x, y + 1);
        break;
    case 'U':
        if (y - 1 >= 0 && !curr_path[(y - 1) * grid_size + x])
            return solve(moves, move_index, x, y - 1);
        break;
    case 'L':
        if (x - 1 >= 0 && !curr_path[y * grid_size + x - 1])
            return solve(moves, move_index, x - 1, y);
        break;
    case 'R':
        if (x + 1 < grid_size && !curr_path[y * grid_size + x + 1])
            return solve(moves, move_index, x + 1, y);
        break;
    default:
        cout << "Something went wrong: " << move << "\n";
    }
    return 0;
}

int solve(string &moves, int move_index, int x, int y)
{
    curr_path[y * grid_size + x] = true;

    if (x == 6 && y == 6)
    {
        path_count += 1;
        cout << path_count << "\n";
        curr_path[y * grid_size + x] = false;
        return 1;
    }
    if (move_index >= string_length)
    {
        curr_path[y * grid_size + x] = false;
        return 0;
    }

    int num_solutions = 0;
    if (moves[move_index] == '?')
    {
        num_solutions += try_move(moves, move_index + 1, x, y, 'D');
        num_solutions += try_move(moves, move_index + 1, x, y, 'U');
        num_solutions += try_move(moves, move_index + 1, x, y, 'L');
        num_solutions += try_move(moves, move_index + 1, x, y, 'R');
    }
    else
    {
        num_solutions += try_move(moves, move_index + 1, x, y, moves[move_index]);
    }
    curr_path[y * grid_size + x] = false;
    return num_solutions;
}

int main()
{
    string moves;

    getline(cin, moves);

    int num_solutions = solve(moves, 0, 0, 0);

    cout << num_solutions << "\n";

    return 0;
}