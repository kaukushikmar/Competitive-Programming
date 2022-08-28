#include <bits/stdc++.h>
using namespace std;

int n, t[800005];
int q;
int a[200005];

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}

int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 1e9;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(sum(v * 2, tl, tm, l, min(r, tm)), sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    build(a, 1, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 2)
        {
            cout << sum(1, 0, n - 1, y - 1, z - 1) << endl;
        }
        else
        {
            update(1, 0, n - 1, y - 1, z);
        }
    }
}