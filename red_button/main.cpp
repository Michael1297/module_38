#include <QApplication>
#include "ImageButton.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ImageButton button(nullptr);
    button.setFixedSize(100, 100);
    button.move(1000, 400);
    button.show();    
    return QApplication::exec();
}
