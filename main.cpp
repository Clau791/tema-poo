#include <iostream>
#include <utility>
#include <vector>
#include <string>

class Camera {
private:
    int numar;
    std::string tip;
    double pretPeNoapte;
    bool esteOcupata;
public:

    // Getter-e pentru numarul, tipul ,disponibilitatea si pretul camerei.

    [[maybe_unused]] [[nodiscard]] int getNumar() const {
        return numar; }

    [[maybe_unused]] [[nodiscard]] std::string getTip() const {
        return tip; }

    [[maybe_unused]] [[nodiscard]] double getPretPeNoapte() const {
        return pretPeNoapte; }

    [[nodiscard]] bool getEsteOcupata() const  {
        return esteOcupata  ; }


    //Constructor pentru Camera
    explicit Camera(int numar = 0, std::string tip = "Standard", double pretPeNoapte = 0.0, bool esteOcupata = false)
            : numar(numar), tip(std::move(tip)), pretPeNoapte(pretPeNoapte), esteOcupata(esteOcupata) {

    }

    // Constructor de copiere
    Camera(const Camera& sursa) =default ;


    //Supraincarcarea parametrului <<
    friend std::ostream& operator<<(std::ostream& out, const Camera& camera) {
        out << "Nr: " << camera.numar << ", Tip: " << camera.tip
            << ", Pret: " << camera.pretPeNoapte << ", "
            << (camera.esteOcupata ? "Ocupata" : "Libera");
        return out;
    }

    //Supraincarcarea parametrului >>

    friend std::istream& operator>>(std::istream& in, Camera& camera) {
        in >> camera.numar >> camera.tip >> camera.pretPeNoapte >> camera.esteOcupata;
        return in;
    }

    // Setter pentru cazul rezervarii camerei
    void SetterOcupata()  {
        this ->esteOcupata = !esteOcupata ;
    }

    //destructor
    ~Camera() = default;

};
class Hotel {
private:
    std::string nume;
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

    friend std::ostream& operator<<(std::ostream& out, const Hotel& hotel) {
        out << "Hotel: " << hotel.nume << "\n";
        for (const auto& camera : hotel.camere) {
            out << camera << "\n";
        }
        return out;
    }

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
    ~Hotel() = default;
};

class Oras {
private:
    std::string nume;
    std::vector<Hotel> hoteluri;

public:

    //Constructor pentru Oras
    explicit Oras(std::string  nume = "") : nume(std::move(nume)) {

    }

    [[nodiscard]] const std::string& getNume() const {
        return nume;
    }

    // Adaugam un getter pentru hoteluri
    [[nodiscard]] const std::vector<Hotel>& getHoteluri() const {
        return hoteluri;
    }

    void adaugaHotel(const Hotel& hotel) {
        hoteluri.push_back(hotel);
    }

