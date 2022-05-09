/**
 * @Author: Your name
 * @Date:   2022-04-18 18:50:41
 * @Last Modified by:   Your name
 * @Last Modified time: 2022-04-19 10:11:35
 */
#include "Debug.hpp"

Debug::Debug(/* args */)
{
    // cout << "construct" << endl;
}

Debug::~Debug()
{
    // cout << "destruct" << endl;
}
// template <typename T>
void Debug::printmn(Mat &src, int m, int n){
    for(int i=m; i<n; i++){
        for( int j=m; j<n; j++){
            cout << (double)src.at<uchar>(i,j) << "\t";
        }
        cout << endl;
    }
    return;
}

void Debug::printshort(Mat &src, int m, int n){
    for(int i=m; i<n; i++){
        for( int j=m; j<n; j++){
            cout << (double)src.at<short>(i,j) << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return;
}