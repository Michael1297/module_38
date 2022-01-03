#include <QApplication>
#include <QMainWindow>
#include "ui_HTML.h"


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QMainWindow window(nullptr);
    Ui::MainWindow ui;
    ui.setupUi(&window);

    QObject::connect(ui.code, &QPlainTextEdit::textChanged, [&ui]{
        ui.page->setHtml(ui.code->toPlainText());                                               // <H1>Test</H1>
    });

    window.show();

    return QApplication::exec();
}
