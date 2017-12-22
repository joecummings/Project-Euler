#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main () {
    vector<int> squares;
    vector<int> sums;
    int sum_of_squares;
    int square_of_sums;

    for (int i = 1; i <= 100; ++i) {
        int sqr_num = pow(i,2);
        squares.push_back(sqr_num);
    }

    for (int i = 0; i < squares.size(); ++i) {
        sum_of_squares += squares[i];
    }

    for (int i = 1; i <= 100; ++i) {
        sums.push_back(i);
    }

    for (int i = 0; i < sums.size(); ++i){
        square_of_sums += sums[i];
    }

    square_of_sums = pow(square_of_sums,2);

    int ans = square_of_sums - sum_of_squares;

    cout << ans;

    return 0;
}

