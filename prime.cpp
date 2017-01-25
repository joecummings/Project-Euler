#include <iostream>
#include <cmath>
using namespace std;

// Determines whether the given number is prime.
bool is_prime(int p) {

  for (int i = 2; i <= sqrt(p); ++i) {
    if (p % i == 0) {
      return false;
      break;
    } 
  }
  return true;
}

// Print all prime numbers between 2 and int n.
int main() {
 
  int n = 0;
  cin >> n;

  for (int i = 2; i <= n; ++i) {
    if (is_prime(i) == true) {
      cout << i << endl; 
    }
  }
  
  return 0;
}
