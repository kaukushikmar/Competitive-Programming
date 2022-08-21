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

    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<long long> prefix(n + 1);
    prefix[0] = 0;
    for (long long i = 1; i <= n; i++)
    {
        prefix[i] += prefix[i - 1] + v[i - 1];
    }
    long long maxcnt = 0, mnm = 0;
    long long l = 0, r = n;
    for (long long i = 0; i < n; i++)
    {
        long long l = 0, r = i, best = 0;
        while (l <= r)
        {
            long long mid = (r + l) / 2;
            long long sum1 = v[i] * mid * 1ll;
            long long sum2 = prefix[i] - prefix[i - mid];
            if (sum1 - sum2 <= k)
            {
                l = mid + 1;
                best = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (best + 1 > maxcnt)
        {
            maxcnt = best + 1;
            mnm = v[i];
        }
    }
    cout << maxcnt << " " << mnm << endl;
}