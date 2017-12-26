#include <iostream>

using namespace std;

long collatz(long p)
{
  if (p % 2 == 0)
  {
    return (p/2);
  } else 
  {
    return ((3 * p) + 1);
  }
}

int main() 
{
  int largest = 0;
  int final = 0;
  
  for (int i = 13; i < 1000000; i++)
  {
    int count = 1;
    long result = i;
  
    while (result != 1)
    {
      long temp = collatz(result);
      result = temp;
      count++;
    }
    
    if (count > largest)
    {
      largest = count;
      final = i;
      cout << final << " " << count << endl;
    }
    
  }
  
  cout << "FINAL: " << final << endl;
  
}
