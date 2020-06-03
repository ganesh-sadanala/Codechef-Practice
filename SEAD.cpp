// Learned Sparse table DS

// Refer : Editorial

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vpii vector<pair<int, int>>
//#define N 2e5+5
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define int long long int
#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = l; i < r; i++)
#define sz(a) (int)((a).size())
#define ll long long
#define ar array
#define init(arr) memset(arr, 0, sizeof(arr))

int n, m, t, d, L, R, n1;
const int N = 1e5 + 5;
const int M = 16;
int sp[M][N];
int binarySearch(int arr[])
{
  int ans = 0;
  int l = 0, r = n1;
  while (l <= r)
  {
    int mid = l + (r - l) / 2;
    if (arr[mid] <= t)
    {
      ans = mid;
      l = mid + 1;
    }
    else
      r = mid - 1;
  }
  return ans;
}
void consSparse(int b[])
{
  int p = log2(n1);
  for (int i = 1; i <= p; i++)
  {
    for (int j = 0; (j + (1 << i) - 1) < n1; j++)
    {
      if (b[sp[i - 1][j]] > b[sp[i - 1][j + (1 << (i - 1))]])
        sp[i][j] = sp[i - 1][j];
      else
        sp[i][j] = sp[i - 1][j + (1 << (i - 1))];
    }
  }
}
bool RMQ(int x, int b[])
{

  int l = R - x;
  int ans;
  int p = log2(l);
  // cout<<b[sp[p][x]]<<" "<<b[sp[p][R-(1<<p)]]<<"\n";
  if (b[sp[p][x]] > b[sp[p][R - (1 << p)]])
    ans = (b[sp[p][x]]);

  else
    ans = (b[sp[p][R - (1 << p)]]);

  // cout<<ans<<" "<<d<<"\n";
  if (ans <= d)
    return true;

  return false;
}
void solve()
{
  init(sp);
  cin >> n;
  n1 = n - 1;
  int a[n], b[n1];
  forn(i, n)
          cin >>
      a[i];
  forn(i, n1)
      b[i] = a[i + 1] - a[i];
  cin >> m;
  forn(i, n - 1)
      sp[0][i] = i;
  consSparse(b);

  while (m-- > 0)
  {
    cin >> t >> d;
    R = binarySearch(a);
    int r = R - 1;
    L = 0;
    int l = 0;
    int ans = R;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (RMQ(mid, b))
      {
        ans = mid;
        r = mid - 1;
      }
      else
        l = mid + 1;
    }

    cout << ans + 1 << "\n";
  }
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
