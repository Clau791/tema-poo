#include "Hotel.h"

Hotel::Hotel(std::string nume) : nume(std::move(nume)) {}

const std::string& Hotel::getNume() const {
    return nume;
}

const std::vector<Camera>& Hotel::getCamere() const {
    return camere;
}

void Hotel::adaugaCamera(const Camera& camera) {
    camere.push_back(camera);
}

std::ostream& operator<<(std::ostream& out, const Hotel& hotel) {
    out << "Hotel: " << hotel.nume << "\n";
    for (const auto& camera : hotel.camere) {
        out << camera;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Hotel& hotel) {
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

Hotel::~Hotel() = default;

