#include <bits/stdc++.h>

using namespace std;

string d;
int c = 0;

void f(int a, int b)
{
    d += '0' + a;
    d += " ";
    d += '0' + b;
    d += "\n";
}

void g(int n, int a, int b)
{
    c += 1;
    if (n < 1)
    {
        return;
    }
    else if (n == 1)
    {
        f(a, b);
        // cout << a << " " << b << "\n";
    }
    else
    {
        int e;

        if ((a == 1 && b == 2) || (b == 1 && a == 2))
            e = 3;
        else if ((a == 1 && b == 3) || ((a == 3 && b == 1)))
            e = 2;
        else
            e = 1;

        g(n - 1, a, e);
        f(a, b);
        // cout << a << " " << b << "\n";
        g(n - 1, e, b);
    }
}

int main()
{
    int n;
    cin >> n;

    g(n, 1, 3);

    cout << c << "\n";
    cout << d;
    return 0;
}