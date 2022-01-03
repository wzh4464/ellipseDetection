#include "Find_arcs.hpp"



Arc::Arc(int _flag)
{
    this->flag = _flag;
}

int Arc::getFlag()
{
    return flag;
}

void Arc::setFlag( int _flag )
{
    this->flag = _flag;
}

int Arc::size()
{
    return points.size();
}

void Arc_set::append(Arc * arc)
{
    data->insert(data->end(),arc);
}

void Arc_set::generateArcSet(Mat &src /*source file image*/)
{
    Mat gss;
    GaussianBlur(src, gss, Size(3, 3), 0, 0, BORDER_DEFAULT);
    Mat gray;
	cvtColor(gss,gray,COLOR_BGR2GRAY);

    double rho, reg_angle, prec, p;
    /* angle tolerance */
	prec = M_PI * ang_th / 180.0;
	p = ang_th / 180.0;
	rho = quant / sin(prec); /* gradient magnitude threshold */
    
    // pyrDown(gray,gss,Size(int(src.cols *scale), int(src.rows *scale)));
    Mat gradient[2];
    Mat gradd;

    int ksize = 1;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    /// Gradient X
    
    Sobel(gray, gradient[0], ddepth, 1, 0, ksize, scale, delta, BORDER_DEFAULT);

    /// Gradient Y
    Sobel(gray, gradient[1], ddepth, 0, 1, ksize, scale, delta, BORDER_DEFAULT);
    Sobel(gray, gradd, 3, 1, 1);
    
    // Mat grad;
    // merge(gradient, 2 ,grad);

    // Mat subtr;
    // subtract(grad, gradd, subtr);
    // cout << subtr << endl;


    // Mat grad(Size(gray.rows,gray.cols),CV_32FC3);
    // for (int i=0; i<gray.rows; i++)
    //     for(int j=0; j<gray.cols; j++)
    //     {
    //         grad.at<double>(i,j)[0] = 
    //     }
    // cout << gradd << endl;
	const char* window_1 = "1";
    const char* window_2 = "2";
    const char* window_3 = "3";
    // namedWindow( window_1 );
    // namedWindow( window_2 );
    // namedWindow( window_3 );
    imshow(window_1, gradient[0]);
    imshow(window_2, gradient[1]);
    imshow(window_3, gradd);
    while (waitKey(0) != 'q')
    {

    }	
}