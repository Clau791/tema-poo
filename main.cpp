#include <iostream>
#include <vector>
#include <string>
// separarea codului din clase în `.h`
#include <Hotel.h>
#include <Oras.h>


int main() {

   //tema 2

    class CameraVIP : public Camera {

    public:
        CameraVIP(int nr, double pret, bool ocupata )
                : Camera(nr, "VIP", pret, ocupata)   { // NOLINT(*-narrowing-conversions)

        }
        //am apelat constructorul din clasa de baza

        void AfiseazaDetalii() override  {
            Camera::AfiseazaDetalii();
            std::cout << "   " << std::endl;
        }


     };

    // Crearea a 3 hoteluri
    Hotel hotel1("Grand Plaza");

    Camera camera1(101, "Dubla", 300.0);
    Camera camera2(102, "Single", 300.0);
    Camera camera3(103, "Dubla", 300.0, true);
    Camera camera4(104, "Dubla", 300.0);
    Camera camera5(105, "Dubla", 300.0, true);
    hotel1.adaugaCamera(camera1);
    hotel1.adaugaCamera(camera2);
    hotel1.adaugaCamera(camera3);
    hotel1.adaugaCamera(camera4);
    hotel1.adaugaCamera(camera5);


    Hotel hotel2("Sea View");
    Camera camera22(202, "Single", 300.0);
    Camera camera23(203, "Dubla", 300.0, true);
    Camera camera24(204, "Tripla", 300.0, true);
    Camera camera25(205, "Tripla", 300.0);
    hotel2.adaugaCamera(camera22);
    hotel2.adaugaCamera(camera23);
    hotel2.adaugaCamera(camera24);
    hotel2.adaugaCamera(camera25);

    Hotel hotel3("Grand Hotel");
    Camera camera30(301, "Dubla", 300.0);
    Camera camera31(302, "Single", 300.0);
    Camera camera32(303, "Dubla", 300.0, true);
    Camera camera33(304, "Dubla", 300.0, true);
    Camera camera34(305, "Dubla", 300.0, true);
    Camera camera35(305, "Tripla", 300.0);

    hotel3.adaugaCamera(camera30);
    hotel3.adaugaCamera(camera31);
    hotel3.adaugaCamera(camera32);
    hotel3.adaugaCamera(camera33);
    hotel3.adaugaCamera(camera34);
    hotel3.adaugaCamera(camera35);

    // Crearea unui oraș si adaugarea hotelurilor în oraș
    Oras oras1("Constanta");
    Oras oras2("Bucuresti");
    oras1.adaugaHotel(hotel1);
    oras1.adaugaHotel(hotel2);
    oras2.adaugaHotel(hotel3);


    //tema 2
    CameraVIP cameraVip1(1, 500.0, false);
    hotel1.adaugaCamera(cameraVip1);
    cameraVip1.AfiseazaDetalii();

    bool continua = true;
    Camera::camereOcupate = 0; // pentru a nu se incrementa si camerele deja initializate cu false

    std::vector<Oras> orase = {oras1, oras2}; //  vectorul cu orașele create

    while (continua) {


        std::cout << "Selectati un oras:\n";
        //pentru a afisa toate orasele din vector
        for (size_t i = 0; i < orase.size(); i++) {
            std::cout << i + 1 << ". " << orase[i].getNume() << std::endl;
        }

        int optiuneOras;
        std::cin >> optiuneOras;

        if (optiuneOras < 1 || optiuneOras > static_cast<int>(orase.size())) {
            std::cout << "Optiune invalida. Incercati din nou.\n";
            continue;
        }
        //am folosit static_cast<int> pentru a ne asigura ca tipul de
        // date returnat este int(nu unsigned cum s-ar fi intamplat fara el)

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
        //obține o referința la hotelul ales din vectorul de hoteluri, pentru a face afisari/modificari

        auto &camere = const_cast<std::vector<Camera> &>(hotelAles.getCamere());
        //obține o referința la hotelul ales din vectorul de camere, pentru a face afisari/modificari

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
                SumaDePlata = SumaDePlata + camere[indexCamera].getPret();
                break; // Ieșire din bucla când rezervarea este efectuata cu succes
            }
        }


        Camera::camereOcupate ++; //incrementam camerele ocupate
        Camera::actualizeazaReducere(); //stabilim reducerea acordata pe baza numarului de camere rezervate
        std::cout << "Suma totala pe care o aveti de platit este: " << SumaDePlata -Camera::reducereGlobala << " RON" << std::endl;
        std::cout << "Doriti sa continuati? (0 = nu, orice alt numar = da): ";


        int continua1;
        std::cin >> continua1;
        if (continua1 == 0) {
            continua = false;
        }


    }
}
