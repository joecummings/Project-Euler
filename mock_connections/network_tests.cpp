#include "errors.h"
#include "parsing.h"
#include "datagram.h"

#include <UnitTest++/UnitTest++.h>
#include <memory>
#include <iostream>
#include <stdexcept>

using namespace std;

#define CHECK_THROW_ENUM(expression, EnumType, EnumValue) \
   UNITTEST_MULTILINE_MACRO_BEGIN \
   bool caught_ = false; \
   try { expression; } \
   catch (EnumType e) { caught_ = e == EnumType::EnumValue; } \
   catch (...) {} \
   if (!caught_) \
      UnitTest::CurrentTest::Results()->OnTestFailure( \
          UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), \
                                __LINE__), \
          "Expected exception: \"" #EnumValue "\" not thrown"); \
   UNITTEST_MULTILINE_MACRO_END

void CHECK_VECTOR_EQUAL(vector<string> V1, vector<string> V2) {
    CHECK_EQUAL(V1.size(), V2.size());
    if (V1.size() != V2.size())
        return;
    for (int ii = 0; ii < V1.size(); ii++) {
        CHECK_EQUAL(V1[ii], V2[ii]);
    }
}

void CHECK_IP_EQUAL(IP_address IP1, IP_address IP2) {
    for (int ii = 0; ii < IP1.size(); ii++) {
        CHECK_EQUAL(IP1[ii], IP2[ii]);
    }
}

TEST(TOKENIZE){
    string test  = "asd asd \"something @ asd\" woah";
    vector<string> test_result = {"asd", "asd", "something @ asd", "woah"};
    vector<string> output  = tokenize(test);

    CHECK_EQUAL(test_result[0],output[0]);
    CHECK_EQUAL(test_result.size(), output.size());
    CHECK_VECTOR_EQUAL(test_result,output);

    string test2 = "";
    vector<string> test_result_2 = {};
    vector<string> output_2 = tokenize(test);
    CHECK_VECTOR_EQUAL(test_result_2,output_2);

    string error  = "q count \" out of place";
    string error1 = "\"";
    CHECK_THROW(tokenize(error), runtime_error);
    CHECK_THROW(tokenize(error1), runtime_error);
}


TEST(PARSE_INT){
    string test   = "101";
    string test1  = "2";
    string test2 = "00222";
    int output    = parse_int(test);
    int output_1   = parse_int(test1);
    int output_2   = parse_int(test2);
    CHECK_EQUAL(101,output);
    CHECK_EQUAL(2,output_1);
    CHECK_EQUAL(222,output_2);

    string error  = "-101";
    string error1 = "string";
    string error2 = "1afd3";
    string error3 = "";
    CHECK_THROW(parse_int(error),runtime_error);
    CHECK_THROW(parse_int(error1),runtime_error);
    CHECK_THROW(parse_int(error2),runtime_error);
    CHECK_THROW(parse_int(error3),runtime_error);
}
TEST(PARSE_IP){
    string test        = "182.000.0.5";
    string test1       = "231234.12345.123456.12345";
    string test2       = "0.0.0.0";
    IP_address output  = {182, 000, 0, 5};
    IP_address output1 = {231234, 12345, 123456, 12345};
    IP_address output2 = {0, 0, 0, 0};
    IP_address IP      = parse_IP(test);
    IP_address IP1     = parse_IP(test1);
    IP_address IP2     = parse_IP(test2);

    CHECK_IP_EQUAL(output,IP);
    CHECK_IP_EQUAL(output1,IP1);
    CHECK_IP_EQUAL(output2,IP2);

}

TEST(PARSE_IP_ERROR){
    string error  = "182.000.0.5.25.1";
    string error1 = "not an ip address";

    CHECK_THROW_ENUM(parse_IP(error),err_code,bad_ip_address);
    CHECK_THROW_ENUM(parse_IP(error1),err_code,bad_ip_address);
}
