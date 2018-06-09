using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class MainClass {

  public static bool isPalindrome(double num){
    string ns = num.ToString();
    char[] a1 = new char[ns.Length];
    char[] a2 = new char[ns.Length];

    for (int i = 0; i < ns.Length; i++){
      a1[i] = ns[i];
    }

    Array.Copy(a1, a2, ns.Length);
    Array.Reverse(a2);

    for (int i = 0; i < ns.Length; i++){
      if (a1[i] != a2[i]){
        return false;
      }
    }
    return true;
  }

  public static void Main (string[] args) {
    IEnumerable<int> nums_1 = Enumerable.Range(100, 899);
    IEnumerable<int> nums_2 = Enumerable.Range(100,899);

    double max = 0;
    foreach (int n_1 in nums_1){
      foreach (int n_2 in nums_2){
        double o1 = n_1 * n_2;
        if (isPalindrome(o1)){
          if (o1 > max) {
            max = o1;
          }
        }
      }
    }

    Console.WriteLine(max);
  }
}
