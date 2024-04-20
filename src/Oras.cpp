//
// Created by klau2 on 20.04.2024.
//
#include "Oras.h"

Oras::Oras(std::string nume) : nume(std::move(nume)) {}

const std::string& Oras::getNume() const {
    return nume;
}

const std::vector<Hotel>& Oras::getHoteluri() const {
    return hoteluri;
}

void Oras::adaugaHotel(const Hotel& hotel) {
    hoteluri.push_back(hotel);
}

std::ostream& operator<<(std::ostream& out, const Oras& oras) {
    out << "Oras: " << oras.nume << "\n";
    for (const auto& hotel : oras.hoteluri) {
        out << hotel;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Oras& oras) {
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

Oras::~Oras() = default;
