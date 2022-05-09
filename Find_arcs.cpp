/**
 * @Author: Your name
 * @Date:   2021-11-22 14:55:36
 * @Last Modified by:   WU Zihan
 * @Last Modified time: 2022-05-09 20:43:52
 */
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

int Arc_set::size()
{
    return data->size();
}

static const char* window_1 = "1";
static int x,y,a,b,th;
static Mat gss;

static void onChangeTrackBar (int,void*)
{
    Mat dist;
    dist = gss.clone();
    ellipse(dist,Point(x,y),Size(a,b),th,0,360,Scalar(0,255,255),1,LINE_AA);
	imshow(window_1, dist);
}

void Arc_set::generateArcSet(cv::Mat &src /*source file image*/)
{
    // cv::Mat gss;
    GaussianBlur(src, gss, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);
    cv::Mat gray;
	cvtColor(gss,gray,cv::COLOR_BGR2GRAY);

    double rho, reg_angle, prec, p;
    /* angle tolerance */
	prec = M_PI * ang_th / 180.0;
	p = ang_th / 180.0;
	rho = quant / sin(prec); /* gradient magnitude threshold */
    
    // pyrDown(gray,gss,Size(int(src.cols *scale), int(src.rows *scale)));
    cv::Mat gradient[2];
    cv::Mat rotated_grad;
    std::vector<cv::Mat> channels(2);

    int ksize = 1;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    /// Gradient X
    Sobel(gray, channels[1], ddepth, 1, 0, ksize, scale, delta, cv::BORDER_DEFAULT);

    /// Gradient Y
    Sobel(gray, channels[0], ddepth, 0, 1, ksize, scale, delta, cv::BORDER_DEFAULT);

    channels[0] = -channels[0];
    cv::merge(channels, rotated_grad);
    static Debug& debugger = Debug::getInstance();

    cv::Mat grad_abs(gray.rows,gray.cols,CV_16S);

    
    for (auto ita = channels[0].begin<short>(), enda = channels[0].end<short>(), itb = channels[1].begin<short>(), itc = grad_abs.begin<short>(); ita != enda; ++ita, ++itb, ++itc){
        auto temp = (short)sqrt((int)*ita * (int)*ita + (int)*itb * (int)*itb);
        // temp is calculated gradient
        if(temp < rho){
            *itc = NAN;
        }
        else{
            *itc = (short)temp;
        }
    }

    
    // debugger.printmn(gray,200,210);
    // debugger.printshort(channels[0],200,210);
    // debugger.printshort(channels[1],200,210);
    debugger.print<short>(grad_abs,200,210);

    /// Abs to show
    // convertScaleAbs(gradient[0], gradient[0]);
    // convertScaleAbs(gradient[1], gradient[1]);
    std::cout << "rotated_grad channels:" <<rotated_grad.channels() << std::endl;
    std::cout << "channels[0] channels:" <<channels[0].channels() << std::endl;

    std::cout << "rotated_grad size:" <<rotated_grad.size << std::endl;
    std::cout << "channels[0] size:" <<channels[0].size << std::endl;
    std::cout << "channels[1] size:" <<channels[1].size << std::endl;
    // gradient[0].size.p
    /*
	const char* window_1 = "1";
    const char* window_2 = "2";
    const char* window_3 = "3";
    const char* trackx = "x";
    const char* tracky = "y";
    const char* tracka = "a";
    const char* trackb = "b";
    const char* trackth = "th";
    x = 200;
    y = 200;
    a = 200;
    b = 100;
    th = 0;
    
    
    namedWindow( window_1, WINDOW_AUTOSIZE );
    createTrackbar (trackx,window_1,&x,gray.cols,
					onChangeTrackBar);
    createTrackbar (tracky,window_1,&y,gray.rows,
					onChangeTrackBar);
    createTrackbar (tracka,window_1,&a,gray.cols,
					onChangeTrackBar);
    createTrackbar (trackb,window_1,&b,gray.rows,
					onChangeTrackBar);
    createTrackbar (trackth,window_1,&th,360,
					onChangeTrackBar);
    onChangeTrackBar(0,0);
    
    while (cv::waitKey(0) != 'q')
    {

    }
    return;
    */

}