#ifndef ABONAMENT_H
#define ABONAMENT_H

#include <string>
#include <iostream>

struct DataAbonament
    {
        int zi;
        int luna;
        int an;
    };

class Abonament
{
    std::string tip_abonament;
    DataAbonament data_inceput;
    DataAbonament data_sfarsit;

public:
    Abonament();
    Abonament(const std::string &abonament, const DataAbonament &inceput, const DataAbonament &sfarsit);

    Abonament(const Abonament &other); // Constructor de copiere implicit
    ~Abonament(); // Destructor implicit

    Abonament &operator=(const Abonament &other); // Operator de copiere implicit
    friend std::ostream &operator<<(std::ostream &os, const Abonament &abonament);// Operatorul de afisare

    void setTipAbonament(const std::string &tip);
    void setDataInceput(const DataAbonament &data_inceput);
    void setDataSfarsit(const DataAbonament &data_sfarsit);

    std::string getTipAbonament() const;
    DataAbonament getDataInceput() const;
    DataAbonament getDataSfarsit() const;

    bool verificaValabilitatea() const;

};

#endif // ABONAMENT_H
