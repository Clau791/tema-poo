//
// Created by klau2 on 10.04.2024.
//
#ifndef OOP_HOTEL_H
#define OOP_HOTEL_H


#include <iostream>
#include <Camera.h>
#include <vector>
#include <string>
#include <utility>

class Hotel {
private:
    std::string nume;
    //Initializam vectorul pentru a stoca și gestiona o colecție de camere
    std::vector<Camera> camere;

public:

    //Constructor pentru Hotel
    explicit Hotel(std::string  nume = "") : nume(std::move(nume)) {

    }

    [[nodiscard]] const std::string& getNume() const {
        return nume; }

    // Adaugam un getter pentru camere
    [[nodiscard]] const std::vector<Camera>& getCamere() const {
        return camere; }


    void adaugaCamera(const Camera& camera) {
        camere.push_back(camera);
    }

    //supraincarcarea operatorului << pentru clasa Hotel
    friend std::ostream& operator<<(std::ostream& out, const Hotel& hotel) {
        out << "Hotel: " << hotel.nume << "\n";
        for (const auto& camera : hotel.camere) {
            out << camera << "\n";
        }
        return out;
    }
    //supraincarcarea operatorului >> pentru clasa Hotel
    friend std::istream& operator>>(std::istream& in, Hotel& hotel) {
        std::cout << "Nume Hotel: ";
        in >> hotel.nume;
        int nrCamere;
        std::cout << "Nr camere: ";
        in >> nrCamere;
        Camera temp;
        for (int i = 0; i < nrCamere; i++) {
            std::cout << "Camera " << i + 1 << ": ";
            in >> temp;
            hotel.camere.push_back(temp);
        }
        return in;
    }

    //destructor
    ~Hotel() = default;
};


#endif //OOP_HOTEL_H
