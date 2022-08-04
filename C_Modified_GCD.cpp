#include <bits/stdc++.h>
using namespace std;

int a, b;
int n;
int low[10005], high[10005];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{

    cin >> a >> b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> low[i] >> high[i];
    }

    int d = gcd(a, b);
    vector<int> v;
    for (int i = 1; i * i <= d; i++)
    {
        if (d % i == 0)
        {
            v.push_back(i);
            if (d / i > i)
                v.push_back(d / i);
        }
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int ans = -1;
        for (int j = v.size() - 1; j >= 0; j--)
        {
            if (low[i] <= v[j] && v[j] <= high[i])
            {
                ans = v[j];
                break;
            }
        }
        cout << ans << endl;
    }
}