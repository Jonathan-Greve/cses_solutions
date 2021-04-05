#include <bits/stdc++.h>

using namespace std;

static const int board_size = 7;

int solve(string moves, bool curr_path[board_size * board_size - 1], int move_index, int x, int y);

bool can_go_up(int x, int y, bool curr_path[board_size * board_size - 1])
{
    if (y - 1 >= 0 && !curr_path[(y - 1) * board_size + x])
    {
        return true;
    }
    return false;
}

bool can_go_down(int x, int y, bool curr_path[board_size * board_size - 1])
{
    if (y + 1 < board_size && !curr_path[(y + 1) * board_size + x])
    {
        return true;
    }
    return false;
}

bool can_go_right(int x, int y, bool curr_path[board_size * board_size - 1])
{
    if (x + 1 < board_size && !curr_path[y * board_size + x + 1])
    {
        return true;
    }
    return false;
}

bool can_go_left(int x, int y, bool curr_path[board_size * board_size - 1])
{
    if (x - 1 >= 0 && !curr_path[y * board_size + x - 1])
    {
        return true;
    }
    return false;
}

int try_move(string moves, bool curr_path[board_size * board_size - 1], int move_index, int x, int y, char move)
{
    int num_solutions = 0;
    switch (move)
    {
    case 'U':
        if (can_go_up(x, y, curr_path) && !(!(can_go_left(x, y, curr_path) || can_go_right(x,y,curr_path)) && can_go_down(x,y,curr_path))){
            curr_path[(y-1)*board_size + x] = true;
            num_solutions = solve(moves, curr_path, move_index + 1, x, y-1);
            curr_path[(y-1)*board_size + x] = false;
            return num_solutions;
        }
        break;
    case 'D':
        if (can_go_down(x, y, curr_path) && !(!(can_go_left(x, y, curr_path) || can_go_right(x,y,curr_path)) && can_go_up(x,y,curr_path))){
            curr_path[(y+1)*board_size + x] = true;
            num_solutions = solve(moves, curr_path, move_index + 1, x, y+1);
            curr_path[(y+1)*board_size + x] = false;
            return num_solutions;
        }
        break;
    case 'R':
        if (can_go_right(x, y, curr_path) && !(!(can_go_up(x, y, curr_path) || can_go_down(x,y,curr_path)) && can_go_left(x,y,curr_path))){
            curr_path[y*board_size + x + 1] = true;
            num_solutions = solve(moves, curr_path, move_index + 1, x+1, y);
            curr_path[y*board_size + x + 1] = false;
            return num_solutions;
        }
        break;
    case 'L':
        if (can_go_left(x, y, curr_path) && !(!(can_go_up(x, y, curr_path) || can_go_down(x,y,curr_path)) && can_go_right(x,y,curr_path))){
            curr_path[y*board_size + x - 1] = true;
            num_solutions = solve(moves, curr_path, move_index + 1, x-1, y);
            curr_path[y*board_size + x - 1] = false;
            return num_solutions;
        }
        break;
    }
    return num_solutions;
}

int solve(string moves, bool curr_path[board_size*board_size-1], int move_index, int x, int y)
{
    int num_solutions = 0;
    static char UDLR[4] = {'U', 'D', 'L', 'R'};
    if (x == 0 && y == (board_size-1) && move_index == (board_size*board_size - 1))
    {
        num_solutions = 1;
    }
    else
    {
        if (moves[move_index] == '?')
        {
            for (auto &&move : UDLR)
        {
            num_solutions += try_move(moves, curr_path, move_index, x, y, move);
        }
    }
    else
    {
        num_solutions += try_move(moves, curr_path, move_index, x, y, moves[move_index]);
    }
}

return num_solutions;
}

int main()
{
    string moves;

    getline(cin, moves);

    bool curr_path[board_size * board_size - 1];
    curr_path[0] = true;

    int num_solutions = solve(moves, curr_path, 0, 0, 0);

    cout << num_solutions << "\n";

    return 0;
}