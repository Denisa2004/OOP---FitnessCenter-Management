#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <cstdlib>

#include "Client.h"
#include "ClientVIP.h"
#include "Antrenor.h"
#include "Abonament.h"


std::ostream &operator<<(std::ostream &os, const Programare &programare)
{
    os << "Zi: " << programare.zi << ", Ora: " << programare.ora;
    return os;
}

std::vector<Antrenor> listaAntrenori;
std::vector<Client> listaClienti;

using namespace std;

int main()
{
        ///--------------------------------------------------ABONAMENT----------------------------------------------------------------

        DataAbonament data_inceput1{1, 3, 2024};
        DataAbonament data_sfarsit1{1, 6, 2024};
        std::string tip1="Fitness";

        Abonament abonament1(tip1, data_inceput1, data_sfarsit1); //constructor de initializare
       // cout<<"Abonament1: "<<abonament1<<endl; //operatorul <<

        Abonament abonament2=abonament1; //constructor de copiere
        //cout<<"Abonament2: "<<abonament2<<endl;

        Abonament abonament3; //constructor
        abonament3=abonament2; //operatorul =
        //cout<<"Abonament3: "<<abonament3<<endl;

        std::string tip2 = "Pilates";
        Abonament abonament4;
        abonament4.setTipAbonament(tip2);

        DataAbonament data_inceput2{17, 2, 2024};
        DataAbonament data_sfarsit2{16, 3, 2024};

        abonament4.setDataInceput(data_inceput2);
        abonament4.setDataSfarsit(data_sfarsit2);

        //cout<<endl<<"Abonament 4:"<<endl;
        //std::cout << "Tip abonament: " << abonament4.getTipAbonament() << std::endl;

        DataAbonament dataInceput = abonament4.getDataInceput();
        //std::cout << "Data inceput: " << dataInceput.zi << "/" << dataInceput.luna << "/" << dataInceput.an << std::endl;

        DataAbonament dataSfarsit = abonament4.getDataSfarsit();
        //std::cout << "Data sfarsit: " << dataSfarsit.zi << "/" << dataSfarsit.luna << "/" << dataSfarsit.an << std::endl;

        Abonament abonament5("Kickboxing", {26, 1, 2024}, {25, 4, 2024});
        //cout<<endl<<"Abonament5: "<<abonament5<<endl;

        /*cout<<endl;
        if(abonament1.verificaValabilitatea())
            cout<<"Abonament1 valabil!"<<endl;
        else
            cout<<"Abonament1 expirat!"<<endl;

        if(abonament4.verificaValabilitatea())
            cout<<"Abonament4 este valabil!"<<endl;
        else
            cout<<"Abonament4 este expirat!"<<endl;
        cout<<endl<<endl;*/


        ///--------------------------------------------------ANTRENOR----------------------------------------------------------------

        Antrenor antrenor1; //constructor
        std::string numeAntr1="Popescu Valentin";
        antrenor1.setNume(numeAntr1);

        std::string numarTelefon1="0771924432";
        antrenor1.setNumarTelefon(numarTelefon1);

        std::vector <orarAntrenor> orar1;
        orar1.push_back({"Luni", "10:00", "Kickboxing"});
        orar1.push_back({"Miercuri", "15:30", "Fitness"});
        orar1.push_back({"Joi", "12:30", "Aerobic"});

        antrenor1.setOrar(orar1);
        //cout<<antrenor1<<endl; //operatorul <<

        std::vector <orarAntrenor> orar2;
        orar2.push_back({"Luni", "12:00", "Aerobic"});
        orar2.push_back({"Marti", "10:30", "Pilates"});
        orar2.push_back({"Joi", "14:00", "Yoga"});

        Antrenor antrenor2("Neagu Mihaela", "0747721135", orar2); //constructor de initializare
        //cout<<antrenor2<<endl;

        Antrenor antrenor3=antrenor1; //constructor de copiere
        //cout<<antrenor3<<endl;

        Antrenor antrenor4;
        antrenor4=antrenor2; //operator =
        //cout<<antrenor4<<endl;

        Antrenor antrenor5;
        std::string numeAntr5="Marculescu Bogdan";
        antrenor5.setNume(numeAntr5);

        std::string nrTlfAntr5="0721993791";
        antrenor5.setNumarTelefon(nrTlfAntr5);

        std::vector <orarAntrenor> orar5;
        orar5.push_back({"Miercuri", "14:30", "Fitness"});
        orar5.push_back({"Miercuri", "17:30", "Pilates"});
        orar5.push_back({"Vineri", "19:00", "Kickboxing"});

        antrenor5.setOrar(orar5);
        //cout<<antrenor5<<endl<<endl;

        antrenor1.adaugaAntrenor(antrenor1, listaAntrenori);
        antrenor4.adaugaAntrenor(antrenor4, listaAntrenori);
        antrenor5.adaugaAntrenor(antrenor5, listaAntrenori);

        /*cout<<endl<<"Lista antrenorilor este urmatoarea:"<<endl<<endl;
        for (size_t i = 0; i < listaAntrenori.size(); ++i)
            cout<<listaAntrenori[i]<<endl;
        cout<<endl<<endl;*/

        /*char optiuneProgramareSedinta;
        std::cout << "Doriti sa programati o sedinta cu un antrenor? (Y/N): ";
        std::cin >> optiuneProgramareSedinta;

        if (optiuneProgramareSedinta == 'Y')
            antrenor1.programareSedinta(listaAntrenori);
        else if (optiuneProgramareSedinta == 'N')
            std::cout<<"In regula!"<<std::endl;*/


        ///--------------------------------------------------CLIENT----------------------------------------------------------------

        std::string nume1="Vasilescu Ioana";
        std::string nrTelef1="0775924573";
        Client client1(nume1, nrTelef1, abonament1); //constructor de initializare
        //cout<<endl<<client1<<endl; // operatorul <<

        Client client2=client1; //constructor de copiere
        //cout<<client2<<endl;

        Client client3; //constructor
        client3=client2; //operatorul =
        //cout<<client3<<endl;

        Client client4;
        std::string nume4="Mihailescu Georgiana";
        client4.setNume(nume4);

        std::string nrTelef4="0726435577";
        client4.setnumarTelefon(nrTelef4);

        client4.setAbonament(abonament4);
        //cout<<client4<<endl;

        Client client5("Voicu Florin", "0745564932", abonament5);
        /*std::cout<<"Nume: "<<client5.getNume()<<std::endl;
        std::cout<<"Numar telefon: "<<client5.getnumarTelefon()<<std::endl;
        std::cout<<"Abonament: "<<client5.getAbonament()<<std::endl;

        cout<<endl;*/
        client1.adaugaClient(client1, listaClienti);
        client2.adaugaClient(client2, listaClienti);
        client3.adaugaClient(client3, listaClienti);
        client4.adaugaClient(client4, listaClienti);
        client5.adaugaClient(client5, listaClienti);

        /*cout<<endl<<"Lista clientilor este urmatoarea:"<<endl<<endl;
        for (size_t i = 0; i < listaClienti.size(); ++i)
            cout<<listaClienti[i]<<endl;
        cout<<endl;*/


        ///--------------------------------------------------CLIENT VIP----------------------------------------------------------------

        ClientVIP clientVIP1("Cristache Mihai", "0721293926", abonament2, "2173#"); //constructor de initializare
        //cout<<clientVIP1<<endl;

        ClientVIP clientVIP2("Marin Camelia", "0726743772", abonament5, "");
        //clientVIP2.upgradeLaClientVIP();
        //cout<<endl<<clientVIP2<<endl;

        ClientVIP clientVIP3=clientVIP1; //constructor de copiere
        //cout<<clientVIP3<<endl;

        ClientVIP clientVIP4; //constructor
        clientVIP4=clientVIP2; //operator de copiere
        //cout<<clientVIP4<<endl;

        ClientVIP clientVIP5;
        std::string nume5="Ionescu Andreea";
        clientVIP5.setNume(nume5);

        std::string nrTelef5="0745921152";
        clientVIP5.setnumarTelefon(nrTelef5);

        clientVIP5.setAbonament(abonament2);

        std::string codAcces5="7224#";
        clientVIP5.setCodAccesVIP(codAcces5);

        std::string ziSauna="7aprilie";
        std::string oraSauna="17:00";
        clientVIP5.setprogramareSauna(ziSauna, oraSauna);

        std::string ziJacuzzi="12aprilie";
        std::string oraJacuzzi="20:30";
        clientVIP5.setprogramareJacuzzi(ziJacuzzi, oraJacuzzi);

        /*cout<<endl;
        std::cout<<"Nume: "<<clientVIP5.getNume()<<std::endl;
        std::cout<<"Numar telefon: "<<clientVIP5.getnumarTelefon()<<std::endl;
        std::cout<<"Abonament: "<<clientVIP5.getAbonament()<<std::endl;
        std::cout<<"Cod AccesVIP: "<<clientVIP5.getCodAccesVIP()<<std::endl;
        std::cout<<"Programare Sauna: "<<clientVIP5.getprogramareSauna()<<std::endl;
        std::cout<<"Programare Jacuzzi: "<<clientVIP5.getprogramareJacuzzi()<<std::endl;*/

        char opt;
        cout<<endl<<"Doresti sa vizualizezi Meniul? (Y/N)"<<endl;
        cin>>opt;
        if(opt=='N')
            cout<<"In regula!"<<endl;
        else
        {
    #ifdef _WIN32
            system("cls");
    #else
            system("clear");
    #endif
        }


    int optiune;
    char iesire;

    do
    {
        iesire='Y';
        cout << "\n---------------- MENIU APLICATIE SALA FITNESS ----------------\n";
        cout << "1. Adauga un antrenor in lista\n";
        cout << "2. Adauga un client in lista\n";
        cout << "3. Verifica valabilitate abonament \n";
        cout << "4. Programare sedinta cu antrenor\n";
        cout << "5. Upgrade client la VIP\n";
        cout << "6. Iesire\n\n";
        cout << "Introduceti optiunea dvs.: ";
        cin >> optiune;

        switch(optiune)
        {
        case 1:
        {
            Antrenor antrenor;

            cout<<"Introduceti numele antrenorului: ";
            std::string numeAntrenor;
            std::cin>>numeAntrenor;
            std::cout << "Introduceti prenumele antrenorului: ";
            std::string prenumeAntrenor;
            std::cin >> prenumeAntrenor;

            std::string numeComplet = numeAntrenor + " " + prenumeAntrenor;
            antrenor.setNume(numeComplet);

            cout<<"Introduceti numarul de telefon: ";
            std::string numarTelefon;
            cin>>numarTelefon;
            antrenor.setNumarTelefon(numarTelefon);

            cout<<"Introduceti nr de zile in care lucreaza antrenorul: ";
            int nrZile;
            cin>>nrZile;

            cout<<"Introduceti ziua, ora si clasa:"<<endl;
            std::string zi, ora, clasa;
            std::vector<orarAntrenor> orar;
            for(int i=0; i<nrZile; i++)
            {
                cout<<i+1<<": ";
                cin>>zi>>ora>>clasa;
                orar.push_back({zi, ora, clasa});
            }
            antrenor.setOrar(orar);

            antrenor.adaugaAntrenor(antrenor, listaAntrenori);

            cout<<endl<<"Lista antrenorilor este urmatoarea:"<<endl<<endl;
            for (size_t i = 0; i < listaAntrenori.size(); ++i)
                cout<<listaAntrenori[i]<<endl;
            cout<<endl<<endl;

            break;
        }

        case 2:
        {
            Client client;

            cout<<"Introduceti numele clientului: ";
            std::string numeClient;
            std::cin>>numeClient;
            std::cout << "Introduceti prenumele clientului: ";
            std::string prenumeClient;
            std::cin >> prenumeClient;

            std::string numeComplet2 = numeClient + " " + prenumeClient;
            client.setNume(numeComplet2);

            cout<<"Introduceti numarul de telefon: ";
            std::string numarTelefon2;
            cin>>numarTelefon2;
            client.setnumarTelefon(numarTelefon2);

            Abonament abonament;
            cout<<"Introduceti tipul abonamentului: ";
            std::string tipAbonament;
            cin>>tipAbonament;
            abonament.setTipAbonament(tipAbonament);

            DataAbonament dataInceputAb, dataSfarsitAb;
            int ziAb, lunaAb, anAb;

            cout<<"Introduceti ziua, luna si anul datei de inceput (numere): ";
            cin>>ziAb>>lunaAb>>anAb;
            dataInceputAb.zi=ziAb;
            dataInceputAb.luna=lunaAb;
            dataInceputAb.an=anAb;
            abonament.setDataInceput(dataInceputAb);

            cout<<"Introduceti ziua, luna si anul datei de sfarsit (numere) : ";
            cin>>ziAb>>lunaAb>>anAb;
            dataSfarsitAb.zi=ziAb;
            dataSfarsitAb.luna=lunaAb;
            dataSfarsitAb.an=anAb;
            abonament.setDataSfarsit(dataSfarsitAb);

            client.setAbonament(abonament);

            client.adaugaClient(client, listaClienti);

            cout<<endl<<"Lista clientilor este urmatoarea:"<<endl<<endl;
            for (size_t i = 0; i < listaClienti.size(); ++i)
                cout<<listaClienti[i]<<endl;
            cout<<endl<<endl;

            break;
        }
        case 3:
        {
            Abonament abonamentt;
            cout<<"Introduceti tipul abonamentului: ";
            std::string tipAbonamentt;
            cin>>tipAbonamentt;
            abonamentt.setTipAbonament(tipAbonamentt);

            DataAbonament dataInceputAbo, dataSfarsitAbo;
            int ziAbo, lunaAbo, anAbo;

            cout<<"Introduceti ziua, luna si anul datei de inceput (numere): ";
            cin>>ziAbo>>lunaAbo>>anAbo;
            dataInceputAbo.zi=ziAbo;
            dataInceputAbo.luna=lunaAbo;
            dataInceputAbo.an=anAbo;
            abonamentt.setDataInceput(dataInceputAbo);

            cout<<"Introduceti ziua, luna si anul datei de sfarsit (numere) : ";
            cin>>ziAbo>>lunaAbo>>anAbo;
            dataSfarsitAbo.zi=ziAbo;
            dataSfarsitAbo.luna=lunaAbo;
            dataSfarsitAbo.an=anAbo;
            abonamentt.setDataSfarsit(dataSfarsitAbo);

            if(abonamentt.verificaValabilitatea())
                cout<<"Abonamentul este valabil!"<<endl<<endl;
            else
                cout<<"Abonamentul este expirat!"<<endl<<endl;

            break;
        }
        case 4:
        {
            antrenor1.programareSedinta(listaAntrenori);
            break;
        }
        case 5:
        {
            ClientVIP clientVIP;
            cout<<"Introduceti numele clientuluiVIP: ";
            std::string numeClientVIP;
            std::cin>>numeClientVIP;
            std::cout << "Introduceti prenumele clientuluiVIP: ";
            std::string prenumeClientVIP;
            std::cin >> prenumeClientVIP;

            std::string numeCompletVIP = numeClientVIP + " " + prenumeClientVIP;
            clientVIP.setNume(numeCompletVIP);

            cout<<"Introduceti numarul de telefon: ";
            std::string numarTelefonVIP;
            cin>>numarTelefonVIP;
            clientVIP.setnumarTelefon(numarTelefonVIP);

            Abonament abonament;
            cout<<"Introduceti tipul abonamentului: ";
            std::string tipAbonament;
            cin>>tipAbonament;
            abonament.setTipAbonament(tipAbonament);

            DataAbonament dataInceputAb, dataSfarsitAb;
            int ziAb, lunaAb, anAb;

            cout<<"Introduceti ziua, luna si anul datei de inceput (numere): ";
            cin>>ziAb>>lunaAb>>anAb;
            dataInceputAb.zi=ziAb;
            dataInceputAb.luna=lunaAb;
            dataInceputAb.an=anAb;
            abonament.setDataInceput(dataInceputAb);

            cout<<"Introduceti ziua, luna si anul datei de sfarsit (numere) : ";
            cin>>ziAb>>lunaAb>>anAb;
            dataSfarsitAb.zi=ziAb;
            dataSfarsitAb.luna=lunaAb;
            dataSfarsitAb.an=anAb;
            abonament.setDataSfarsit(dataSfarsitAb);

            clientVIP.setAbonament(abonament);

            clientVIP.upgradeLaClientVIP();
            cout<<endl;

            break;
        }

        case 6:
            cout << "Ai iesit din Meniu.\n";
            iesire = 'N';
            break;
        default:
            cout << "Optiune invalida. Va rugam sa alegeti o optiune valida.\n";
            break;
        }
        std::cout << "Doresti sa continui? (Y/N): ";
        std::cin >> iesire;

        // Curăță ecranul consolei

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

    }
    while (iesire=='Y');

    std::cout << "La revedere!" << std::endl;


    return 0;
}
