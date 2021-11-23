#pragma once

#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

class Arc {
    void add(int x, int y);
    void add(Point2i * pt);
    public:
    Arc();
    int flag;
    int num;
    std::vector <Point2i*>* data;
};

class Arc_set {
    private:
    int set_num;
    public:
    int gset_num();
    void add_num();
    std::vector <Arc *> * data;
};