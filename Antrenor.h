#ifndef ANTRENOR_H
#define ANTRENOR_H

#include <iostream>
#include <string>
#include <vector>

struct orarAntrenor
{
    std::string ziua;
    std::string ora;
    std::string clasa;
};

class Antrenor
{
    std::string nume;
    std::string numarTelefon;
    std::vector <orarAntrenor> orar;

public:
    Antrenor();
    Antrenor(const std::string &nume, const std::string &numarTelefon, const std::vector<orarAntrenor> &orar);

    Antrenor(const Antrenor &other); // Constructor de copiere implicit
    ~Antrenor(); // Destructor implicit

    Antrenor &operator=(const Antrenor &other); // Operator de copiere implicit
    friend std::ostream& operator<<(std::ostream& os, const orarAntrenor& orar);
    friend std::ostream &operator<<(std::ostream &os, const Antrenor &antrenor);// Operatorul de afisare

    void setNume(const std::string &nume);
    void setNumarTelefon(const std::string  &numarTelefon);
    void setOrar(const std::vector<orarAntrenor> &orar);

    std::string getNume() const;
    std::string getNumarTelefon() const;
    std::vector<orarAntrenor> getOrar() const;

    void adaugaAntrenor(const Antrenor& antrenor, std::vector<Antrenor>& listaAntrenori);
    void programareSedinta(const std::vector<Antrenor>& listaAntrenori) const;

};

#endif // ANTRENOR_H
