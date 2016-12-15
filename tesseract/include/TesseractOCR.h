#ifndef TESSERACTOCR_H
#define TESSERACTOCR_H


#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <tesseract/baseapi.h>

using namespace cv;

class TesseractOCR
{
    public:
        TesseractOCR();
        char* ReadOCR(cv::Mat Input);
        virtual ~TesseractOCR();
};


#endif // TESSERACTOCR_H
