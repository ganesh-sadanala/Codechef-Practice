/* package codechef; // don't place package name! */
// Top down : www.codechef.com/viewsolution/30320870

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
  static int n, m;
  static long dp[][][];
  static int x[] = { 2, 2, 1, 1 };
  static int y[] = { 1, -1, 2, -2 };
  static long mod = (long) 1e9 + 7l;

  static boolean isValid(int p, int q) {
    return (p >= 1 && p <= n && q >= 1 && q <= m);
  }

  static long dfs(int i, int j, int f) {
    if (i == n)
      return f;

    if (i <= 0 || i > n || j <= 0 || j > m)
      return 0;

    if (dp[i][j][f] != -1)
      return dp[i][j][f];

    long ans = 0;

    for (int k = 0; k < 4; k++) {
      if (isValid(i + x[k], j + y[k])) {
        ans += dfs(i + x[k], j + y[k], f ^ 1);
        ans %= mod;
      }
    }
    return dp[i][j][f] = ans;
  }

  public static void main(String[] args) throws java.lang.Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    String s[] = bf.readLine().trim().split("\\s+");
    n = Integer.parseInt(s[0]);
    m = Integer.parseInt(s[1]);
    dp = new long[n + 1][m + 1][2];
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++)
        Arrays.fill(dp[i][j], -1);
    }

    long ans = 0;
    for (int i = 2; i <= m; i += 2) {
      ans += dfs(1, i, 0);
      ans %= mod;
    }
    System.out.println(ans);
  }
}
