
#include <videoplayer.h>



VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent),ui(new Ui::VideoPlayer),_media(0)
{
    ui->setupUi(this);

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->video);

    ui->video->setMediaPlayer(_player);
    ui->seek->setMediaPlayer(_player);

    connect(ui->actionOpenLocal, SIGNAL(triggered()), this, SLOT(openLocal()));
    connect(ui->actionOpenUrl, SIGNAL(triggered()), this, SLOT(openUrl()));
    connect(ui->openLocal, SIGNAL(clicked()), this, SLOT(openLocal()));
    connect(ui->openUrl, SIGNAL(clicked()), this, SLOT(openUrl()));
}

VideoPlayer::~VideoPlayer()
{
    delete _player;
    delete _media;
    delete _instance;
    delete ui;
}

void VideoPlayer::openLocal()
{
    QString file =
            QFileDialog::getOpenFileName(this, tr("Open file"),
                                         QDir::homePath(),
                                         tr("Multimedia files(*)"));
    if (file.isEmpty())
        return;
    _media = new VlcMedia(file, true, _instance);
    _player->open(_media);
}

void VideoPlayer::openUrl()
{
    QString url =
            QInputDialog::getText(this, tr("Open Url"), tr("Enter the URL you want to play"));
    if (url.isEmpty())
        return;
    _media = new VlcMedia(url, _instance);
    _player->open(_media);
}
