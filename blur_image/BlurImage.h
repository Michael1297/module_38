#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QImage>

class BlurImage : public QMainWindow{
    Q_OBJECT

public:
    QLabel* imageLabel = nullptr;
    QSlider* blurRadius = nullptr;
    QPushButton* openFileButton = nullptr;
    BlurImage(QMainWindow* parent = nullptr);
    void openFile();
    void sliderMove();

private:
    QString filePath;                                                   //ссылка на файл
    QImage blur_image(QImage source, int blurRadius);                   //наложение Blur-эффект
    void drawImage(QString sourceImage);                                 //вывод изображения
};
