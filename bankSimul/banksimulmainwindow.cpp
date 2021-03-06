#include <QtCore>
#include <QObject>
#include <QWidget>
#include "headers/banklibrary.h"
#include "banksimulmainwindow.h"
#include "ui_banksimulmainwindow.h"
#include "headers/dbconnect.h"
#include "headers/ui_nappisform.h"
#include "headers/nappis.h"


bankSimulMainWindow::bankSimulMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bankSimulMainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(7);
    dbYhteys = new DBConnect("", 1234);
    dbYhteys->yhdistaTietokantaan();
    nostonValinta = new BankLibrary;
    Nappaimisto = new NappisForm(this);
    Nappaimisto->move((this->width()/2-Nappaimisto->width()/2),260);//x 260
    //Nappaimisto->show();
    RFID = new RfidDLL;

    RFID->palautaPankkikortinNumeroKomponentti();
    //connect(ui->stackedWidget,SIGNAL(currentChanged(int)), this, SLOT(on_stackedWidget_currentChanged(int)));

    //timer
    timer = new QTimer(this);
    this->connect(timer, SIGNAL(timeout()), this, SLOT(paivitaAika()));
    connect(RFID,&RfidDLL::testiSignal,this,&bankSimulMainWindow::testiSlot);
   // this->connect(ui->pushButtonKirjauduUlos4_1, SIGNAL(clicked()), this, SIGNAL(kirjauduUlos()));
   //timer->start(1000);
    connect(Nappaimisto, SIGNAL(nappisOkPainettu(int)),this,SLOT(testiNappisPin()));
    //ui->stackedWidget->setCurrentIndex(7);
}

bankSimulMainWindow::~bankSimulMainWindow()
{
    delete ui;
    delete dbYhteys;
    delete nostonValinta;
    delete Nappaimisto;
    delete RFID;
}


void bankSimulMainWindow::on_pushButton_2_KirjauduSisaan_clicked()
{
    //ui->stackedWidget->setCurrentIndex(1);
    //dbYhteys->setKortinNro("");
    if(RFID->getCardSerialNumber() != "")
    {
        dbYhteys->setKortinNro(RFID->getCardSerialNumber());
        qDebug() << "Kortin nro: ***" << dbYhteys->getKortinNro();
    }
    dbYhteys->setPinKoodi(1234);
    if(dbYhteys->getPinKoodi() != 0 && dbYhteys->getKortinNro() != "" && dbYhteys->tarkistaKortinPin() == true )
    {
        qDebug() << "if lauseessa!";
        qDebug() << dbYhteys->palautaNro(5);
        //qDebug() << dbYhteys->palautaNroYksi();
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        ui->labelPinKoodi->setText("Virheellinen PIN!");
    }
    timer->start(1000);
    Nappaimisto->close();
    qDebug() << RFID->getCardSerialNumber();
}

//*************************Päävalikon-napit**************************************
void bankSimulMainWindow::on_pushButtonNostaRahaa_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    aikaaJaljella = 20;
}

void bankSimulMainWindow::on_pushButtonNaytaSaldo_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    dbYhteys->haeSaldo();
    //qDebug() << dbYhteys->getSaldo();
    ui->labelTilinSaldoTiedot->setText("Tilin saldo on tällä hetkellä: " + QString::number(dbYhteys->getSaldo()));
    aikaaJaljella = 10;
}

void bankSimulMainWindow::on_pushButtonNaytaTilitapahtumat_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    dbYhteys->haeTilitapahtumat();
    ui->tableViewTilitapahtumat->setModel(dbYhteys->haeTilitapahtumat());
    aikaaJaljella = 20;
}

void bankSimulMainWindow::on_pushButtonKirjauduUlos_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    timer->stop();

    dbYhteys->setKortinNro("a");
    //qDebug() << dbYhteys->getKortinNro();
}

//Nosta Rahaa -> Vaihda Valuuttaa
void bankSimulMainWindow::on_pushButtonVaihdaValuutta_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

// ***********Peruuta-napit:*********************************
//Tilin Saldo peruuta-nappi. page3
void bankSimulMainWindow::on_pushButton_2_Peruuta_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//Rahan Nosto peruuta-nappi: page4
void bankSimulMainWindow::on_pushButton_Peruuta_clicked()
{
    Nappaimisto->close();
    ui->stackedWidget->setCurrentIndex(1);
}

//Näytä Tilitapahtumat peruuta-nappi: page5
void bankSimulMainWindow::on_pushButton_Peruuta_P5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//Vaihda Valuuttaa peruuta-nappi: page5_2
void bankSimulMainWindow::on_pushButton_Peruuta_P5_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
//Nostit Rahaa peruuta-nappi: page4_1
void bankSimulMainWindow::on_pushButton_Peruuta_P4_1_clicked()
{
    Nappaimisto->close();
    ui->stackedWidget->setCurrentIndex(1);
    aikaaJaljella = 20;
}


