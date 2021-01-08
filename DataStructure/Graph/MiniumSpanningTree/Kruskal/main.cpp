//using disjoint sets data structure

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100000
//Time complexity O(M*N) fos Disjoint sets
//so the most time for algorithms depended the sort p[]

//You can improve O(MN) into O(M*log(n))in case the union method used rank
//https://en.wikipedia.org/wiki/Disjoint-set_data_structure
pair<ll, pair<int, int>> p[N];
int n, m;
ll minCost;
ll d[N];
void makeSet()
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = i;
    }
}

ll find(int x)
{
    if (x != d[x])
    {
        d[x] = find(d[x]);
    }
    return d[x];
}
void unionXY(int x, int y)
{
    int c = find(x);
    int k = find(y);
    d[c] = d[k];
}
void Kruskal()
{
    makeSet();
    int x, y;
    ll cost;
    for (int i = 0; i < m; ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        if (find(x) != find(y))//O(n)
        {
            minCost += cost;
            unionXY(x, y);//O(n)
        }
    }
}
int main()
{
    int x, y;
    ll dxy;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> dxy;
        p[i] = make_pair(dxy, make_pair(x, y));
    }
    sort(p, p + m);
    Kruskal();
    cout << minCost;
    return 0;
}