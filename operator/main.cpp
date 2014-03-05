#include "mainwindow.h"
#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <QProgressBar>
#include <QObject>
#include <QHBoxLayout>
#include <QSlider>
#include "keywindoe.h"
#include <QKeyEvent>
#include "udpwork.h"
#include "mythread.h"
#include <QLabel>
#include <QPushButton>
#include <worker.h>
#include <QPlainTextEdit>
#include <QRadioButton>
#include <hradiobutton.h>
#include <radiolist.h>
#include <receiveswitch.h>
#include <joystickwindow.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <joystickinput.h>
#include <joythread.h>
#include <roverwindow.h>
#include <armwindow.h>
#include <diagnostics.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //TERMINAL WINDOW --------------------------------------------------------------//
    //Create Window
    QWidget *windowAll = new QWidget;
    //Labels and Names
    QLabel *Sent = new QLabel;
    QLabel *Internal = new QLabel;
    QLabel *Received = new QLabel;
    Sent->setText("Terminal: Sent");
    Internal->setText("Terminal: Internal");
    Received->setText("Terminal: Receieved");
    //Windows Titles
    windowAll->setWindowTitle("Terminals");
    //Terminals Objects
    QPlainTextEdit *TerminalInternal = new QPlainTextEdit;
    QPlainTextEdit *TerminalSent = new QPlainTextEdit;
    QPlainTextEdit *TerminalReceived = new QPlainTextEdit;
    TerminalInternal->isReadOnly();
    TerminalSent->isReadOnly();
    TerminalReceived->isReadOnly();
    //Create Layouts
    QGridLayout *layerTerminalAll = new QGridLayout;
    int terminalWidth = 340;
    layerTerminalAll->setColumnMinimumWidth(0,terminalWidth);
    layerTerminalAll->setColumnMinimumWidth(1,terminalWidth);
    layerTerminalAll->setColumnMinimumWidth(2,terminalWidth);
    //Add to Layouts
    layerTerminalAll->addWidget(Internal,0,0);
    layerTerminalAll->addWidget(TerminalInternal,1,0);
    layerTerminalAll->addWidget(Sent,0,1);
    layerTerminalAll->addWidget(TerminalSent,1,1);
    layerTerminalAll->addWidget(Received,0,2);
    layerTerminalAll->addWidget(TerminalReceived,1,2);
    //Add layout to window
    windowAll->setLayout(layerTerminalAll);
    windowAll->setWindowTitle("Terminals");
    //Show Window
    //TERMINAL WINDOW-----------------------------------------------------------------------//




    //WORKERS / SLIDERS / RADIOBUTTONS--------------------------------------------------------------------//
    //Testing
    int NumberOfServors = 9;

    //Create Window containing sliders
    QWidget *windowSlider = new QWidget;
    windowSlider->setWindowTitle("slider");//Contains Sliders

    //Create Socket and Initialize
    UDPwork *mysock = new UDPwork;
    //Thread
    QThread cThread;
    myThread cObject;
    //UDP to Terminals
    QObject::connect(mysock,SIGNAL(UDPtoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(mysock,SIGNAL(UDPtoTerminalSend(QString)),TerminalSent,SLOT(appendPlainText(QString)));
    QObject::connect(mysock,SIGNAL(Received(QString)),TerminalReceived,SLOT(appendPlainText(QString)));

    //Workerall
    WorkerAll *All = new WorkerAll;
    //Rover Driver
    WorkerRover *rWorker = new WorkerRover;

    //Build Workers and Sliders Lists
    QList<Worker*> workerList;
    QList<QSlider*> sliderList;
    QList<HRadioButton*> radioButtonList;

    //KEY INPUT
    keyWindoe *test = new keyWindoe;
    test->setMaximumHeight(200);
    test->setMaximumWidth(200);

    //Radio Controller
    RadioList *myList = new RadioList(test);
    //Connect RadioList to socket
    QObject::connect(myList,SIGNAL(toSend(QString)),mysock,SLOT(Send(QString)));



    //For Loop to build dynamically
    for(int i = 0;i <NumberOfServors;i++)
    {
        //Create each Worker and Slider
        workerList.append(new Worker);
        sliderList.append(new QSlider);
        radioButtonList.append(new HRadioButton);

        radioButtonList.at(i)->initialize(i);
        workerList.at(i)->Initialize(sliderList.at(i),i);

        //Connect to Terminal And Socket
        QObject::connect(workerList.at(i),SIGNAL(WorkerToTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
        QObject::connect(workerList.at(i),SIGNAL(WorkerToSend(QString)),mysock,SLOT(Send(QString)));
        QObject::connect(radioButtonList.at(i),SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
        QObject::connect(radioButtonList.at(i),SIGNAL(clicked(int)),myList,SLOT(RadioReceive(int)));

        //Add Workers to Main Controller [workerALL Class]
        All->addWorker(workerList.at(i));
        myList->addslide(workerList.at(i));
        myList->addButton(radioButtonList.at(i));

    }

    //Create Drive and Arm Objects
    HRadioButton *radioButtonAll = new HRadioButton();
    HRadioButton *radioButtonRover = new HRadioButton();
    radioButtonAll->initialize(NumberOfServors);
    radioButtonRover->initialize(NumberOfServors+1);
    radioButtonAll->setText("All Servos");
    radioButtonRover->setText("Drive Control");
    QObject::connect(radioButtonAll,SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(radioButtonRover,SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    myList->wAll = All;
    myList->wRover = rWorker;
    myList->addButton(radioButtonAll);
    myList->addButton(radioButtonRover);
    QObject::connect(radioButtonAll,SIGNAL(clicked(int)),myList,SLOT(RadioReceive(int)));
    QObject::connect(radioButtonRover,SIGNAL(clicked(int)),myList,SLOT(RadioReceive(int)));
    //WORKERS / SLIDERS / RADIOBUTTONS---------------------------------------------------------------------------//









    //JOYSTICK-------------------------------------------------------------------------------------//
    //Joystick Window
    joystickWindow *jWindow = new joystickWindow;
    jWindow->initialize();
    //Input
    joystickInput *jInput = new joystickInput;
    //Pass Input to Radio List
    myList->joys = jInput;
    //Connections
    QObject::connect(jInput,SIGNAL(axisSet(int,int,int,int,int,int)),jWindow,SLOT(axisSet(int,int,int,int,int,int)));
    QObject::connect(jInput,SIGNAL(buttons(int)),jWindow,SLOT(buttonPress(int)));
    QObject::connect(jInput,SIGNAL(axisSet(int,int,int,int,int,int)),myList,SLOT(axisSet(int,int,int,int,int,int)));
    QObject::connect(jInput,SIGNAL(buttons(int)),myList,SLOT(buttons(int)));
    QObject::connect(jInput,SIGNAL(toInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    //Thread
    QThread jThread;
    joyThread jObject;
    //Connect thread to Terminal
    //Initate Thread
    jObject.jInputs = jInput;
    jObject.DoSetup(jThread);
    jObject.moveToThread(&jThread);
    jThread.start();
    //JOYSTICK-------------------------------------------------------------------------------------//



    //ROVER VIEW
    roverWindow *rWindow = new roverWindow;
    rWindow->intialize();
    myList->rWindow = rWindow;
    QObject::connect(jInput,SIGNAL(buttons(int)),rWindow,SLOT(buttonControl(int)));
    //ROVER VIEW


    //ARM VIEW
    armWindow *arm = new armWindow;
    QObject::connect(sliderList.at(0),SIGNAL(valueChanged(int)),arm,SLOT(Angle1(int)));
    QObject::connect(sliderList.at(1),SIGNAL(valueChanged(int)),arm,SLOT(Angle2(int)));
    QObject::connect(sliderList.at(3),SIGNAL(valueChanged(int)),arm,SLOT(ClawAngle(int)));
    QObject::connect(jInput,SIGNAL(buttons(int)),arm,SLOT(Buttons(int)));
    //ARM VIEW



    //DIAGNOSTICS
    Diagnostics *diag = new Diagnostics;

    //DIAGNOSTICS



    //BUTTONS--------------------------------------------------------------------------------------//
    QPushButton *syncButton = new QPushButton;
    QPushButton *showTerminals = new QPushButton;
    QPushButton *showJoystick = new QPushButton;
    QPushButton *showKeyInput = new QPushButton;
    QPushButton *showRover  = new QPushButton;
    QPushButton *showDiagnostics = new QPushButton;
    showDiagnostics->setText("Diagnostics");
    showRover->setText("Rover View");
    showKeyInput->setText("Key Input");
    syncButton->setText("Sync Servos");
    showTerminals->setText("Terminals");
    showJoystick->setText("Joystick");

    QObject::connect(showTerminals,SIGNAL(clicked()),windowAll,SLOT(show()));
    QObject::connect(syncButton,SIGNAL(clicked()),myList,SLOT(forcesync()));
    QObject::connect(showJoystick,SIGNAL(clicked()),jWindow,SLOT(showBox()));
    QObject::connect(showKeyInput,SIGNAL(clicked()),test,SLOT(show()));
    QObject::connect(showRover,SIGNAL(clicked()),rWindow,SLOT(showRover()));
    //BUTTONS--------------------------------------------------------------------------------------//




    //LAYOUTS--------------------------------------------------------------------------------------//
    QWidget *mainWind = new QWidget;
    QGridLayout *mainLayout = new QGridLayout;
    QGridLayout *leftPanelLayout = new QGridLayout;
    QGridLayout *rightPanelLayout = new QGridLayout;
    QGridLayout *videoPanelLayout = new QGridLayout;
    int columnWidth = 160;
    int rowHeight = 90;
    mainLayout->setColumnMinimumWidth(0,columnWidth);
    mainLayout->setColumnMinimumWidth(1,columnWidth);
    mainLayout->setColumnMinimumWidth(2,columnWidth);
    mainLayout->setColumnMinimumWidth(3,columnWidth);
    mainLayout->setRowMinimumHeight(0,rowHeight);
    mainLayout->setRowMinimumHeight(1,rowHeight);
    mainLayout->setRowMinimumHeight(2,rowHeight);
    mainLayout->setRowMinimumHeight(3,rowHeight);
    //LeftPanel
    leftPanelLayout->addWidget(showTerminals);
    leftPanelLayout->addWidget(syncButton);
    leftPanelLayout->addWidget(showJoystick);
    leftPanelLayout->addWidget(showKeyInput);
    leftPanelLayout->addWidget(showRover);
    leftPanelLayout->addWidget(showDiagnostics);
    //Slider Window---------------------------
    QGridLayout *layerslid = new QGridLayout;
    //layers
    for(int k = 0;k<NumberOfServors;k++)
    {
        layerslid->addWidget(sliderList.at(k),0,k);
        layerslid->addWidget(radioButtonList.at(k),1,k);
    }
    QGridLayout *sidebar = new QGridLayout;
    sidebar->addWidget(radioButtonAll,0,0);
    sidebar->addWidget(radioButtonRover,1,0);
    layerslid->addLayout(sidebar,0,NumberOfServors,2,1);
    //Slider Window --------------------------
    //Add to layouts to windows
    //windowSlider->setLayout(layerslid);
    //Show Windows
    mainLayout->addLayout(leftPanelLayout,0,0,4,1);
    mainLayout->addLayout(layerslid,3,1,2,1);
    mainWind->setLayout(mainLayout);
    mainWind->show();
    // windowSlider->show();
    //LAYOUTS--------------------------------------------------------------------------------------//



    //SWITCH-------------------------------------------------------------------------//
    receiveSwitch *interpret = new receiveSwitch;
    QObject::connect(interpret,SIGNAL(resetHeader()),mysock,SLOT(resetHeader()));
    QObject::connect(interpret,SIGNAL(toInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(mysock,SIGNAL(Received(QString)),interpret,SLOT(interpret(QString)));
    QObject::connect(interpret,SIGNAL(toSend(QString)),mysock,SLOT(Send(QString)));
    //SWITCH



    //CREATE THREAD---------------------------------------------------------------------------------//
    //Pass socket to Thread
    mysock->InitializeConnection();
    cObject.sock = mysock;
    //Initate Thread
    cObject.DoSetup(cThread);
    cObject.moveToThread(&cThread);
    cThread.start();

    //Initialize radioButtons
    radioButtonList.at(0)->setChecked(true);



    return a.exec();
}
