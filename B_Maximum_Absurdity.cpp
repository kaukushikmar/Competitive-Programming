#include <bits/stdc++.h>
using namespace std;

long long ans;
long long n, k;
long long a[200005];
long long dp[200005][2];
long long f[200005], g[200005];
int main()
{

    memset(dp, 0, sizeof(dp));
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<long long> prefix(n + 1, 0);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] += prefix[i - 1] + a[i];
    }

    int a1, b1;
    for (int i = n - k + 1; i >= 1; i--)
    {
        long long x = prefix[i + k - 1] - prefix[i - 1];
        if (x >= f[i + 1])
        {
            f[i] = x;
            g[i] = i;
        }
        else
        {
            f[i] = f[i + 1];
            g[i] = g[i + 1];
        }
    }
    for (int i = n - 2 * k + 1; i >= 1; i--)
    {
        long long x = prefix[i + k - 1] - prefix[i - 1];
        if (x + f[i + k] >= ans)
        {
            ans = x + f[i + k];
            a1 = i;
            b1 = g[i + k];
        }
    }
    cout << a1 << " " << b1 << endl;
}