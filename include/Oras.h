#ifndef OOP_ORAS_H
#define OOP_ORAS_H

#include <iostream>
#include <vector>
#include <string>
#include "Hotel.h"

class Oras {
private:
    std::string nume;
    std::vector<Hotel> hoteluri;

public:
    explicit Oras(std::string nume = "");

    [[nodiscard]] const std::string& getNume() const;
    [[nodiscard]] const std::vector<Hotel>& getHoteluri() const;

    void adaugaHotel(const Hotel& hotel);

    friend std::ostream& operator<<(std::ostream& out, const Oras& oras);
    friend std::istream& operator>>(std::istream& in, Oras& oras);

    virtual ~Oras();
};

#endif // OOP_ORAS_H
