#ifndef OOP_ORAS_H
#define OOP_ORAS_H

#include <iostream>
#include <vector>
#include <string>
#include "Hotel.h" // Make sure this includes the definition of Hotel and Camera properly.

template <typename T>
class Oras {
private:
    std::string nume;
    std::vector< Hotel<Camera<std::string>>> hoteluri;
public:
    explicit Oras(std::string nume); // Constructor should be declared here, not defined

    [[maybe_unused]] [[nodiscard]] const std::string& getNume() const;
    [[nodiscard]] const std::vector<Hotel<Camera<std::string>>>& getHoteluri() const;
    void adaugaHotel(const Hotel<Camera<std::string>>& hotel);

    virtual ~Oras(); // If this doesn't manage resources directly, it might not need to be virtual
};

template<typename T>
Oras<T>::~Oras() = default;

// Member function definitions should be outside the class declaration if not defined inline


// Constructor
template<typename T>
inline Oras<T>::Oras(std::string nume) : nume(std::move(nume)) {}


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

// Metoda pentru adăugarea unui hotel în oraș
template<typename T>
void Oras<T>::adaugaHotel(const Hotel<Camera<std::string>>& hotel) {
    hoteluri.push_back(hotel);
}
#endif // OOP_ORAS_H
