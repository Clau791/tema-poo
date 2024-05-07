#ifndef OOP_HOTEL_H
#define OOP_HOTEL_H

#include <iostream>
#include <vector>
#include <string>
#include "Camera.h"

template <typename T>
class Hotel {
private:
    std::string nume;

public:
    std::vector<T> camere; // Vector care stocheaza camere de tip T

    // Constructor care inițializeaza numele hotelului
    explicit Hotel(std::string nume = "") : nume(std::move(nume)) {}

    // Returneaza numele hotelului
    [[nodiscard]] const std::string& getNume() const {
        return nume;
    }

    // Returneaza vectorul de camere, corectat să foloseasca T
    [[nodiscard]] const std::vector<T>& getCamere() const {
        return camere;
    }

    // Adauga o camera la lista de camere a hotelului
    void adaugaCamera(const T& camera) {
        camere.push_back(camera);
    }

    // Destructor virtual
    virtual ~Hotel();

    // Supraincarcare pentru operatorii << și >>
    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Hotel<U>& hotel);

    template<typename U>
    friend std::istream& operator>>(std::istream& in, Hotel<U>& hotel);
};

template<typename T>
Hotel<T>::~Hotel() = default;

// Definirea operatorului <<
template<typename T>
std::ostream& operator<<(std::ostream& out, const Hotel<T>& hotel) {
    out << "Hotel: " << hotel.nume << "\n";
    for (const auto& camera : hotel.camere) {
        out << camera;
    }
    return out;
}

// Definirea operatorului >>
template<typename T>
std::istream& operator>>(std::istream& in, Hotel<T>& hotel) {
    std::cout << "Nume Hotel: ";
    in >> hotel.nume;
    int nrCamere;
    std::cout << "Nr camere: ";
    in >> nrCamere;
    T temp;
    for (int i = 0; i < nrCamere; i++) {
        std::cout << "Camera " << i + 1 << ": ";
        in >> temp;
        hotel.camere.push_back(temp);
    }
    return in;
}

#endif // OOP_HOTEL_H
