#include <iostream>
#include <vector>

using namespace std;

// This function sums up the even-valued terms in the Fibonacci sequence whose
// values do not exceed four million
int main()
{
    vector<int>fibonacci;
    int i = 0;
    int add = 0;

    do {
        if (i == 0) {
            fibonacci.push_back(1);
        } else {
            add = fibonacci[(i - 1)] + fibonacci[(i-2)];
            fibonacci.push_back(add);
        }
        i++;
    } while (add < 4000000);

    int result = 0;

    for (int p = 0; p < fibonacci.size(); ++p) {
        if (fibonacci[p] % 2 == 0) {
            result = result + fibonacci[p];
        }
    }

    cout << result << endl;

    return 0;
}
