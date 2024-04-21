#ifndef OOP_CAMERAVIP_H
#define OOP_CAMERAVIP_H

class CameraVIP : public Camera {

public:
    CameraVIP(int nr, int pret, bool ocupata )
            : Camera(nr, "VIP", pret, ocupata)   { // NOLINT(*-narrowing-conversions)

    }
    //am apelat constructorul din clasa de baza

    void AfiseazaDetalii() override  {
        Camera::AfiseazaDetalii();
        std::cout << "Aceasta este camera VIP" << std::endl;
    }



};


#endif //OOP_CAMERAVIP_H
