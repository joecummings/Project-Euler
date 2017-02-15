#include "parsing.h"
#include "interface.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int parse_int(const string& s) {

    std::vector<string> ords = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    size_t l = s.length();
    int final = 0;

    if (s.length() == 0)
        throw runtime_error("s not non-negative integer");

    if (s.at(0) == ('-'))
        throw runtime_error("s not a non-negative integer");

    for (int i = 0; i < l; ++i) {
        if ((0 == s.compare(i, 1, "0") ||
             0 == s.compare(i, 1, "1") ||
             0 == s.compare(i, 1, "2") ||
             0 == s.compare(i, 1, "3") ||
             0 == s.compare(i, 1, "4") ||
             0 == s.compare(i, 1, "5") ||
             0 == s.compare(i, 1, "6") ||
             0 == s.compare(i, 1, "7") ||
             0 == s.compare(i, 1, "8") ||
             0 == s.compare(i, 1, "9"))) {
            for (int j = 0; j < 10; ++j) {
                if (0 == s.compare(i, 1, ords[j])) {
                    final *= 10;
                    final += j;
                }
            }
        } else {
            throw runtime_error("s not a non-negative integer");
        }

    }
    return final;
}

vector<string> tokenize(const string& line)
{
    vector<string> final;
    int size_final = 0;
    int q = 0;

    for (int i = 0; i < line.length(); ++i) {
        if (line.at(i) == '\"') {
            q += 1;
        }
    };

    if (q % 2 != 0) {
        throw runtime_error("unbalanced number of quotation marks");
    }

    for (size_t i = 0; i < line.length(); ++i) {
        if (line.at(i)  == '\"') {
            int j;
            if (i + 1 == line.length()) {
                return final;
            } else {
                j = i + 1;
            }
             do {
                if (line.at(j) == '\"'){
                    final.push_back(line.substr(i,(j-i)));
                }
                j++;
            } while (final.size() == size_final);
            size_final += 1;
            i = j - 1;
        } else if (line.at(i) != ' ') {
            int j;
            if (i + 1 == line.length()) {
                return final;
            } else {
                j = i + 1;
            }
            do {
                if (line.at(j) == ' ' || line.at(j) == '\"') {
                    final.push_back(line.substr(i, (j - i)));
                }
                j++;
            } while (final.size() == size_final);
            size_final += 1;
            i = j - 1;
        }
    }
    return final;
}
