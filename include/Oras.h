#ifndef OOP_ORAS_H
#define OOP_ORAS_H

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "Hotel.h"

template <typename T>
class Oras {
private:
    std::string nume;
    std::vector< Hotel<Camera<std::string>>> hoteluri; // vectorul cu hoteluri din oras

public:

    explicit Oras(std::string nume);
    [[maybe_unused]] [[nodiscard]] const std::string& getNume() const;
    [[nodiscard]] const std::vector<Hotel<Camera<std::string>>>& getHoteluri() const;
    void adaugaHotel(const Hotel<Camera<std::string>>& hotel);
    virtual ~Oras();

};

template<typename T>
Oras<T>::~Oras() = default;


// Constructor
template<typename T>
Oras<T>::Oras(std::string nume) : nume(std::move(nume)) {}


// Getter pentru numele orașului
template<typename T>
const std::string& Oras<T>::getNume() const {
    return nume;
}

// Getter pentru vectorul de hoteluri
template<typename T>
const std::vector<Hotel<Camera<std::string>>>& Oras<T>::getHoteluri() const {
    return hoteluri;
}

// Metoda pentru adaugarea unui hotel în oraș
template<typename T>
void Oras<T>::adaugaHotel(const Hotel<Camera<std::string>>& hotel) {
    hoteluri.push_back(hotel);
}
#endif // OOP_ORAS_H
