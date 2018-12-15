#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include "dbconnect_global.h"

class DBCONNECTSHARED_EXPORT DBConnect
{

public:
    DBConnect();
    //Muodostettaessa syötetään parametrit k:kortinNro, p: pinKoodi
    DBConnect(QString k, int p);
    //Yhdistää koulun palvelimella olevaan tietokantaan
    void yhdistaTietokantaan();

    //bool yhdistaTiliin(QString RFID, int pinKoodi);

    //Noutaa kyseisen tilin saldon tietokannasta ja asettaa sen olion saldo atribuuttiin.
    void haeSaldo();
    //Veloittaa käyttäjän tililtä kyseisen summan
    void veloitaSumma(int veloitettavaSumma);


    //---------------------------------------------
    //Koodia debugausta varten!
    void suoritaKysely(QString kayttajanKysely);
    double getSaldo();
    int getPinKoodi();
    QString getKortinNro();
    void setKortinNro(QString value);
    void setPinKoodi(int value);
    //---------------------------------------------

protected:


private:
    QSqlDatabase db;
    QString kyselynTulos;
    double saldo = 0;
    QString tiliNro;
    QString kortinNro; //0B003254CB / abcde12345
    int pinKoodi;
};

#endif // DBCONNECT_H