#include <stdio.h>
#include <iostream>

using namespace std;

void zero_arr(int (&arr)[26])
{
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
}

void make_palindrome_helper(int (&count_arr)[26], char odd_letter, int odd_letter_count, int index)
{
    if (index == 26)
    {
    }
    else
    {
        int half_count = count_arr[index] / 2;
        for (int i = 0; i < half_count; i++)
        {
            cout << (char)(index + 0x41);
        }
        count_arr[index] -= half_count;
        make_palindrome_helper(count_arr, odd_letter, odd_letter_count, index + 1);
        if (index == 25 && count_arr[odd_letter - 0x41] == -1)
        {
            // count_arr[odd_letter - 0x41] = 0;
            for (int i = 0; i < odd_letter_count; i++)
            {
                cout << odd_letter;
            }
        }
        for (int i = 0; i < half_count; i++)
        {
            cout << (char)(index + 0x41);
        }
        count_arr[index] -= half_count;
    }
}

void make_palindrome(int (&count_arr)[26], char odd_letter, int odd_letter_count)
{

    count_arr[odd_letter - 0x41] = -1;
    make_palindrome_helper(count_arr, odd_letter, odd_letter_count, 0);
}

int main()
{
    int char_count_arr[26];
    zero_arr(char_count_arr);

    string s;
    cin >> s;

    for (char c : s)
    {
        if ( c - 0x41 < 0){
            cout << "INVALID INPUT\n";
            return -1;
        }
        char_count_arr[c - 0x41] += 1;
    }

    int num_odd_letters = 0;
    char odd_letter = '3';
    int odd_letter_count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (char_count_arr[i] % 2 != 0)
        {
            num_odd_letters += 1;
            odd_letter = i + 0x41;
            odd_letter_count = char_count_arr[i];
        }
    }

    if ((s.size() % 2 == 0 && num_odd_letters > 0) ||
        (s.size() % 2 != 0 && num_odd_letters > 1))
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        make_palindrome(char_count_arr, odd_letter, odd_letter_count);
    }
}