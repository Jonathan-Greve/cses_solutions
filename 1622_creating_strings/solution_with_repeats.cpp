#include <bits/stdc++.h>

using namespace std;

int num_solutions{0};
string solution_str{""};

void create_string_helper(string curr_str, string result){
    if (curr_str == ""){
        num_solutions++;
        solution_str += (result + "\n");
    }
    else{
        for (int i = 0; i < curr_str.size() / sizeof(char); i++)
        {
            string curr_str_copy = curr_str;
            char replaced_char = curr_str_copy[i];
            curr_str_copy.replace(i, 1, "");
            create_string_helper(curr_str_copy, result+replaced_char);
        }
    }
}

void create_strings(string start_str){
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