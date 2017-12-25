#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int p) {
    for (int i = 2; i <= sqrt(p); ++i) 
    {
        if (p % i == 0) 
        {
            return false;
        }
    }
    return true;
}

int main() {
  long sum = 0;
  for (int i = 2; i < 2000000; i++)
  {
    if (is_prime(i))
    {
      sum += i;
    }
  }
  
  cout << sum;
}
