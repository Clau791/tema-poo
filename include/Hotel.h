//
// Created by klau2 on 10.04.2024.
//
#ifndef OOP_HOTEL_H
#define OOP_HOTEL_H

#include <iostream>
#include <vector>
#include <string>
#include "Camera.h" // Asigurați-vă că includeți corect header-ul

class Hotel {
private:
    std::string nume;
    std::vector<Camera> camere;

public:
    explicit Hotel(std::string nume = "");
    [[nodiscard]] const std::string& getNume() const;
    [[nodiscard]] const std::vector<Camera>& getCamere() const;
    void adaugaCamera(const Camera& camera);

    friend std::ostream& operator<<(std::ostream& out, const Hotel& hotel);
    friend std::istream& operator>>(std::istream& in, Hotel& hotel);

    virtual ~Hotel();
};


#endif //OOP_HOTEL_H
