#pragma once

#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

class Arc {
    private:
    // memeber
    int flag;
    
    public:
    // member
    std::vector<Point2i*> points;
    

    // function
    Arc (int);
    int getFlag();
    void setFlag(int);
    int size();
    Point2i* & operator[](int i){
       return points[i];
    } // [] reference
};

class Arc_set {
    private:

    public:
    void append(Arc *);
    void size();
    std::vector <Arc *> * data;
};