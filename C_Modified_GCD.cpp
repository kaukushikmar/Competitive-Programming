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
}