#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>

int main() {
    // Create a Tesseract API object
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

    // Initialize tesseract to use English (you can change language if needed)
    if (api->Init(NULL, "eng")) {
        std::cerr << "Could not initialize tesseract." << std::endl;
        return 1;
    }

    // Open an image file
    Pix *image = pixRead("/Users/arshitadewan/Desktop/receipt.png");
    api->SetImage(image);

    // Get OCR result
    char *outText = api->GetUTF8Text();
    std::cout << "OCR Output: " << outText << std::endl;

    // Clean up
    delete [] outText;
    pixDestroy(&image);
    api->End();
    return 0;
}

