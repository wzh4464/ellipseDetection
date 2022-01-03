#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <limits.h>
#include <float.h>
#include <iostream>
#include <fstream>

#include <eigen3/Eigen/Eigenvalues>
#include "Find_arcs.hpp"

using Eigen::MatrixXd;
using namespace Eigen;
using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    cout << "Built with OpenCV " << CV_VERSION << endl;
    CommandLineParser parser(argc, argv, "{@input | /Users/zihanwu/ellipseDetectionplus/build/data/lena.jpg | input image}");
    string filename;
    filename = parser.get<String>("@input");
    Mat src = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR);
    Arc_set arcSet;
    arcSet.generateArcSet(src);

    return EXIT_SUCCESS;
}