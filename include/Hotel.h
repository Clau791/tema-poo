//
// Created by klau2 on 10.04.2024.
//
#ifndef OOP_HOTEL_H
#define OOP_HOTEL_H
#include <iostream>
#include <vector>
#include <string>
#include "Camera.h"
#include "CameraVIP.h"
#include "CameraEco.h"
#include <memory>
template <typename T>

// clasa nu a fost modificata de la tema 1
class Hotel {
private:
    std::string nume;


public:
    std::vector<T> camere;
    explicit Hotel(std::string nume = "");
    [[nodiscard]] const std::string& getNume() const;
    [[nodiscard]] const std::vector<Camera<std::string>>& getCamere() const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Hotel<U>& hotel);
    template<typename U>
    friend std::istream& operator>>(std::istream& in, Hotel<U>& hotel);
    virtual ~Hotel();

    void adaugaCamera(const T& camera);
};
#include "Hotel.h"

template<typename T>
Hotel<T>::Hotel(std::string nume) : nume(std::move(nume)) {}

template<typename T>
const std::string& Hotel<T>::getNume() const {
    return nume;
}

template<typename T>
const std::vector<Camera<std::string>>& Hotel<T>::getCamere() const {
    return camere;
}

template <typename T>
void Hotel<T>::adaugaCamera(const T& camera) {
    camere.push_back(camera);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Hotel<T>& hotel) {
    out << "Hotel: " << hotel.nume << "\n";
    for (const auto& camera : hotel.camere) {
        out << camera;
    }
    return out;
}

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

template<typename T>
Hotel<T>::~Hotel() = default;

#endif //OOP_HOTEL_H
