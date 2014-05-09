/********************************************************************************
** Form generated from reading UI file 'VideoPlayer.ui'
**
** Created: Fri May 9 17:48:39 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYER_H
#define UI_VIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "vlc-qt/WidgetSeek.h"
#include "vlc-qt/WidgetVideo.h"
#include "vlc-qt/WidgetVolumeSlider.h"

QT_BEGIN_NAMESPACE

class Ui_VideoPlayer
{
public:
    QAction *actionClose;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionOpenLocal;
    QAction *actionOpenUrl;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QPushButton *openLocal;
    QPushButton *openUrl;
    VlcWidgetVideo *video;
    QPushButton *stop;
    QPushButton *pause;
    VlcWidgetVolumeSlider *volume;
    VlcWidgetSeek *seek;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuMedia;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VideoPlayer)
    {
        if (VideoPlayer->objectName().isEmpty())
            VideoPlayer->setObjectName(QString::fromUtf8("VideoPlayer"));
        VideoPlayer->resize(640, 480);
        actionClose = new QAction(VideoPlayer);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionPause = new QAction(VideoPlayer);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionStop = new QAction(VideoPlayer);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionOpenLocal = new QAction(VideoPlayer);
        actionOpenLocal->setObjectName(QString::fromUtf8("actionOpenLocal"));
        actionOpenUrl = new QAction(VideoPlayer);
        actionOpenUrl->setObjectName(QString::fromUtf8("actionOpenUrl"));
        centralwidget = new QWidget(VideoPlayer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        openLocal = new QPushButton(centralwidget);
        openLocal->setObjectName(QString::fromUtf8("openLocal"));

        gridLayout_2->addWidget(openLocal, 0, 0, 1, 1);

        openUrl = new QPushButton(centralwidget);
        openUrl->setObjectName(QString::fromUtf8("openUrl"));

        gridLayout_2->addWidget(openUrl, 0, 1, 1, 1);

        video = new VlcWidgetVideo(centralwidget);
        video->setObjectName(QString::fromUtf8("video"));

        gridLayout_2->addWidget(video, 1, 0, 1, 2);

        stop = new QPushButton(centralwidget);
        stop->setObjectName(QString::fromUtf8("stop"));

        gridLayout_2->addWidget(stop, 3, 1, 1, 1);

        pause = new QPushButton(centralwidget);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setCheckable(true);

        gridLayout_2->addWidget(pause, 3, 0, 1, 1);

        volume = new VlcWidgetVolumeSlider(centralwidget);
        volume->setObjectName(QString::fromUtf8("volume"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(volume->sizePolicy().hasHeightForWidth());
        volume->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(volume, 4, 0, 1, 2);

        seek = new VlcWidgetSeek(centralwidget);
        seek->setObjectName(QString::fromUtf8("seek"));
        sizePolicy.setHeightForWidth(seek->sizePolicy().hasHeightForWidth());
        seek->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(seek, 5, 0, 1, 2);

        VideoPlayer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VideoPlayer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuMedia = new QMenu(menubar);
        menuMedia->setObjectName(QString::fromUtf8("menuMedia"));
        VideoPlayer->setMenuBar(menubar);
        statusbar = new QStatusBar(VideoPlayer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        VideoPlayer->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuMedia->menuAction());
        menuFile->addAction(actionOpenLocal);
        menuFile->addAction(actionOpenUrl);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuMedia->addAction(actionPause);
        menuMedia->addAction(actionStop);

        retranslateUi(VideoPlayer);
        QObject::connect(actionClose, SIGNAL(triggered()), VideoPlayer, SLOT(close()));

        QMetaObject::connectSlotsByName(VideoPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *VideoPlayer)
    {
        VideoPlayer->setWindowTitle(QApplication::translate("VideoPlayer", "Demo Player", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("VideoPlayer", "Close", 0, QApplication::UnicodeUTF8));
        actionPause->setText(QApplication::translate("VideoPlayer", "Pause", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("VideoPlayer", "Stop", 0, QApplication::UnicodeUTF8));
        actionOpenLocal->setText(QApplication::translate("VideoPlayer", "Open local file", 0, QApplication::UnicodeUTF8));
        actionOpenUrl->setText(QApplication::translate("VideoPlayer", "Open URL", 0, QApplication::UnicodeUTF8));
        openLocal->setText(QApplication::translate("VideoPlayer", "Open local file", 0, QApplication::UnicodeUTF8));
        openUrl->setText(QApplication::translate("VideoPlayer", "Open URL", 0, QApplication::UnicodeUTF8));
        stop->setText(QApplication::translate("VideoPlayer", "Stop", 0, QApplication::UnicodeUTF8));
        pause->setText(QApplication::translate("VideoPlayer", "Pause", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("VideoPlayer", "File", 0, QApplication::UnicodeUTF8));
        menuMedia->setTitle(QApplication::translate("VideoPlayer", "Media", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VideoPlayer: public Ui_VideoPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYER_H
