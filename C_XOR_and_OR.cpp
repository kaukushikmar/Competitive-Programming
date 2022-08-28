#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    if (s1.length() != s2.length())
    {
        cout << "NO" << endl;
        return 0;
    }

    int n = s1.length();
    bool valid = true;

    for (int i = 0; i < n - 1; i++)
    {
        int xr = (s1[i] - '0') ^ (s1[i + 1] - '0');
        int rr = (s1[i] - '0') | (s1[i + 1] - '0');
        if ((xr == (s1[i] - '0') && rr == (s1[i + 1] - '0')) || (rr == (s1[i] - '0') && xr == (s1[i + 1] - '0')))
        {
            continue;
        }
        else
        {
            valid = false;
        }
    }
    if (valid)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}