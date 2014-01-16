#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class engine
{
    public:
        engine(int argc, char **argv);
        ~engine();
        int workImage();
        void filterAplied(Mat &image, Mat &mimage, int kernel, int filtro);
        int options(char charcheckforkeypress, int &kernel, int &filtro);
    private:
        VideoCapture cap;
        Mat image;
        Mat mimage;
        Mat edges;
        int argc;
        char **argv;
};

#endif // ENGINE_H
