#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;
    if (sum % 2 != 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";

        vector<int> s1;
        vector<int> s2;

        bool into_s1 = true;
        int count = 0;
        for (long long i = n; i > 0; i--)
        {
            if (into_s1)
            {
                s1.push_back(i);
            }
            else
            {
                s2.push_back(i);
            }
            count += 1;
            if (count % 2 == 0)
            {
            }
            else
            {
                into_s1 = !into_s1;
            }
        }

        cout << s1.size() << "\n";
        for (int val : s1)
        {
            cout << val << " ";
        }

        cout << "\n";
        cout << s2.size() << "\n";
        for (int val : s2)
        {
            cout << val << " ";
        }
    }
}