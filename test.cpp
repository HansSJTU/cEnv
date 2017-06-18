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
#include <boost/filesystem.hpp>

using namespace std;
using namespace cv;

DEFINE_int32(threads, 8, "Thread count");
DEFINE_string(glog_dir, "./log/", "The output log dir");

int main(int argc, char* argv[])
{
    google::ParseCommandLineFlags(&argc, &argv, true);
    google::InitGoogleLogging(argv[0]);

    google::SetStderrLogging(google::INFO);
    if (!boost::filesystem::exists(FLAGS_glog_dir))
    {
        boost::filesystem::create_directories(FLAGS_glog_dir);
    }
    google::SetLogDestination(google::GLOG_INFO, (FLAGS_glog_dir + "/log_info_").c_str());
    google::SetLogDestination(google::GLOG_WARNING, (FLAGS_glog_dir + "/log_warning_").c_str());
    google::SetLogDestination(google::GLOG_ERROR, (FLAGS_glog_dir + "/log_error_").c_str());
    google::SetLogDestination(google::GLOG_FATAL, (FLAGS_glog_dir + "/log_fatal_").c_str());
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

    boost::filesystem::path p("/usr/include/boost/filesystem.hpp");
    LOG(INFO) << p.string();
    LOG(INFO) << p.parent_path().string();
    LOG(INFO) << p.stem();
    LOG(INFO) << p.filename();
    LOG(INFO) << p.extension();
    LOG(INFO) << boost::filesystem::change_extension("test.c", "so");

    LOG(INFO) << boost::filesystem::exists(p);
    LOG(INFO) << boost::filesystem::is_directory(p);

    int i = 0;
#pragma omp parallel for private(i)
    for (i = 0; i < 10000; i++)
    {
        for (int k = 0; k < 10000000; k++)
        {
            if (k == 10000000 - 1)
                LOG(INFO) << i;
        }
    }
    
    google::ShutdownGoogleLogging();
    return 0;
}
