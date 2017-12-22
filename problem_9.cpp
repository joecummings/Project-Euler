#include <iostream>

using namespace std;

int main() {
  int temp = 0;
  long result;
  
  for (int i = 0; i < 1000; i++)
  {
    for (int j = i; j < i+1000; j++)
    {
      for (int k = j; k < j+1000; k++)
      {
        int a = i*i;
        int b = j*j;
        int c = k*k;
        if ((a + b) == c)
        {
          if ((i + j + k) == 1000)
          {
            result = i*j*k;
          }
        }
      }
    }
  }
  cout << result;
}