// *************Nosta Rahaa napit:************************
void bankSimulMainWindow::on_pushButton_20e_clicked()
{
    nostonValinta->nostoSummanValinta(ui->pushButton_20e->text());
    tarkastaTilinKate();
}

void bankSimulMainWindow::on_pushButton_2_40e_clicked()
{
    nostonValinta->nostoSummanValinta(ui->pushButton_2_40e->text());
    tarkastaTilinKate();
}

void bankSimulMainWindow::on_pushButton_4_60e_clicked()
{
    nostonValinta->nostoSummanValinta(ui->pushButton_4_60e->text());
    tarkastaTilinKate();
}

void bankSimulMainWindow::on_pushButton_5_80e_clicked()
{
    nostonValinta->nostoSummanValinta(ui->pushButton_5_80e->text());
    tarkastaTilinKate();
}

void bankSimulMainWindow::on_pushButton_6_100e_clicked()
{
    //aikaaJaljella = 10;
    //ui->stackedWidget->setCurrentIndex(6);
    nostonValinta->nostoSummanValinta(ui->pushButton_6_100e->text());
    /*dbYhteys->veloitaSumma(nostonValinta->getVeloitaSumma());
    qDebug() << nostonValinta->getVeloitaSumma();
    dbYhteys->haeSaldo();
    ui->label_NostitRahaa->setText("Nostit " + QString::number(nostonValinta->getVeloitaSumma()) +" euroa\nTilillesi jäi "+ QString::number(dbYhteys->getSaldo())+" euroa");*/
    tarkastaTilinKate();
}

void bankSimulMainWindow::on_pushButton_7_MuuSumma_clicked()
{
    Nappaimisto->show();
    aikaaJaljella = 20;
    //ui->stackedWidget->setCurrentIndex(6);
    //dbYhteys->haeSaldo();
    //ui->label_NostitRahaa->setText("Nostit " + QString::number(nostonValinta->getVeloitaSumma()) +" euroa\nTilillesi jäi "+ QString::number(dbYhteys->getSaldo())+" euroa");
    //.append("e")
}

/*
void bankSimulMainWindow::laskuri()
{
        aikaaJaljella = 10;
        ajastin = new QTimer(this);

        paivitaAika();
        ajastin->setInterval(1000);
        ajastin->start();
}

*/
void bankSimulMainWindow::paivitaAika()
{
     timer->start(1000);
     //aikaaJaljella= aikaaJaljella -1;
     ui->labelLaskuriKirjauduUlos->setText(" "+ QString::number(aikaaJaljella));

    if (!(--aikaaJaljella))
    {
        timer->stop();
        ui->stackedWidget->setCurrentIndex(7);

    }
    //emit kirjauduUlos();

}

/*
void bankSimulMainWindow::alustaTimer()
{
         aikaaJaljella = 10;
         ajastin->setInterval(1000);
         ajastin->start();
}

*/
void bankSimulMainWindow::Timer()
{
    // aikaaJaljella = 10;
    paivitaAika();
    //timer->setInterval(1000);
    //timer->start();
}

void bankSimulMainWindow::on_pushButtonKirjauduUlos4_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    timer->stop();
    dbYhteys->setKortinNro("a");

}

void bankSimulMainWindow::on_pushButton_clicked()
{
    dbYhteys->setKortinNro("0B003254CB");
    ui->stackedWidget->setCurrentIndex(0);
    Nappaimisto->show();
}

void bankSimulMainWindow::tarkastaTilinKate()
{
    dbYhteys->haeSaldo();
    if(dbYhteys->getSaldo() >= nostonValinta->getVeloitaSumma())
    {
        dbYhteys->veloitaSumma(nostonValinta->getVeloitaSumma());
        qDebug() << nostonValinta->getVeloitaSumma();
        dbYhteys->haeSaldo();
        ui->label_NostitRahaa->setText("Nostit " + QString::number(nostonValinta->getVeloitaSumma()) +" euroa\nTilillesi jäi "+ QString::number(dbYhteys->getSaldo())+" euroa");
    }
    else
    {
        ui->label_NostitRahaa->setText("Tilin kate ei riitä kyseiselle summalle.\nTililläsi on "+ QString::number(dbYhteys->getSaldo())+" euroa");
    }
    Nappaimisto->close();
    aikaaJaljella = 10;
    ui->stackedWidget->setCurrentIndex(6);


    //qDebug()<<nostonValinta->getVeloitaSumma();
}

void bankSimulMainWindow::testiSlot()
{
    ui->stackedWidget->setCurrentIndex(0);
    Nappaimisto->show();
void bankSimulMainWindow::testiNappisPin()
{
    ui->stackedWidget->setCurrentIndex(1);
    // #####Ei toimi vielä toi, mutta signaali tulee läpi nappikselta tähän.#####
    // ui->labelPinKoodi->setText(" "+QString::number(Nappaimisto->muisti));
    qDebug() <<"Nappiksen slotti";
    Nappaimisto->close();
    //aikaaJaljella = 10;
}
