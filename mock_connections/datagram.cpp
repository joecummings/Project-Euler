#include "datagram.h"
#include "parsing.h"
#include "errors.h"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

IP_address parse_IP(string s)
{
    array<int, 4> final;
    std::vector<int> temp;
    string ts = s;
    string n;

    for (unsigned i = 0; i < s.length(); ++i) {
        if (0 == s.compare(i, 1, ".")) {
            n.append(" ", i);
        } else if (!(0 == s.compare(i, 1, "0") ||
                             0 == s.compare(i, 1, "1") ||
                             0 == s.compare(i, 1, "2") ||
                             0 == s.compare(i, 1, "3") ||
                             0 == s.compare(i, 1, "4") ||
                             0 == s.compare(i, 1, "5") ||
                             0 == s.compare(i, 1, "6") ||
                             0 == s.compare(i, 1, "7") ||
                             0 == s.compare(i, 1, "8") ||
                             0 == s.compare(i, 1, "9"))) {
            throw err_code::bad_ip_address;
        } else {
            n.append(s.at(i), i);
        }
    }

    std::vector<string> num = tokenize(n);

    if (num.size() != 4)
        throw err_code::bad_ip_address;

    temp.push_back(parse_int(num[0]));
    temp.push_back(parse_int(num[1]));
    temp.push_back(parse_int(num[2]));
    temp.push_back(parse_int(num[3]));

    for (int j = 0; j < temp.size(); j++) {
        if (true == (255 < temp[j]))
            throw err_code::bad_ip_address;
    }

    for (int i = 0; i < 4; ++i) {
        final[i] = temp[i];
    }

    return final;
}

