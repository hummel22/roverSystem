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




    //WORKERS AND SLIDERS--------------------------------------------------------------------//
    //Create Windows
    QWidget *windowSlider = new QWidget;
    windowSlider->setWindowTitle("slider");//Contains Sliders
    //Create Sliders
    QSlider *slider1 = new QSlider;
    Worker *switcher1 = new Worker;
    //switcher1 to Internal Terminal
    QObject::connect(switcher1,SIGNAL(WorkerToTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    switcher1->Initialize(slider1,1);
    QSlider *slider2 = new QSlider;
    Worker *switcher2 = new Worker;
    //switcher1 to Internal Terminal
    QObject::connect(switcher2,SIGNAL(WorkerToTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    switcher2->Initialize(slider2,2);
    QSlider *slider3 = new QSlider;
    Worker *switcher3 = new Worker;
    //switcher1 to Internal Terminal
    QObject::connect(switcher3,SIGNAL(WorkerToTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    switcher3->Initialize(slider3,3);
    QSlider *slider4 = new QSlider;
    Worker *switcher4 = new Worker;
    //switcher1 to Internal Terminal
    QObject::connect(switcher4,SIGNAL(WorkerToTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    switcher4->Initialize(slider4,4);
    QSlider *slider5 = new QSlider;
    Worker *switcher5 = new Worker;
    //switcher1 to Internal Terminal
    QObject::connect(switcher5,SIGNAL(WorkerToTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    switcher5->Initialize(slider5,5);
    QSlider *slider6 = new QSlider;
    Worker *switcher6 = new Worker;
    //switcher1 to Internal Terminal
    QObject::connect(switcher6,SIGNAL(WorkerToTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    switcher6->Initialize(slider6,6);
    //Create Socket and Initialize
    UDPwork *mysock = new UDPwork;
    //Thread
    QThread cThread;
    myThread cObject;
    //Connect All Workers to socket
    QObject::connect(switcher1,SIGNAL(WorkerToSend(QString)),mysock,SLOT(Send(QString)));
    QObject::connect(switcher2,SIGNAL(WorkerToSend(QString)),mysock,SLOT(Send(QString)));
    QObject::connect(switcher3,SIGNAL(WorkerToSend(QString)),mysock,SLOT(Send(QString)));
    QObject::connect(switcher4,SIGNAL(WorkerToSend(QString)),mysock,SLOT(Send(QString)));
    QObject::connect(switcher5,SIGNAL(WorkerToSend(QString)),mysock,SLOT(Send(QString)));
    QObject::connect(switcher6,SIGNAL(WorkerToSend(QString)),mysock,SLOT(Send(QString)));
        //UDP to Terminals
    QObject::connect(mysock,SIGNAL(UDPtoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(mysock,SIGNAL(UDPtoTerminalSend(QString)),TerminalSent,SLOT(appendPlainText(QString)));
    QObject::connect(mysock,SIGNAL(Received(QString)),TerminalReceived,SLOT(appendPlainText(QString)));
    //Workerall
    WorkerAll *All = new WorkerAll;
    All->addWorker(switcher1);
    All->addWorker(switcher2);
    All->addWorker(switcher3);
    All->addWorker(switcher4);
    All->addWorker(switcher5);
    All->addWorker(switcher6);

   //Rover Worker
    WorkerRover *rWorker = new WorkerRover;
    //WORKERS AND SLIDERS---------------------------------------------------------------------------//




    //RADIO BUTTONS--------------------------------------------------------------------------------//
    //Testing
    int NumberOfServors = 9;
    QList<Worker*> workerList;
    //
    HRadioButton *radioButton1 = new HRadioButton(1);
    HRadioButton *radioButton2 = new HRadioButton(2);
    HRadioButton *radioButton3 = new HRadioButton(3);
    HRadioButton *radioButton4 = new HRadioButton(4);
    HRadioButton *radioButton5 = new HRadioButton(5);
    HRadioButton *radioButton6 = new HRadioButton(6);
    HRadioButton *radioButtonAll = new HRadioButton(7);
    HRadioButton *radioButtonRover = new HRadioButton(8);
    radioButtonAll->setText("All Servos");
    radioButtonRover->setText("Rover Control");
    //Connect Radio Buttons to Internal Terminal
    QObject::connect(radioButton1,SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(radioButton2,SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(radioButton3,SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(radioButton4,SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(radioButton5,SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(radioButton6,SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(radioButtonAll,SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(radioButtonRover,SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    //KEY INPUT
    keyWindoe *test = new keyWindoe;
    test->setMaximumHeight(200);
    test->setMaximumWidth(200);
    //Radio Controller
    RadioList *myList = new RadioList(test);
    myList->addslide(switcher1);
    myList->addslide(switcher2);
    myList->addslide(switcher3);
    myList->addslide(switcher4);
    myList->addslide(switcher5);
    myList->addslide(switcher6);
    myList->wAll = All;
    myList->wRover = rWorker;
    //Add radio Buttons to List
    myList->addButton(radioButton1);
    myList->addButton(radioButton2);
    myList->addButton(radioButton3);
    myList->addButton(radioButton4);
    myList->addButton(radioButton5);
    myList->addButton(radioButton6);
    myList->addButton((radioButtonAll));
    myList->addButton(radioButtonRover);
    //Connect RadioList to socket
    QObject::connect(myList,SIGNAL(toSend(QString)),mysock,SLOT(Send(QString)));
    //Connect RadioButtons to Radio List
    QObject::connect(radioButton1,SIGNAL(clicked(int)),myList,SLOT(RadioReceive(int)));
    QObject::connect(radioButton2,SIGNAL(clicked(int)),myList,SLOT(RadioReceive(int)));
    QObject::connect(radioButton3,SIGNAL(clicked(int)),myList,SLOT(RadioReceive(int)));
    QObject::connect(radioButton4,SIGNAL(clicked(int)),myList,SLOT(RadioReceive(int)));
    QObject::connect(radioButton5,SIGNAL(clicked(int)),myList,SLOT(RadioReceive(int)));
    QObject::connect(radioButton6,SIGNAL(clicked(int)),myList,SLOT(RadioReceive(int)));
    QObject::connect(radioButtonAll,SIGNAL(clicked(int)),myList,SLOT(RadioReceive(int)));
    QObject::connect(radioButtonRover,SIGNAL(clicked(int)),myList,SLOT(RadioReceive(int)));
    //RADIO BUTTONS--------------------------------------------------------------------------------//








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
    QObject::connect(slider1,SIGNAL(valueChanged(int)),arm,SLOT(Angle1(int)));
    QObject::connect(slider2,SIGNAL(valueChanged(int)),arm,SLOT(Angle2(int)));
    QObject::connect(slider4,SIGNAL(valueChanged(int)),arm,SLOT(ClawAngle(int)));
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
    //Slider Window---------------------------
    QGridLayout *layerslid = new QGridLayout;
    //layers
    layerslid->addWidget(slider1,0,0);
    layerslid->addWidget(slider2,0,1);
    layerslid->addWidget(slider3,0,2);
    layerslid->addWidget(slider4,0,3);
    layerslid->addWidget(slider5,0,4);
    layerslid->addWidget(slider6,0,5);
    layerslid->addWidget(radioButton1,1,0);
    layerslid->addWidget(radioButton2,1,1);
    layerslid->addWidget(radioButton3,1,2);
    layerslid->addWidget(radioButton4,1,3);
    layerslid->addWidget(radioButton5,1,4);
    layerslid->addWidget(radioButton6,1,5);
    QGridLayout *sidebar = new QGridLayout;
    sidebar->addWidget(radioButtonAll,0,0);
    sidebar->addWidget(radioButtonRover,1,0);
    layerslid->addLayout(sidebar,0,6,2,1);
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
    radioButton1->setChecked(true);



    return a.exec();
}
