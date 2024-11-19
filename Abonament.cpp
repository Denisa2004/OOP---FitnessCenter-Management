#include "Abonament.h"
#include <string>

Abonament::Abonament()=default;

Abonament::Abonament(const std::string &tip, const DataAbonament &inceput, const DataAbonament &sfarsit)
    : tip_abonament(tip), data_inceput(inceput), data_sfarsit(sfarsit) {}


Abonament::~Abonament() =default;

Abonament::Abonament(const Abonament &other)
    : tip_abonament(other.tip_abonament), data_inceput(other.data_inceput), data_sfarsit(other.data_sfarsit) {}

Abonament &Abonament::operator=(const Abonament &other)
{
    if (this != &other)
    {
        tip_abonament = other.tip_abonament;
        data_inceput = other.data_inceput;
        data_sfarsit = other.data_sfarsit;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Abonament &abonament)
{
    os << "Tip abonament: " << abonament.tip_abonament << ", Data inceput: "
       << abonament.data_inceput.zi << "/" << abonament.data_inceput.luna << "/" << abonament.data_inceput.an
       << ", Data sfarsit: " << abonament.data_sfarsit.zi << "/" << abonament.data_sfarsit.luna << "/"
       << abonament.data_sfarsit.an;
    return os;
}

void Abonament::setTipAbonament(const std::string &tip)
{
    tip_abonament = tip;
}

void Abonament::setDataInceput(const DataAbonament &inceput)
{
    data_inceput = inceput;
}

void Abonament::setDataSfarsit(const DataAbonament &sfarsit)
{
    data_sfarsit = sfarsit;
}

std::string Abonament::getTipAbonament() const
{
    return tip_abonament;
}

DataAbonament Abonament::getDataInceput() const
{
    return data_inceput;
}

DataAbonament Abonament::getDataSfarsit() const
{
    return data_sfarsit;
}

bool Abonament::verificaValabilitatea() const
{
    DataAbonament data_curenta = {28, 3, 2024};

    if (data_curenta.an < data_inceput.an || data_curenta.an > data_sfarsit.an)
        return false;
    else if (data_curenta.an == data_inceput.an && data_curenta.luna < data_inceput.luna)
        return false;
    else if (data_curenta.an == data_inceput.an && data_curenta.luna == data_inceput.luna && data_curenta.zi < data_inceput.zi)
        return false;
    else if (data_curenta.an == data_sfarsit.an && data_curenta.luna > data_sfarsit.luna)
        return false;
    else if (data_curenta.an == data_sfarsit.an && data_curenta.luna == data_sfarsit.luna && data_curenta.zi > data_sfarsit.zi)
        return false;

    return true;
}
