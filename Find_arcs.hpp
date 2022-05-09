#pragma once
#include <math.h>
#include <vector>
// #include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>
#include "Debug.hpp"
using namespace cv;
// using namespace std;
class Arc {
    private:
    // memeber
    int flag; // other words, name
    
    public:
    // member
    std::vector<cv::Point2i*> points;


    // function
    Arc (int);
    int getFlag();
    void setFlag(int);
    int size();
    cv::Point2i* & operator[](int i){
       return points[i];
    } // [] reference
};

class Arc_set {
    private:
    double scale = 0.5;		  /* Scale the image by Gaussian filter to 'scale'. */
	/*double sigma_scale = 0.6; Sigma for Gaussian filter is computed as
                                sigma = sigma_scale/scale.                    */
	double quant = 2.0;		  /* Bound to the quantization error on the
                                gradient norm.                                */
	double ang_th = 22.5;	  /* Gradient angle tolerance in degrees.           */
	double log_eps = 0.0;	  /* Detection threshold: -log10(NFA) > log_eps     */
	double density_th = 0.7;  /* Minimal density of region point2is in rectangle. */
	int n_bins = 1024;		  /* Number of bins in pseudo-ordering of gradient
                               modulus. */
    public:
    Arc_set() {};
    void append(Arc *);
    int size();
    std::vector <Arc *> * data;
    void generateArcSet(cv::Mat &src); // generate all arcs
    /**
     * @brief generate all arcs from source image
     * 1. Guass blur 
     * 2. gray
     * 3. caluculate gradient
     * 4. get rotated gradient map
     * 
     */
};

// class 