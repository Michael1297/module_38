#include <QApplication>
#include "BlurImage.h"
#include "ui_blur_image.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    BlurImage window(nullptr);    

    window.show();
    return QApplication::exec();
}
