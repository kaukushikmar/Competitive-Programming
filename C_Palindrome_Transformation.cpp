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

    int n, p;
    cin >> n >> p;
    p = p - 1;
    vector<int> mvs(n, 0);
    string s;
    cin >> s;
    for (int i = 0; i < n / 2; i++)
    {
        mvs[i] = min(abs((s[i] - 'a') - (s[n - 1 - i] - 'a')), abs(26 - abs((s[i] - 'a') - (s[n - 1 - i] - 'a'))));
        // cout << mvs[i] << " ";
        // cout << i << endl;
    }
    if (n % 2 == 0 && p >= n / 2)
    {
        p = (n - 1 - p);
    }
    if (n % 2 == 1 && p >= (n + 1) / 2)
    {
        p = (n - 1 - p);
    }
    int start = -1, end = -1;
    for (int i = 0; i < n; i++)
    {
        if (mvs[i] != 0)
        {
            start = i;
            break;
        }
    }
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        if (mvs[i] != 0)
        {
            end = i;
            break;
        }
    }
    if (start == -1 && end == -1)
    {
        cout << 0 << endl;
        return 0;
    }
    // cout << start << end << endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += mvs[i];
    // cout << sum << endl;
    if (p >= end)
    {
        cout << (p - start + sum) << endl;
    }
    else if (p <= start)
    {
        cout << (end - p + sum) << endl;
    }
    else
    {
        cout << ((end - start) + min(p - start, end - p) + sum) << endl;
    }
}