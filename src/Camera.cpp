#include "Camera.h"

int Camera::reducere = 0;
int Camera::camereOcupate = 0;
int SumaDePlata = 0;

Camera::Camera(int numar, std::string tip, int pretPeNoapte, bool esteOcupata)
        : numar(numar), tip(std::move(tip)), pretPeNoapte(pretPeNoapte), esteOcupata(esteOcupata) {}


Camera::Camera(const Camera& sursa)
        : numar(sursa.numar), tip(sursa.tip), pretPeNoapte(sursa.pretPeNoapte), esteOcupata(sursa.esteOcupata) {}


void Camera::actualizeazaReducere() {
    if (camereOcupate >= 2 && camereOcupate < 3) {
        reducere = 50;
    } else if (camereOcupate >= 3) {
        reducere = 100;
    }
    std::cout << "Reducerea actualizata este: " << reducere << " RON" << std::endl;
}

void Camera::SetterOcupata() {
    esteOcupata = !esteOcupata;
}

void Camera::AfiseazaDetalii() {
    std::cout << "Camera " << numar << ": " << tip << ", " << pretPeNoapte << " RON, "
              << (esteOcupata ? "Ocupata" : "Libera") << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Camera& camera) {
    out << "Nr: " << camera.numar << ", Tip: " << camera.tip
        << ", Pret: " << camera.pretPeNoapte << ", "
        << (camera.esteOcupata ? "Ocupata" : "Libera");
    return out;
}

std::istream& operator>>(std::istream& in, Camera& camera) {
    in >> camera.numar >> camera.tip >> camera.pretPeNoapte >> camera.esteOcupata;
    return in;
}

Camera::~Camera() {}

