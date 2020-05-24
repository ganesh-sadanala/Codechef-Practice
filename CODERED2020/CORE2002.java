/* package codechef; // don't place package name! */
// Refer : Other submissions

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
  public static void main(String[] args) throws java.lang.Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(bf.readLine());
    while (t-- > 0) {
      int n = Integer.parseInt(bf.readLine());
      String s[] = bf.readLine().trim().split("\\s+");
      System.out.println(Math.max(Integer.parseInt(s[0]), Integer.parseInt(s[n - 1])));
    }
  }
}
