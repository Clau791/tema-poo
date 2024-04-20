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


    return in;
}

Oras::~Oras() = default;
