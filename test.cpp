/*
 * test.cpp
 * Copyright (C) 2017 Hans <Hans@Hans-MacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <gflags/gflags.h>

using namespace std;

DEFINE_int32(test_int, 1, "This is to test int");
DEFINE_string(test_string, "Test String", "This is to test string");

int main(int argc, char* argv[])
{
    google::ParseCommandLineFlags(&argc, &argv, true);
    cout << "test_int: " << FLAGS_test_int << endl;
    cout << "test_string: " << FLAGS_test_string << endl;
    return 0;
}
