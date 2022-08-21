#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int last[1000005];
int dp[4005][4005];
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    int ans = 2;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = 2;
            if (last[a[j]] != 0)
            {
                dp[i][j] = max(dp[i][j], 1 + dp[last[a[j]]][i]);
            }
            if (dp[i][j] > ans)
            {
                ans = dp[i][j];
            }
        }
        last[a[i]] = i;
    }
    cout << ans;
}