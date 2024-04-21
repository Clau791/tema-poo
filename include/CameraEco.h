#ifndef OOP_CAMERAECO_H
#define OOP_CAMERAECO_H


// Clasa CameraEco extinde clasa Camera
class CameraEco : public Camera {

public:
    CameraEco(int numar, int pret, bool ocupata)
            : Camera(numar, "Eco", pret, ocupata) {

    }
    // Constructorul pentru CameraEco


    void AfiseazaDetalii() override{
        Camera::AfiseazaDetalii();  // Afișeaza detaliile ale camerei
        std::cout << "Aceasta camera este economica." << std::endl;

    };



};

#endif //OOP_CAMERAECO_H
