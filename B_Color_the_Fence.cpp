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

    int n;
    cin >> n;
    vector<int> v(9);
    for (int i = 0; i < 9; i++)
        cin >> v[i];
    int maxd = 1e9;
    int d = 0;
    for (int i = 0; i < 9; i++)
    {
        if (v[i] <= maxd)
        {
            maxd = v[i];
            d = i + 1;
        }
    }
    int mxmd = n / maxd;
    if (mxmd == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    n %= v[d - 1];
    string s = "";
    while (mxmd)
    {
        s += d + '0';
        mxmd--;
    }
    int j = 0;
    for (int i = 8; i > d - 1; i--)
    {
        int val = v[i] - v[d - 1];
        int cnt = n / val;
        for (int k = j; k < min((int)s.length(), j + cnt); k++)
        {
            s[k] = i + 1 + '0';
        }
        n -= val * cnt;
        j += cnt;
    }
    cout << s << endl;
}