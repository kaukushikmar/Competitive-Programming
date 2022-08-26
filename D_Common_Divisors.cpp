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

    int n1 = s1.length(), n2 = s2.length();
    string common = "";

    for (int i = 0; i < min(n1, n2); i++)
    {
        if (s1[i] == s2[i])
        {
            common += s1[i];
        }
        else
            break;
    }

    if (common.length() == 0)
    {
        cout << 0 << endl;
        return 0;
    }
}