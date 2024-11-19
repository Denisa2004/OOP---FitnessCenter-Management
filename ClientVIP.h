#ifndef CLIENTVIP_H
#define CLIENTVIP_H

#include "Client.h"

struct Programare
{
    std::string zi;
    std::string ora;

};

class ClientVIP : public Client
{
    std::string codAccesVIP;
    Programare progSauna;
    Programare progJacuzzi;

public:

    ClientVIP();
    ClientVIP(const std::string &nume,  const std::string &numarTelefon, const Abonament &abonament, const std::string &codAcces);

    ~ClientVIP();
    ClientVIP(const ClientVIP &other);

    ClientVIP &operator=(const ClientVIP &other);
    friend std::ostream &operator<<(std::ostream &os, const ClientVIP &client);

    void setCodAccesVIP(const std::string& codAcces);
    std::string getCodAccesVIP() const;

    void setprogramareSauna(const std::string &zi, const std::string &ora);
    Programare getprogramareSauna() const;

    void setprogramareJacuzzi(const std::string &zi, const std::string &ora);
    Programare getprogramareJacuzzi() const;

    void upgradeLaClientVIP();

};

#endif // CLIENTVIP_H
