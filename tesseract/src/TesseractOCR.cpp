#include "TesseractOCR.h"

TesseractOCR::TesseractOCR()
{
    //ctor
}

TesseractOCR::~TesseractOCR()
{
    //dtor
}

char* TesseractOCR::ReadOCR(cv::Mat Input)
{
    cv::Mat In1;
    In1 = Input;
	cv::Mat gray;
	cv::cvtColor(In1, gray, CV_BGR2GRAY);

	tesseract::TessBaseAPI tess;
	tess.Init(NULL, "eng", tesseract::OEM_DEFAULT);
	tess.SetPageSegMode(tesseract::PSM_SINGLE_BLOCK);
	tess.SetImage((uchar*) gray.data, gray.cols, gray.rows, 1, gray.cols);

	// Get the text
	char* out = tess.GetUTF8Text();
	for (unsigned char ucIndex = 0; *(out + ucIndex) != '\0'; ucIndex++) {
		if (*(out + ucIndex) == '\n' || *(out + ucIndex) == '\r') {
			*(out + ucIndex) = '\0';
			break;
		}
	}

	return (out);

}
