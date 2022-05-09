// /**
//  * @Author: Your name
//  * @Date:   2022-04-18 18:50:41
//  * @Last Modified by:   WU Zihan
//  * @Last Modified time: 2022-05-09 20:44:14
//  */
#include "Debug.hpp"

Debug::Debug(/* args */)
{
    // cout << "construct" << endl;
}

Debug::~Debug()
{
    // cout << "destruct" << endl;
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