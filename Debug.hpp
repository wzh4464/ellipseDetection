#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

// Single Object

using cv::Mat;
using std::cout;
using std::endl;
class Debug
{
private:
    // static Debug instance;
    Debug(/* args */);
    ~Debug();
    Debug(const Debug&)=delete;
    Debug &operator=(const Debug&);
public:
    static Debug& getInstance(){
        static Debug debugger;
        return debugger;
    }
    // template <typename T> 
    void printmn(Mat&,int m=0,int n=5);
    void printshort(Mat&,int m=0,int n=5);
};

