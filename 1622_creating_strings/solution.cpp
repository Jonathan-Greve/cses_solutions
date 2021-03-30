#include <bits/stdc++.h>

using namespace std;

int num_solutions{0};
string solution_str{""};

void create_string_helper(string curr_str, string result)
{
    if (curr_str == "")
    {
        num_solutions++;
        solution_str += (result + "\n");
    }
    else
    {
        unordered_map<char, int> char_seen_map;
        for (int i = 0; i < curr_str.size(); i++)
        {
            char replaced_char = curr_str[i];
            if (char_seen_map.count(replaced_char) == 0)
            {
                char_seen_map[replaced_char] = 1;
                string curr_str_copy = curr_str;
                curr_str_copy.replace(i, 1, "");
                create_string_helper(curr_str_copy, result + replaced_char);
            }
        }
    }
}

void create_strings(string start_str)
{
    sort(start_str.begin(), start_str.end());
    create_string_helper(start_str, "");
}

int main()
{
    string input_str;
    getline(cin, input_str);

    create_strings(input_str);
    cout << num_solutions << "\n";
    cout << solution_str;
}