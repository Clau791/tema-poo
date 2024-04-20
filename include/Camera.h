#include <iostream>

class Camera {
private:
    int numar;
    std::string tip;
    int pretPeNoapte;
    bool esteOcupata;
public:
    [[maybe_unused]] [[nodiscard]] int getPret() const {
        return pretPeNoapte; }

    [[maybe_unused]] [[nodiscard]] int getNumar() const {
        return numar; }

    [[nodiscard]] bool getEsteOcupata() const  {
        return esteOcupata  ; }

    //tema 2
    static double reducereGlobala; // Reducere globala aplicabila tuturor camerelor
    static int camereOcupate;


    //Constructor pentru Camera
    explicit Camera(int numar = 0, std::string tip = "Standard", int pretPeNoapte = 0 , bool esteOcupata = false)
            : numar(numar), tip(std::move(tip)), pretPeNoapte(pretPeNoapte), esteOcupata(esteOcupata) {

    }
    // tema 2
    static void actualizeazaReducere() {

         if (camereOcupate >= 2 && camereOcupate < 3) {

            reducereGlobala = 50.0;
        } else if( camereOcupate >= 3) {
            reducereGlobala = 100.0;
        }
        std::cout << "Reducerea actualizata este: " << reducereGlobala << " RON" << std::endl;

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


    //tema 2
    // folosim virtual pentru a putea ilustra upcasting-ul
    virtual void AfiseazaDetalii() {
        std::cout << "Camera " << numar << ": " << tip << ", " << pretPeNoapte << " RON, "
                  << (esteOcupata ? "Ocupata" : "Libera") << std::endl;
    }
    //destructor
    virtual ~Camera() = default;

};

double Camera::reducereGlobala = 0;
int Camera::camereOcupate = 0;
int SumaDePlata = 0;
