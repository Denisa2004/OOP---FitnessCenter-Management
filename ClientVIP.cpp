#include "ClientVIP.h"
#include "Client.h"
#include <iostream>

ClientVIP::ClientVIP()=default;

ClientVIP::ClientVIP(const std::string &nume,  const std::string &numarTelefon, const Abonament &abonament, const std::string &codAcces)
    : Client(nume,numarTelefon, abonament), codAccesVIP(codAcces) {}

ClientVIP::~ClientVIP()=default;

ClientVIP::ClientVIP(const ClientVIP &other)
    : Client(other), codAccesVIP(other.codAccesVIP) {}


ClientVIP &ClientVIP::operator=(const ClientVIP &other)
{
    if (this != &other)
    {
        Client::operator=(other); // Apel operatorul de atribuire al clasei de bază
        codAccesVIP = other.codAccesVIP;
        progSauna = other.progSauna;
        progJacuzzi = other.progJacuzzi;
    }
    return *this;
}


std::ostream &operator<<(std::ostream &os, const ClientVIP &client)
{
    os << static_cast<const Client &>(client); // Afiseaza detalii comune
    os << "Cod Acces VIP: " << client.codAccesVIP << "\n";
    if (!(client.progSauna.zi.empty()) && !(client.progSauna.ora.empty()))
        os << "Programare Sauna: " << client.progSauna.zi << " la ora " << client.progSauna.ora << "\n";
    if(!(client.progJacuzzi.zi.empty()) && !(client.progJacuzzi.ora.empty()))
        os << "Programare Jacuzzi: " << client.progJacuzzi.zi << " la ora " << client.progJacuzzi.ora << "\n";
    return os;
}

std::string ClientVIP::getCodAccesVIP()
const
{
    return codAccesVIP;
}

void ClientVIP::setCodAccesVIP(const std::string &codAcces)
{
    codAccesVIP = codAcces;
}

Programare ClientVIP::getprogramareSauna() const
{
    if (progSauna.zi.empty() && progSauna.ora.empty())
        return { "", "" };
    else
        return progSauna;

}

Programare ClientVIP::getprogramareJacuzzi() const
{
    if (progJacuzzi.zi.empty() && progJacuzzi.ora.empty())
        return { "", "" };
    else
        return progJacuzzi;
}

void ClientVIP::setprogramareSauna(const std::string &zi, const std::string &ora)
{
    progSauna.zi = zi;
    progSauna.ora = ora;
}

void ClientVIP::setprogramareJacuzzi(const std::string &zi, const std::string &ora)
{
    progJacuzzi.zi = zi;
    progJacuzzi.ora = ora;
}

void ClientVIP::upgradeLaClientVIP()
{
    std::string codAcces;
    std::cout << "Upgrade-ul la client VIP pentru clientul " << nume << ".\n";
    std::cout << "Introduceti codul de acces VIP: ";
    std::cin >> codAcces;
    setCodAccesVIP(codAcces); // Setare cod acces VIP

    char optiuneProgramare;
    std::cout << "Doriti programare la sauna/jacuzzi? (S/J): ";
    std::cin >> optiuneProgramare;

    if (optiuneProgramare == 'S')
    {
        std::cout << "Introduceti data programarii pentru sauna (format: ziLuna) : ";
        std::cin >> progSauna.zi;
        std::cout << "Introduceti ora programarii pentru sauna: ";
        std::cin >> progSauna.ora;
    }
    else if (optiuneProgramare == 'J')
    {
        std::cout << "Introduceti data programarii pentru jacuzzi (format: ziLuna) : ";
        std::cin >> progJacuzzi.zi;
        std::cout << "Introduceti ora programarii pentru jacuzzi: ";
        std::cin >> progJacuzzi.ora;
    }
}
