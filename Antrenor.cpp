#include "Antrenor.h"
#include <string>
#include <vector>

Antrenor::Antrenor()=default;

Antrenor::Antrenor(const std::string &nume, const std::string &numarTelefon, const std::vector <orarAntrenor> &orar)
    : nume(nume), numarTelefon(numarTelefon), orar(orar) {}

Antrenor:: ~Antrenor()= default;

Antrenor::Antrenor(const Antrenor& other)
    : nume(other.nume), numarTelefon(other.numarTelefon), orar(other.orar) {}

Antrenor &Antrenor::operator=(const Antrenor &other)
{
    if (this != &other)
    {
        nume = other.nume;
        numarTelefon = other.numarTelefon;
        orar = other.orar;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const orarAntrenor& orar)
{
    os << "Ziua: " << orar.ziua << ", Ora: " << orar.ora << ", Clasa: " << orar.clasa;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Antrenor &antrenor)
{
    os << "Nume antrenor: " << antrenor.getNume() << ", Numar telefon: " << antrenor.getNumarTelefon()<< std::endl;
    os << "Orarul antrenorului:\n";
    std::vector <orarAntrenor> orar=antrenor.getOrar();
    for (int i=0; i<orar.size(); i++)
    {
        os << "Ziua: " << orar[i].ziua << ", Ora: " << orar[i].ora << ", Clasa: " << orar[i].clasa<<std::endl;
    }
    return os;
}

void Antrenor::setNume(const std::string &numeNou)
{
    nume = numeNou;
}

void Antrenor::setNumarTelefon(const std::string &numarTelefonNou)
{
    numarTelefon = numarTelefonNou;
}

void Antrenor::setOrar(const std::vector<orarAntrenor> &orarNou)
{
    orar = orarNou;
}

std::string Antrenor::getNume() const
{
    return nume;
}

std::string Antrenor::getNumarTelefon() const
{
    return numarTelefon;
}

std::vector<orarAntrenor> Antrenor::getOrar() const
{
    return orar;
}

void Antrenor::adaugaAntrenor(const Antrenor& antrenor, std::vector<Antrenor>& listaAntrenori)
{
    listaAntrenori.push_back(antrenor);
    std::cout << "Antrenorul " << antrenor.getNume() << " a fost adaugat cu succes.\n";
}

void Antrenor::programareSedinta(const std::vector<Antrenor>& listaAntrenori) const
{
    std::cout << "Alegeti un antrenor si o sedinta:\n" << std::endl;
    for (int i=0; i<listaAntrenori.size(); i++)
    {
        std::cout << listaAntrenori[i] << std::endl << std::endl;
    }

    std::cout << "Introduceti doar numele de familie al antrenorului cu care doriti sa faceti programarea: ";
    std::string numeAntrenor;
    std::cin >> numeAntrenor;

    std::string zi, ora;
    std::cout << "Introduceti ziua si ora pentru sedinta (format: zi ora): ";
    std::cin >> zi >> ora;

    std::cout << "Ati programat o sedinta cu antrenorul " << numeAntrenor << " pentru ziua de " << zi << " la ora " << ora << ".\n";
}
