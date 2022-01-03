#include "BlurImage.h"
#include "ui_blur_image.h"

#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QPainter>

#include <QFileDialog>

BlurImage::BlurImage(QMainWindow* parent): QMainWindow(parent){
    Ui::MainWindow ui;
    ui.setupUi(this);
    imageLabel = ui.imageLabel;
    blurRadius = ui.blurRadius;
    openFileButton = ui.openFileButton;

    QObject::connect(openFileButton, &QPushButton::clicked, this, &BlurImage::openFile);
    QObject::connect(blurRadius, &QSlider::sliderMoved, this, &BlurImage::sliderMove);
}

QImage BlurImage::blur_image(QImage source, int blurRadius){        //наложение Blur-эффект
    if(source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    auto* blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage resilt(source.size(), QImage::Format_ARGB32);
    resilt.fill(Qt::transparent);
    QPainter painter(&resilt);
    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));
    return resilt;
}

void BlurImage::drawImage(QString sourceImage){                 //вывод изображения
    if(sourceImage.isEmpty()) return;
    imageLabel->setPixmap(QPixmap::fromImage(blur_image(QImage(sourceImage), blurRadius->value()).scaled(
                                        imageLabel->width(),
                                        imageLabel->height(), Qt::KeepAspectRatio)));
}

void BlurImage::openFile(){                                    //открытие изображения
    filePath = QFileDialog::getOpenFileName(nullptr, "Open image file", "", "Image Files (*.jpg , *.png)");
    this->drawImage(filePath);
}

void BlurImage::sliderMove(){                                  //перемещение слайдера
    this->drawImage(filePath);
}
