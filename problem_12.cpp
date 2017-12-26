#include <iostream>
#include <vector>

using namespace std;

// make a vector full of all the triangle numbers
vector<long long> triangle_num()
{
  int count = 0;
  vector<long long> total;
  
  for (int i = 0; i <= 15000; i++)
  {
    count++;
    int sum = 0;
    for (int j = 0; j <= 15000; j++)
    {
      if (j < count)
      {
        sum += j;
      }
    }
    if (count > 1)
    {
      total.push_back(sum);
    }
  }
  return total;
}

// find the number of divisors for each triangle number
int num_of_divisors(int p)
{
  int count = 0;
  for (int i = 1; i <= p; i++)
  {
    if (p % i == 0)
    {
      count++;
    }
  }
  return count;
}

int main() 
{
  vector<long long> triangles = triangle_num();
  
  for (int i = 0; i < triangles.size(); i++)
  {
    int temp = num_of_divisors(triangles[i]);
    if (temp > 500)
    {
      cout << triangles[i] << endl;
    }
  }
}
