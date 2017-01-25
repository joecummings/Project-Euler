// Circle.cpp takes the inputs of two circles and calculates whether or not they overlap.

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


// Represents a circle on the plane.
struct Circle
{
  double x, y;          // (x, y) is the center
  double radius;
};

// Reads a circle from cin and returns it.
Circle read_circle()
{
  double x, y, r = 0;
  cin >> x >> y >> r;
  Circle c{x,y,r};
  return c;
}

// Determines whether two circles overlap.
bool overlapped(Circle C1, Circle C2)
{
  if(sqrt((C2.x - C1.x)*(C2.x - C1.x) + (C2.y - C1.y)*(C2.y-C1.y)) < (C1.radius + C2. radius)) {
    return true;
  } else {
    return false;
  }
}

// Accepts circle inputs until a negative radius is declared.
int main() {
 
  Circle C = read_circle();
  std::vector<string>results;
 
  for (Circle temp = read_circle(); temp.radius > 0; temp = read_circle()) {
    Circle Ci = temp;
    if (overlapped(C, Ci) == true) {
      results.push_back("overlapped");
    } else {
      results.push_back("not overlapped");
    }
  }

  for(int i = 0; i < results.size(); ++i){
    cout << results[i] << endl;
  }

  return 0;
}
