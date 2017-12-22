#include <iostream>

using namespace std;

// This function find the sum of all numbers less than 1000 that are divisible by 3 or 5
int main()
{
    int result = 0;

    for (int i = 0; i < 1000; ++i){
        if ((i % 3 == 0) || (i % 5 == 0)) {
            result = result + i;
        }
    }
    cout << result;
}



