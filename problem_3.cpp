#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// is_prime returns true is the int is prime
bool is_prime(int p) {

    for (int i = 2; i <= sqrt(p); ++i) {
        if (p % i == 0) {
            return false;
            break;
        }
    }
    return true;
}

// Clean this shit up...I apologize for shitty code
// Calculates the prime factors of first
int main() {

    long first = 600851475143;
    int next = 0;
    int i = 2;
    vector<int> results;

    do {
        if (first % i == 0){
            results.push_back(i);
            first = first/i;
        }
        ++i;
    } while (results.size() == 0);

    if (is_prime(first)) {
        cout << results[0] << endl;
    }

    do {
        if (first % i == 0) {
            results.push_back(i);
            first = first/i;
        }
        ++i;
    } while (results.size() == 1);

    if (is_prime(first)) {
        cout << results[0] << endl << results[1];
    }

    do {
        if (first % i == 0) {
            results.push_back(i);
            first = first/i;
        }
        ++i;
    } while (results.size() == 2);

    if (is_prime(first)) {
        cout << results[0] << endl << results[1] << endl << results[2];
    }

    return 0;

}
