using System;
using System.Collections.Generic;

class MainClass {

  public static bool isPrime(double num){
    for (double i = 2; i <= Math.Sqrt(num); i++){
      if (num % i == 0){
        return false;
      }
    }
    return true;
  }

  public static double allFactors(double num){
    double p = 1;
    double largest = 0;
    for (double i = 1; i < num+1; i++){
      // discount based on prime number theory
      p -= 0.000001;
      if (p <= 0){
        break;
      }
      if (num % i == 0){
        if (isPrime(i)){
          if (i > largest){
            largest = i;
          }
        }
      }
    }
    return largest;
  }

  public static void Main () {
    Console.WriteLine(allFactors(600851475143));
  }
}
