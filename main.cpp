#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <limits.h>
#include <float.h>
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Eigenvalues>
#include "Find_arcs.hpp"

using Eigen::MatrixXd;
using namespace Eigen;
using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    cout << "Built with OpenCV " << CV_VERSION << endl;
	CommandLineParser parser(argc, argv, "{@input | /Users/zihanwu/ellipseDetectionplus/pics/666.jpg | input image}");
    string filename;
	filename = parser.get<String>("@input");
	cout << filename << endl;
	Mat src = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR);

    Arc arc1( 1 );
    cout << arc1.getFlag() << endl;

    

	Mat gray;
	cvtColor(src,gray,COLOR_BGR2GRAY);
    const char* source_window = "Source";
    namedWindow( source_window );
    imshow(source_window,gray);
    while (waitKey(0) != 'q'){

    }
    return 0;
}