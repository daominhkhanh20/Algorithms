#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define N 10000
#define ll long long
vector<ii> a[N];
vector<int> marked;
ll totalCost;
int n, m;

void Prim()
{
    marked.assign(n + 1, false);
    priority_queue<ii, vector<ii>, greater<ii>> q;
    int s = 1; //the vertex start
    q.push(ii(0, 1));
    while (q.size())
    {
        ii temp = q.top();
        q.pop();
        int u = temp.second;

        if (marked[u])
        {
            continue;
        }
        marked[u] = true;
        totalCost += temp.first;

        for (int i = 0; i < a[u].size(); ++i)
        {
            int y = a[u][i].second;
            if (!marked[y])
            {
                q.push(a[u][i]);
            }
        }
    }
}
int main()
{
    int x, y;
    ll cost;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> cost;
        a[x].push_back(ii(cost, y));
        a[y].push_back(ii(cost, x));
    }
    Prim();
    cout << totalCost;
    return 0;
}
