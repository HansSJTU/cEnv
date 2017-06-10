/*
 * test.cpp
 * Copyright (C) 2017 Hans <Hans@Hans-MacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

DEFINE_int32(test_int, 1, "This is to test int");
DEFINE_string(test_string, "Test String", "This is to test string");

int main(int argc, char* argv[])
{
    google::ParseCommandLineFlags(&argc, &argv, true);
    google::InitGoogleLogging(argv[0]);

    google::SetStderrLogging(google::INFO);
    google::SetLogDestination(google::GLOG_INFO, "./log/log_info_");
    google::SetLogDestination(google::GLOG_WARNING, "./log/log_warning_");
    google::SetLogDestination(google::GLOG_ERROR, "./log/log_error_");
    google::SetLogDestination(google::GLOG_FATAL, "./log/log_fatal_");
    FLAGS_colorlogtostderr = true;
    FLAGS_logbufsecs = 0;

    Mat image = imread("testImage.png");
    namedWindow("image", CV_WINDOW_AUTOSIZE);
    imshow("image", image);
    
    google::ShutdownGoogleLogging();
    return 0;
}
