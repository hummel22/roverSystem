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

    //SOCKET--------------------------------------------------------------------------------//
    UDPwork *MySocket = new UDPwork;
    //Thread
    QThread cThread;
    myThread cObject;
    //UDP to Terminals
    QObject::connect(MySocket,SIGNAL(UDPtoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(MySocket,SIGNAL(UDPtoTerminalSend(QString)),TerminalSent,SLOT(appendPlainText(QString)));
    QObject::connect(MySocket,SIGNAL(Received(QString)),TerminalReceived,SLOT(appendPlainText(QString)));
    //SOCKET--------------------------------------------------------------------------------//


    //WORKERS / SLIDERS / RADIOBUTTONS--------------------------------------------------------------------//
    int NumberOfServors = 12;               //Set Number of Servos to Control
    //QWidget *windowSlider = new QWidget;    //Create Container for Sliders
    //windowSlider->setWindowTitle("Sliders"); //Contains Sliders


    ArmController *Arm = new ArmController;         //Arm Control Object
    RoverController *Drive = new RoverController;   //Drive Control Object
    //Build Workers and Sliders Lists
    QList<Servo*> servoList;
    QList<QSlider*> sliderList;
    QList<HRadioButton*> radioButtonList;


    //KEY INPUT
    keyWindoe *test = new keyWindoe;
    test->setMaximumHeight(200);
    test->setMaximumWidth(200);

    //Radio Controller
    RadioList *ModeHandler = new RadioList(test);
    //Connect RadioList to socket
    QObject::connect(ModeHandler,SIGNAL(toSend(QString)),MySocket,SLOT(Send(QString)));

    //For Loop to build dynamically
    for(int i = 0;i <NumberOfServors;i++)
    {
        //Create each Worker and Slider
        servoList.append(new Servo);
        sliderList.append(new QSlider);
        radioButtonList.append(new HRadioButton);
        radioButtonList.at(i)->initialize(i);
        servoList.at(i)->Initialize(sliderList.at(i),i);

        //Connect to Terminal And Socket - Connect radio buttons to RadioList
        QObject::connect(servoList.at(i),SIGNAL(ToTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
        QObject::connect(servoList.at(i),SIGNAL(Send(QString)),MySocket,SLOT(Send(QString)));
        QObject::connect(radioButtonList.at(i),SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
        QObject::connect(radioButtonList.at(i),SIGNAL(clicked(int)),ModeHandler,SLOT(RadioReceive(int)));

        //Add Workers to Main Controllers [workerALL Class]
        Arm->addWorker(servoList.at(i));
        ModeHandler->addslide(servoList.at(i));
        ModeHandler->addButton(radioButtonList.at(i));

    }

    //Create Drive and Arm Objects
    HRadioButton *radioButtonArm = new HRadioButton();
    HRadioButton *radioButtonRover = new HRadioButton();
    radioButtonArm->initialize(NumberOfServors);
    radioButtonRover->initialize(NumberOfServors+1);
    radioButtonArm->setText("All Servos");
    radioButtonRover->setText("Drive Control");
    QObject::connect(radioButtonArm,SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(radioButtonRover,SIGNAL(RadioButtontoTerminalInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    ModeHandler->Arm = Arm;
    ModeHandler->Drive = Drive;
    ModeHandler->addButton(radioButtonArm);
    ModeHandler->addButton(radioButtonRover);
    QObject::connect(radioButtonArm,SIGNAL(clicked(int)),ModeHandler,SLOT(RadioReceive(int)));
    QObject::connect(radioButtonRover,SIGNAL(clicked(int)),ModeHandler,SLOT(RadioReceive(int)));
    //WORKERS / SLIDERS / RADIOBUTTONS---------------------------------------------------------------------------//









    //JOYSTICK-------------------------------------------------------------------------------------//
    //Joystick Window
    joystickWindow *jWindow = new joystickWindow;
    jWindow->initialize();
    joystickInput *jInput = new joystickInput;      //Connect to Joystick
    ModeHandler->jInput = jInput;                   //Allow ModeHandler to control joystick connections
    //Initial Connections
    QObject::connect(jInput,SIGNAL(axisSet(int,int,int,int,int,int)),jWindow,SLOT(axisSet(int,int,int,int,int,int)));
    QObject::connect(jInput,SIGNAL(buttons(int)),jWindow,SLOT(buttonPress(int)));
    QObject::connect(jInput,SIGNAL(axisSet(int,int,int,int,int,int)),ModeHandler,SLOT(axisSet(int,int,int,int,int,int)));
    QObject::connect(jInput,SIGNAL(buttons(int)),ModeHandler,SLOT(buttons(int)));
    QObject::connect(jInput,SIGNAL(toInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    //Thread
    QThread jThread;
    joyThread jObject;
    //Initate Thread
    jObject.jInputs = jInput;
    jObject.DoSetup(jThread);
    jObject.moveToThread(&jThread);
    jThread.start();
    //JOYSTICK-------------------------------------------------------------------------------------//



    //ROVER GRAPHICAL VIEW
    roverWindow *rWindow = new roverWindow;
    rWindow->intialize();
    ModeHandler->rWindow = rWindow;
    QObject::connect(jInput,SIGNAL(buttons(int)),rWindow,SLOT(buttonControl(int)));
    //ROVER VIEW


    //ARM GRAPHICAL VIEW
    armWindow *aWindow = new armWindow;
    QObject::connect(sliderList.at(0),SIGNAL(valueChanged(int)),aWindow,SLOT(Angle1(int)));
    QObject::connect(sliderList.at(1),SIGNAL(valueChanged(int)),aWindow,SLOT(Angle2(int)));
    QObject::connect(sliderList.at(3),SIGNAL(valueChanged(int)),aWindow,SLOT(ClawAngle(int)));
    QObject::connect(jInput,SIGNAL(buttons(int)),aWindow,SLOT(Buttons(int)));
    //ARM VIEW



    //DIAGNOSTICS
    Diagnostics *diag = new Diagnostics;
    QObject::connect(diag,SIGNAL(toInternalTerminal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(diag,SIGNAL(Send(QString)),MySocket,SLOT(Send(QString)));
    //DIAGNOSTICS



    //BUTTONS--------------------------------------------------------------------------------------//
    QPushButton *showTerminals = new QPushButton;
    QPushButton *showJoystick = new QPushButton;
    QPushButton *showKeyInput = new QPushButton;
    QPushButton *showRover  = new QPushButton;
    QPushButton *showDiagnostics = new QPushButton;
    QPushButton *Reset = new QPushButton;
    showDiagnostics->setText("Diagnostics");
    showRover->setText("Rover View");
    showKeyInput->setText("Key Input");
    showTerminals->setText("Terminals");
    showJoystick->setText("Joystick");
    Reset->setText("Reset");

    QObject::connect(showTerminals,SIGNAL(clicked()),windowAll,SLOT(show()));
    QObject::connect(showJoystick,SIGNAL(clicked()),jWindow,SLOT(showBox()));
    QObject::connect(showKeyInput,SIGNAL(clicked()),test,SLOT(show()));
    QObject::connect(showRover,SIGNAL(clicked()),rWindow,SLOT(showRover()));
    QObject::connect(Reset,SIGNAL(clicked()),Arm,SLOT(reset()));
    QObject::connect(showDiagnostics,SIGNAL(clicked()),diag,SLOT(showDiagnostics()));
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
    leftPanelLayout->addWidget(showJoystick);
    leftPanelLayout->addWidget(showKeyInput);
    leftPanelLayout->addWidget(showRover);
    leftPanelLayout->addWidget(showDiagnostics);
    leftPanelLayout->addWidget(Reset);
    //Slider Window---------------------------
    QGridLayout *layerslid = new QGridLayout;
    //layers
    for(int k = 0;k<NumberOfServors;k++)
    {
        layerslid->addWidget(sliderList.at(k),0,k);
        layerslid->addWidget(radioButtonList.at(k),1,k);
    }
    QGridLayout *sidebar = new QGridLayout;
    sidebar->addWidget(radioButtonArm,0,0);
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
    QObject::connect(interpret,SIGNAL(resetHeader()),MySocket,SLOT(resetHeader()));
    QObject::connect(interpret,SIGNAL(toInternal(QString)),TerminalInternal,SLOT(appendPlainText(QString)));
    QObject::connect(MySocket,SIGNAL(Received(QString)),interpret,SLOT(interpret(QString)));
    QObject::connect(interpret,SIGNAL(toSend(QString)),MySocket,SLOT(Send(QString)));
    QObject::connect(interpret,SIGNAL(servoAttributes(int[])),diag,SLOT(receiveAttributes(int[])));
    //SWITCH



    //CREATE THREAD---------------------------------------------------------------------------------//
    //Pass socket to Thread
    MySocket->InitializeConnection();
    cObject.sock = MySocket;
    //Initate Thread
    cObject.DoSetup(cThread);
    cObject.moveToThread(&cThread);
    cThread.start();

    //Initialize radioButtons
    radioButtonList.at(0)->setChecked(true);



    return a.exec();
}
