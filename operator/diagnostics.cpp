#include "diagnostics.h"

Diagnostics::Diagnostics(QObject *parent) :
    QObject(parent)
{
        //Variables
        int columns = 16;
        int rows = 20;
        int width = 75;
        int height = 30;

        //Build Main Window
        scene = new QGraphicsScene(0,0,columns*width,rows*height,&m); //Create Scene for Graphics
        m.setScene(scene);
        m.setWindowTitle("Diagnostics");
        m.setMinimumHeight(rows*height);
        m.setMinimumWidth(columns*width);
        m.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //Remove SCroll Bars
        m.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        QGridLayout *mainLayout = new QGridLayout; //Layout
        //Set all row and columns with minimm height/width
        for(int i=0;i<columns;i++)
        {
            mainLayout->setColumnMinimumWidth(i,width);
            //mainLayout->set
        }
        for(int i=0;i<rows;i++)
        {
            mainLayout->setRowMinimumHeight(i,height+15);
            //mainLayout->row
        }

        //Create Items
        //Sync Servo Values - GUI -> Rover
        QPushButton *forceSyncGUI = new QPushButton;
        forceSyncGUI->setText("Sync GUI->Rover");
        forceSyncGUI->setMaximumHeight(height);
        forceSyncGUI->setMaximumWidth(2*width);
        mainLayout->addWidget(forceSyncGUI,1,1,1,2);

        //Sync Servo Values Rover -> GUI
        QPushButton *forceSyncRover = new QPushButton;
        forceSyncRover->setText("Sync Rover->GUI");
        forceSyncRover->setMaximumHeight(height);
        forceSyncRover->setMaximumWidth(2*width);
        mainLayout->addWidget(forceSyncRover,1,3,1,2);

        //Check Arduino Status - Also Resets
        QPushButton *arduinoCheck = new QPushButton;
        arduinoCheck->setText("Check Arduino");
        arduinoCheck->setMaximumHeight(height);
        arduinoCheck->setMaximumWidth(2*width);
        mainLayout->addWidget(arduinoCheck,1,5,1,2);

        //Check Xbox Controller Status
        QPushButton *xboxControler = new QPushButton;
        xboxControler->setText("Controller Status");
        xboxControler->setMaximumHeight(height);
        xboxControler->setMaximumWidth(2*width);
        mainLayout->addWidget(xboxControler,1,7,1,2);

        //Check Camera Status
        QPushButton *cameraCheck = new QPushButton;
        cameraCheck->setText("Camera Status");
        cameraCheck->setMaximumHeight(height);
        cameraCheck->setMaximumWidth(2*width);
        mainLayout->addWidget(cameraCheck,2,1,1,2);

        //Check Camera Status
        QPushButton *syncAll = new QPushButton;
        syncAll->setText("Sync All");
        syncAll->setMaximumHeight(height);
        syncAll->setMaximumWidth(2*width);
        mainLayout->addWidget(syncAll,2,3,1,2);



        int row = 5;        //Table Starting row

        //Servo Table Header
        QList<QString> servoHeaders;        //Headers for Servo Table
        QList<QLabel*> servoTableLabels;
        QList<int> spacerNumbers;
        spacerNumbers << 1 << 4;             //Pick where spaces are doubles
        servoHeaders.append("Servo");
        servoHeaders.append("Upper");
        servoHeaders.append("Lower");
        servoHeaders.append("Filter");
        servoHeaders.append("Status");
        servoHeaders.append("Update");

        //Add Spacers
        QSpacerItem *spacer = new QSpacerItem(width,height);
        mainLayout->addItem(spacer,4,1,1,1);
        mainLayout->addItem(spacer,5,1,1,1);
        mainLayout->addItem(spacer,row-1,7,1,1);
        mainLayout->addItem(spacer,row-1,8,1,1);


        //Create the servoTable Headlines
        int columnSpan;
        int add = 0;
        for(int i = 0; i < servoHeaders.size();i++)
        {

            columnSpan = 1;
            //allow for different column spans
            if(spacerNumbers.contains(i))
            {
                add++;
                columnSpan = 2;
            }
            servoTableLabels.append(new QLabel);
            servoTableLabels.at(i)->setText(servoHeaders.at(i));
            servoTableLabels.at(i)->setMinimumWidth(width);
            servoTableLabels.at(i)->setAlignment(Qt::AlignCenter);
            mainLayout->addWidget(servoTableLabels.at(i),row-1,i+1+add,1,columnSpan);

        }



        //Table -All servo Names
        QList<QString> servoNames;
        servoNames.append("Base");
        servoNames.append("Shoulder");
        servoNames.append("Elbow");
        servoNames.append("Wrist - R");
        servoNames.append("Wrist - V");
        servoNames.append("Claw");
        servoNames.append("Steer - FR");
        servoNames.append("Steer - FL");
        servoNames.append("Steer - BR");
        servoNames.append("Steer - BL");
        servoNames.append("Pan - H");
        servoNames.append("Pan - V");
        //Items to placed in each servo row
        QList<QLabel*> servolabels;
        QList<QTextEdit*> Uppers;
        QList<QTextEdit*> Lowers;
        QList<QTextEdit*> Filters;
        QList<QPushButton*> Set;
        QList<QGraphicsEllipseItem*> statusCircles;
        QList<QLabel*> statusLabels;
        QList<QPushButton*> updateButtons;
        int buttonName = 0;

        //Build Servo Table
        for(int i = 0;i < servoNames.size();i++)
        {

            servolabels.append(new QLabel);
            servolabels.at(i)->setText(servoNames.at(i));
            servolabels.at(i)->setMaximumWidth(2*width);
            servolabels.at(i)->setMinimumWidth(width*2);
            mainLayout->addWidget(servolabels.at(i),row,1,1,2);


            Uppers.append(new QTextEdit);
            Uppers.at(i)->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            Uppers.at(i)->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            Uppers.at(i)->setMaximumWidth(width);
            Uppers.at(i)->setAlignment(Qt::AlignRight);
            Uppers.at(i)->setMinimumHeight(height-5);
            Uppers.at(i)->setWordWrapMode(QTextOption::NoWrap);
            //Uppers.at(i)->setReadOnly(true);
            mainLayout->addWidget(Uppers.at(i),row,3,1,1);


            Lowers.append(new QTextEdit);
            Lowers.at(i)->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            Lowers.at(i)->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            Lowers.at(i)->setMaximumWidth(width);
            Lowers.at(i)->setMinimumHeight(height-5);
            Lowers.at(i)->setAlignment(Qt::AlignRight);
            Lowers.at(i)->setWordWrapMode(QTextOption::NoWrap);
            //Lowers.at(i)->setReadOnly(true);
            mainLayout->addWidget(Lowers.at(i),row,4,1,1);

            Filters.append(new QTextEdit);
            Filters.at(i)->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            Filters.at(i)->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            Filters.at(i)->setMaximumWidth(width);
            Filters.at(i)->setMinimumHeight(height-5);
            Filters.at(i)->setAlignment(Qt::AlignRight);
            Filters.at(i)->setWordWrapMode(QTextOption::NoWrap);
            //Filters.at(i)->setReadOnly(true);
            mainLayout->addWidget(Filters.at(i),row,5,1,1);

            mainLayout->addItem(spacer,row,6,1,1);
           // mainLayout->addItem(spacer,row,7,1,1);
            mainLayout->addItem(spacer,row,9,1,1);
            //mainLayout->addItem(spacer,row,10,1,1);

            //statusCircles.append(new QGraphicsEllipseItem);
            //statusCircles.at(i)->setBrush(QBrush(Qt::red));
            //statusCircles.at(i)->setRect(width*7-width/2,(row)*(height+2)+5,height/2-1,height/2-1);
            //scene->addItem(statusCircles.at(i));


            statusLabels.append(new QLabel);
            statusLabels.at(i)->setText("Wait");
            statusLabels.at(i)->setMaximumWidth(width);
            statusLabels.at(i)->setMinimumWidth(width);
            statusLabels.at(i)->setAlignment(Qt::AlignCenter);
            mainLayout->addWidget(statusLabels.at(i),row,7,1,1);

            updateButtons.append(new QPushButton);
            updateButtons.at(i)->setText("Update");
            updateButtons.at(i)->setMaximumHeight(height-5);
            updateButtons.at(i)->setMaximumWidth(width);
            mainLayout->addWidget(updateButtons.at(i),row,8,1,1);
            updateButtons.at(i)->setObjectName(QString::number(buttonName));
            QObject::connect(updateButtons.at(i),SIGNAL(clicked()),this,SLOT(updateButton()));

            buttonName++;
            row++;
        }


        //Motor Table
        QList<QString> motorStrings;
        QList<QLabel*> motorLabels;
        QList<QTextEdit*> motorUpper;
        motorStrings.append("FR");
        motorStrings.append("FL");
        motorStrings.append("MR");
        motorStrings.append("ML");
        motorStrings.append("BR");
        motorStrings.append("BL");
        motorStrings.append("Motor Limits");

        row = 5;
        for(int i=0;i<motorStrings.size()-1;i++)
        {
            //Motor Wheels Labels
            motorLabels.append(new QLabel);
            motorLabels.at(i)->setText(motorStrings.at(i));
            motorLabels.at(i)->setMaximumWidth(width);
            motorLabels.at(i)->setMinimumWidth(width);
            motorLabels.at(i)->setAlignment(Qt::AlignCenter);
            mainLayout->addWidget(motorLabels.at(i),row,10+i,1,1);

            //Text Boxes for motor Upper Limits
            motorUpper.append(new QTextEdit);
            motorUpper.at(i)->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            motorUpper.at(i)->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            motorUpper.at(i)->setMaximumWidth(width);
            motorUpper.at(i)->setMinimumHeight(height-5);
            motorUpper.at(i)->setAlignment(Qt::AlignRight);
            motorUpper.at(i)->setWordWrapMode(QTextOption::NoWrap);
            //Filters.at(i)->setReadOnly(true);
            mainLayout->addWidget(motorUpper.at(i),row+1,10+i,1,1);

        }

        //Add motor table Header
        motorLabels.append(new QLabel);
        motorLabels.at(6)->setText(motorStrings.at(6));
        motorLabels.at(6)->setMaximumWidth(2*width);
        motorLabels.at(6)->setMinimumWidth(width);
        mainLayout->addWidget(motorLabels.at(6),row-1,10,1,2);
        //Sync Motor Limits
        QPushButton *syncMotors = new QPushButton;
        syncMotors->setText("Sync Motors");
        syncMotors->setMaximumHeight(height);
        syncMotors->setMaximumWidth(2*width);
        mainLayout->addWidget(syncMotors,row-1,14,1,2);


         //Items Table Headers
        //Item Header
        QLabel *itemHeader = new QLabel;
        itemHeader->setText("Items");
        itemHeader->setMaximumWidth(2*width);
        itemHeader->setMinimumWidth(width);
        itemHeader->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(itemHeader,row+3,10,1,2);
        //Status Header
        QLabel *itemStatusHeader = new QLabel;
        itemStatusHeader->setText("Status");
        itemStatusHeader->setMaximumWidth(2*width);
        itemStatusHeader->setMinimumWidth(width);
        itemStatusHeader->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(itemStatusHeader,row+3,10+4,1,1);
        //Item Update Buttons Header
        QLabel *itemUpdate = new QLabel;
        itemUpdate->setText("Update");
        itemUpdate->setMaximumWidth(2*width);
        itemUpdate->setMinimumWidth(width);
        itemUpdate->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(itemUpdate,row+3,10+5,1,1);


        //Items to add to each row
        QList<QString> itemStrings;
        QList<QLabel*> itemLabels;
        QList<QLabel*> itemStatus;
        QList<QTextEdit*> itemText;
        QList<QPushButton*> itemButton;
        itemStrings.append("New Header");
        itemStrings.append("Shutdown Limit");
        itemStrings.append("Loop Delay");
        itemStrings.append("Sheel Command");

        //Build Item Table
        for (int i = 0; i < itemStrings.size();i++)
        {
            //Labels
            itemLabels.append(new QLabel);
            itemLabels.at(i)->setText(itemStrings.at(i));
            itemLabels.at(i)->setMaximumWidth(2*width);
            itemLabels.at(i)->setMinimumWidth(width);
            mainLayout->addWidget(itemLabels.at(i),row+4+i,10,1,2);

            //Text Boxes for motor Upper Limits
            itemText.append(new QTextEdit);
            itemText.at(i)->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            itemText.at(i)->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            itemText.at(i)->setMaximumWidth(width);
            itemText.at(i)->setMinimumHeight(height-5);
            itemText.at(i)->setAlignment(Qt::AlignRight);
            itemText.at(i)->setWordWrapMode(QTextOption::NoWrap);
            //Filters.at(i)->setReadOnly(true);
            mainLayout->addWidget(itemText.at(i),row+4+i,13,1,1);

            //Item Status Labels
            itemStatus.append(new QLabel);
            itemStatus.at(i)->setText("Wait");
            itemStatus.at(i)->setMaximumWidth(width);
            itemStatus.at(i)->setMinimumWidth(width);
            itemStatus.at(i)->setAlignment(Qt::AlignCenter);
            mainLayout->addWidget(itemStatus.at(i),row+4+i,14,1,1);

            //Item Buttons
            itemButton.append(new QPushButton);
            itemButton.at(i)->setText("Update");
            itemButton.at(i)->setMaximumHeight(height-5);
            itemButton.at(i)->setMaximumWidth(width);
            mainLayout->addWidget(itemButton.at(i),row+4+i,15,1,1);
            itemButton.at(i)->setObjectName(QString::number(buttonName));
            QObject::connect(itemButton.at(i),SIGNAL(clicked()),this,SLOT(updateButton()));
            buttonName++;
        }



        m.setLayout(mainLayout);
}


void Diagnostics::showDiagnostics()
{

    if(m.isHidden())
    {
        m.show();
    } else
    {
        m.hide();
    }

}

void Diagnostics::updateButton()
{
    QString id = QObject::sender()->objectName();
    emit toInternalTerminal("Button Pressed: "+id);
}
