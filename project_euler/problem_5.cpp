#include <iostream>
#include <vector>

using namespace std;

int main() {

    int result = 0;
    int j = 2521;
    int i = 2;

    do {
        if (j % i == 0) {
            ++i;
            if (i == 20) {
                result = j;
            }
        } else {
            j++;
            i = 2;
        }
    } while (result == 0);

    cout << result;
}


