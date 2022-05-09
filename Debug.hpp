#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

// Single Object
using namespace cv;
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
    template <typename T> void print(Mat &,int m=0,int n=5);
    void printshort(Mat & src,int m=0,int n=5);
};


template <typename T> void Debug::print(Mat &src, int m, int n){
    for(int i=m; i<n; i++){
        for( int j=m; j<n; j++){
            cout << (double)src.at<T>(i,j) << "\t";
        }
        cout << endl;
    }
    return;
}