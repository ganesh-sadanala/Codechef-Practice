// Solved using binary search and preprocess
// Refer : https://discuss.codechef.com/t/richstr-editorial/35161/5?u=ganesh_6

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define N 2e5 + 5
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = l; i < r; i++)
#define sz(a) (int)((a).size())
#define ll long long
#define ar array
#define init(arr) memset(arr, 0, sizeof(arr))

set<int> inx;
void solve()
{
  inx.clear();
  int n, q;
  string s;
  cin >> n >> q >> s;
  forn(i, n - 2)
  {
    if (s[i] == s[i + 1] || s[i] == s[i + 2] || s[i + 1] == s[i + 2])
      inx.insert(i);
  }
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    auto itr = inx.upper_bound(l - 1);
    if (itr != inx.end() && (*itr + 2) <= r)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    solve();
}

// Using prefix array method
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define N 2e5 + 5
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = l; i < r; i++)
#define sz(a) (int)((a).size())
#define ll long long
#define ar array
#define init(arr) memset(arr, 0, sizeof(arr))

void solve()
{
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> v(n, 0);
  fore(i, 2, n)
  {
    if (s[i] == s[i - 1] || s[i] == s[i - 2] || s[i - 1] == s[i - 2])
      v[i] = v[i - 1] + 1;
    else
      v[i] = v[i - 1];
  }
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    if (r - l > 1)
    {
      // Reason: Adding previous cnt too
      if (v[r - 1] - v[l] > 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    else
      cout << "NO\n";
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    solve();
}
