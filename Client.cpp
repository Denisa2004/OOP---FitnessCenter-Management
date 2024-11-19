#include "Client.h"
#include "ClientVIP.h"
#include <vector>

Client::Client()=default;

Client::Client(const std::string &nume, const std::string &numarTelefon, const Abonament &abonament)
    : nume(nume), numarTelefon(numarTelefon), abonament(abonament) {}


Client::~Client()=default;

Client::Client(const Client &other)
    : nume(other.nume), abonament(other.abonament), numarTelefon(other.numarTelefon) {}


Client& Client::operator=(const Client& other)
{
    if (this != &other)
    {
        nume = other.nume;
        abonament = other.abonament;
        numarTelefon=other.numarTelefon;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Client &client)
{
    os << "Nume: " << client.getNume() << "\n";
    os << "Numar de telefon: " << client.getnumarTelefon() << "\n";
    os << "Abonament:" << client.getAbonament() << "\n";
    return os;
}

std::string Client::getNume() const
{
    return nume;
}

void Client::setNume(const std::string& nume)
{
    this->nume = nume;
}

std::string Client::getnumarTelefon() const
{
    return numarTelefon;
}

void Client::setnumarTelefon(const std::string& numarTelefon)
{
    this->numarTelefon = numarTelefon;
}

Abonament Client::getAbonament() const
{
    return abonament;
}

void Client::setAbonament(const Abonament& abonament)
{
    this->abonament = abonament;
}

void Client::adaugaClient(const Client& client, std::vector<Client>& listaClienti)
{
    listaClienti.push_back(client);
    std::cout << "Clientul " << client.getNume() << " a fost adaugat cu succes.\n";
}

