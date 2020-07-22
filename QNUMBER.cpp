// Refer : CodeNCode
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl "\n"

unordered_map<ll, ll> fac;
ll total = 1;
void factorize(ll n)
{
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      int cnt = 0;
      while (n % i == 0)
      {
        cnt++;
        n /= i;
      }
      fac[i] = cnt;
      total *= (cnt + 1);
    }
  }
  if (n > 1)
  {
    fac[n] = 1;
    total *= 2;
  }
}
void solve()
{
  ll n, q;
  cin >> n >> q;
  factorize(n);
  while (q--)
  {
    ll t, k;
    cin >> t >> k;
    if (t == 1)
    {
      ll res = 1;
      for (pair<ll, ll> p : fac)
      {
        ll cnt = 0;
        while (k % p.first == 0)
        {
          k /= p.first;
          cnt++;
        }
        res *= min(cnt, p.second) + 1;
      }
      cout << res << endl;
    }
    if (t == 2)
    {
      ll res = 1;
      for (pair<ll, ll> p : fac)
      {
        ll cnt = 0;
        while (k % p.first == 0)
        {
          k /= p.first;
          cnt++;
        }
        if (cnt > p.second)
        {
          res = 0;
          break;
        }
        res *= (p.second - cnt + 1);
      }
      // k can't divide
      if (k > 1)
        res = 0;
      cout << res << endl;
    }
    if (t == 3)
    {
      ll res = 1;
      for (pair<ll, ll> p : fac)
      {
        ll cnt = 0;
        while (k % p.first == 0)
        {
          k /= p.first;
          cnt++;
        }
        if (cnt > p.second)
        {
          res = 0;
          break;
        }
        res *= (p.second - cnt + 1);
      }
      // k can't divide
      if (k > 1)
        res = 0;
      cout << (total - res) << endl;
    }
  }
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  solve();
}
