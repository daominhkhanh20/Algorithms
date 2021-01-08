#include <bits/stdc++.h>
using namespace std;
#define N 50
vector<int> f[N];

bool a[N];
int cc = 0; //coneected component
void dfs(int k)
{
    a[k] = true;
    for (int i = 0; i < f[k].size(); i++)
    {
        if (!a[f[k][i]])
        {
            dfs(f[k][i]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    memset(a, false, n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        f[x].push_back(y);
        f[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == false)
        {
            dfs(i);
            cc++;
        }
    }
    cout << cc;
    return 0;
}