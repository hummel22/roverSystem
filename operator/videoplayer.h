#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMainWindow>
//#include <QtWidgets>
#include <QFileDialog>
#include <QInputDialog>

#include <vlc-qt/Common.h>
#include <vlc-qt/Instance.h>
#include <vlc-qt/Media.h>
#include <vlc-qt/MediaPlayer.h>
#include <ui_VideoPlayer.h>


namespace Ui {
    class VideoPlayer;
}

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

class VideoPlayer : public QMainWindow
{
Q_OBJECT
public:
    explicit VideoPlayer(QWidget *parent = 0);
    ~VideoPlayer();

private slots:
    void openLocal();
    void openUrl();

private:
    Ui::VideoPlayer *ui;

    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;
};

#endif // VIDEOPLAYER_H
