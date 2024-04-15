//
// Created by klau2 on 10.04.2024.
//
#ifndef OOP_ORAS_H
#define OOP_ORAS_H
#include <iostream>
#include <utility>
#include <vector>
#include <string>
//#include <Camera.h>
#include <Hotel.h>


class Oras {
private:
    std::string nume;

    //Initializam vectorul pentru a stoca și gestiona hotelurile
    std::vector<Hotel> hoteluri;

public:

    //Constructor pentru Oras
    explicit Oras(std::string  nume = "") : nume(std::move(nume)) {

    }

    [[nodiscard]] const std::string& getNume() const {
        return nume;
    }

    // Adaugam un getter pentru hoteluri
    [[nodiscard]] const std::vector<Hotel>& getHoteluri() const {
        return hoteluri;
    }

    void adaugaHotel(const Hotel& hotel) {
        hoteluri.push_back(hotel);
    }

    friend std::ostream& operator<<(std::ostream& out, const Oras& oras) {
        out << "Oras: " << oras.nume << "\n";
        for (const auto& hotel : oras.hoteluri) {
            out << hotel;
        }
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Oras& oras) {
        std::cout << "Nume Oras: ";
        in >> oras.nume;
        int nrHoteluri;
        std::cout << "Nr hoteluri: ";
        in >> nrHoteluri;
        Hotel temp;
        for (int i = 0; i < nrHoteluri; i++) {
            std::cout << "Hotel " << i + 1 << ": ";
            in >> temp;
            oras.hoteluri.push_back(temp);
        }
        return in;
    }
    ~Oras() =default;
};


#endif //OOP_ORAS_H