    friend std::ostream& operator<<(std::ostream& out, const Oras& oras) {
        out << "Oras: " << oras.nume << "\n";
        for (const auto& hotel : oras.hoteluri) {
            out << hotel;
        }
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Oras& oras) {
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
    ~Oras() =default;
};


int main() {
    // Crearea a două hoteluri
    Hotel hotel1("Grand Plaza");
    Camera camera1(101, "Dubla", 300.0);
    Camera camera2(102, "Single", 150.0);
    Camera camera3(103, "Dubla", 350.0, true);
    Camera camera4(104, "Dubla", 370.0);
    Camera camera5(105, "Dubla", 130.0, true);
    hotel1.adaugaCamera(camera1);
    hotel1.adaugaCamera(camera2);
    hotel1.adaugaCamera(camera3);
    hotel1.adaugaCamera(camera4);
    hotel1.adaugaCamera(camera5);


    Hotel hotel3("Grand Hotel");
    Camera camera30(301, "Dubla", 320.0);
    Camera camera31(302, "Single", 150.0);
    Camera camera32(303, "Dubla", 350.0, true);
    Camera camera33(304, "Dubla", 370.0, true);
    Camera camera34(305, "Dubla", 330.0, true);
    hotel3.adaugaCamera(camera30);
    hotel3.adaugaCamera(camera31);
    hotel3.adaugaCamera(camera32);
    hotel3.adaugaCamera(camera33);
    hotel3.adaugaCamera(camera34);



    Hotel hotel2("Sea View");
    Camera camera20(201, "Tripla", 500.0);
    Camera camera22(202, "Single", 180.0);
    Camera camera23(203, "Dubla", 250.0, true);
    Camera camera24(204, "Tripla", 450.0, true);
    Camera camera25(205, "Tripla", 350.0);
    hotel2.adaugaCamera(camera20);
    hotel2.adaugaCamera(camera22);
    hotel2.adaugaCamera(camera23);
    hotel2.adaugaCamera(camera24);
    hotel2.adaugaCamera(camera25);


    // Crearea unui oraș si adaugar ea hotelurilor în oraș
    Oras oras1("Constanta");
    Oras oras2("Bucuresti");
    oras1.adaugaHotel(hotel1);
    oras1.adaugaHotel(hotel2);
    oras2.adaugaHotel(hotel3);


    bool continua = true;

    std::vector<Oras> orase = {oras1, oras2}; //  vectorul cu orașele create

    while (continua) {


        std::cout << "Selectati un oras:\n";
        for (size_t i = 0; i < orase.size(); i++) {
            std::cout << i + 1 << ". " << orase[i].getNume() << std::endl;
        }

        int optiuneOras;
        std::cin >> optiuneOras;

        if (optiuneOras < 1 || optiuneOras > static_cast<int>(orase.size())) {
            std::cout << "Optiune invalida. Incercati din nou.\n";
            continue;
        }


        Oras &orasAles = orase[optiuneOras - 1];
        const std::vector<Hotel> &hoteluri = orasAles.getHoteluri();

        std::cout << "Selectati un hotel din " << orasAles.getNume() << ":\n";

        for (size_t j = 0; j < hoteluri.size(); ++j) {
            std::cout << j + 1 << ". " << hoteluri[j].getNume() << std::endl;
        }
        int optiuneHotel;


        while (true) {

            std::cin >> optiuneHotel;

            if (optiuneHotel < 1 || optiuneHotel > static_cast<int>(hoteluri.size())) {
                std::cout << "Optiune invalida. Incercati din nou.\n";
                continue;

            }
            break;
        }


        auto &hotelAles = const_cast<Hotel &>(hoteluri[optiuneHotel - 1]);

       auto &camere = const_cast<std::vector<Camera> &>(hotelAles.getCamere()); // Obținem acces la modificare

        std::cout << "Selectati o camera din " << hotelAles.getNume() << ":\n";
        for (size_t k = 0; k < camere.size(); ++k) {
            std::cout << k + 1 << ". " << camere[k] << std::endl;
        }

        int optiuneCamera;

        while (true) {
            std::cin >> optiuneCamera;

            if (optiuneCamera < 1 || optiuneCamera > static_cast<int>(camere.size())) {
                std::cout << "Optiune invalida. Incercati din nou.\n";
                continue; // Reincepe bucla dacă selecția este invalida
            }

            int indexCamera = optiuneCamera - 1;
            if (camere[indexCamera].getEsteOcupata()) {
                std::cout << "Camera este deja ocupata.\n";

                // Ofera utilizatorului opțiunea de a alege o altă camera
                std::cout << "Va rugam sa selectati o alta camera.\n";
            } else {

                camere[indexCamera].SetterOcupata();
               // std::cout << camere[indexCamera].getEsteOcupata()<<std::endl;// Verifica daca camera a fost ocupata

                std::cout << "Camera "<<camere[indexCamera].getNumar()<<" a fost rezervata cu succes.\n";
                break; // Ieșire din bucla când rezervarea este efectuata cu succes
            }
        }

        std::cout << "Doriti sa continuati? (0 = nu, orice alt numar = da): ";
        int continua1;
        std::cin >> continua1;
        if (continua1 == 0) {
            continua = false;
        }


    }
}
