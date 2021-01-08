#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int
void update(ll dp[], int n, int x, ll val)
{
    for (; x <= n; x += (x & (-x)))
        dp[x] = (dp[x] + val);
}
ll pre(ll dp[], int n, int x)
{
    ll sum = 0;
    for (; x > 0; x -= x & (-x))
        sum = (sum + dp[x]) % M;
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i, k;
    ll x;
    cin >> n;
    ll dp[n + 1] = {0};
    for (i = 1; i <= n; i++)
    {
        cin >> k;
        x = pre(dp, n, i);
        if (i == 1)
            x = 1;
        update(dp, n, i + 1, x);
        update(dp, n, i + k + 1, -x);
    }
    cout << pre(dp, n, n);

    return 0;
}