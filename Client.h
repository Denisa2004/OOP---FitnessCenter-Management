#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Abonament.h"
#include "Antrenor.h"

class Client
{
protected:
    std::string nume;
    std::string numarTelefon;
    Abonament abonament;

public:
    Client();
    Client(const std::string &nume, const std::string &numarTelefon, const Abonament &abonament);

    ~Client();
    Client(const Client &other);

    Client &operator=(const Client &other);
    friend std::ostream &operator<<(std::ostream &os, const Client &client);

    void setNume(const std::string &nume);
    void setAbonament(const Abonament &abonament);
    void setnumarTelefon(const std::string &numarTelefon);

    Abonament getAbonament() const;
    std::string getNume() const;
    std::string getnumarTelefon() const;

    void adaugaClient(const Client& client, std::vector<Client>& listaClienti);

};

#endif // CLIENT_H
