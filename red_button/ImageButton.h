#pragma once

#include <QPushButton>
#include <QPixmap>
#include <QMediaPlayer>
#include <QMediaContent>

class ImageButton: public QPushButton{
    Q_OBJECT

public:
    QMediaPlayer* player = nullptr;
    QMediaContent sound;
public:
    ImageButton() = default;
    ImageButton(QWidget* parent);
    void paintEvent(QPaintEvent* e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent* e) override;

public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown = false;
};
