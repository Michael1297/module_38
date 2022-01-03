#include "ImageButton.h"
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>

ImageButton::ImageButton(QWidget* parent) : QPushButton(parent) {
    player = new QMediaPlayer();
    sound = QUrl("qrc:/resources/sound.mp3");
    player->setVolume(100);
    player ->setMedia(sound);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonDownPixmap = QPixmap(":/resources/red_button_down.png");
    mButtonUpPixmap = QPixmap(":/resources/red_button_up.png");
    mCurrentButtonPixmap = mButtonUpPixmap;

    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}

void ImageButton::paintEvent(QPaintEvent* e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const {           //размер виджета
    return QSize(100, 100);
}

QSize ImageButton::minimumSizeHint() const {    //минимальный размер виджета
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent* e) { //реакция на нажатие
    setDown();
}

void ImageButton::setDown() {                   //нажать
    player->stop();
    player->play();
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();                                  //перерисовывает виджет

    QTimer::singleShot(player->duration() , this, &ImageButton::setUp);

}

void ImageButton::setUp() {                    //отпустить
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();                                  //перерисовывает виджет
}
