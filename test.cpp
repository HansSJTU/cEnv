/*
 * test.cpp
 * Copyright (C) 2017 Hans <Hans@Hans-MacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <fstream>  
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <jsoncpp/json/json.h> 
#include <omp.h> 

using namespace std;
using namespace cv;

DEFINE_int32(threads, 4, "Thread count");
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
    
    omp_set_num_threads(FLAGS_threads);

    // c++ test
    // Mat image = imread("testImage.png");
    // namedWindow("image", CV_WINDOW_AUTOSIZE);
    // imshow("image", image);

    // jsoncpp test
    // ifstream inputFile;
    // inputFile.open("test.json");

    // Json::Reader jsonReader;
    // Json::Value rootValue;
    // if (!jsonReader.parse(inputFile, rootValue))
    //     return -1;

    // LOG(INFO) << rootValue["address"][0]["name"].asString();

    google::ShutdownGoogleLogging();
    return 0;
}
