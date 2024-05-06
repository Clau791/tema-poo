#include <iostream>
#include <string>
template <typename T>
class Camera {
private:
    int numar;
    T tip;
    int pretPeNoapte;
    bool esteOcupata;

public:
    [[maybe_unused]] [[nodiscard]] T getTip() const{
        return  tip;
    }
    [[maybe_unused]] [[nodiscard]] int getPret() const {
        return pretPeNoapte; }

    [[maybe_unused]] [[nodiscard]] int getNumar() const {
        return numar; }

    [[nodiscard]] bool getEsteOcupata() const  {
        return esteOcupata  ; }

    void SetterOcupata();

    // tema 2 , adaugam o reducere in cazul rezervarii mai multor camere
    // variabile de tip static
    static int reducere;
    [[maybe_unused]] static int camereOcupate;

    explicit Camera(int numar = 0, T tip = "Standard", int pretPeNoapte = 0, bool esteOcupata = false);


    //tema 2 , functii static si virtual pentru calcularea reducerii si pentru afisarea detaliilor
    [[maybe_unused]] static void actualizeazaReducere();
    // tema 2 , folosim upcasting
    [[maybe_unused]] virtual void AfiseazaDetalii();

    //Am incercat sa fac aceasta clasa una pur virtuala
    //dar am intampinat problema la instantierea obiectelor si adaugarea lor in vector ulterior

    //destructor virtual
    virtual ~Camera();

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Camera<U>& camera);

    template <typename U>
    friend std::istream& operator>>(std::istream& in, Camera<U>& camera);
};


template<typename T>
int Camera<T>::reducere = 0;
template<typename T>
[[maybe_unused]] int Camera<T>::camereOcupate = 0;
int SumaDePlata = 0;

template<typename T>
Camera<T>::Camera(int numar, T tip, int pretPeNoapte, bool esteOcupata)
        : numar(numar), tip(std::move(tip)), pretPeNoapte(pretPeNoapte), esteOcupata(esteOcupata) {
}

template<typename T>
[[maybe_unused]] void Camera<T>::actualizeazaReducere() {
    if (camereOcupate >= 2 && camereOcupate < 3) {
        reducere = 50;
    } else if (camereOcupate >= 3) {
        reducere = 100;
    }
    std::cout << "Reducerea actualizata este: " << reducere << " RON" << std::endl;
}

template<typename T>
void Camera<T>::SetterOcupata() {
    esteOcupata = !esteOcupata;
}

template<typename T>
[[maybe_unused]] void Camera<T>::AfiseazaDetalii() {
    std::cout << "Camera " << numar << ": " << tip << ", " << pretPeNoapte << " RON, "
              << (esteOcupata ? "Ocupata" : "Libera") << std::endl;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Camera<T>& camera) {
    out << "Nr: " << camera.numar << ", Tip: " << camera.tip
        << ", Pret: " << camera.pretPeNoapte << ", "
        << (camera.esteOcupata ? "Ocupata" : "Libera");
    return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, Camera<T>& camera) {
    in >> camera.numar >> camera.tip >> camera.pretPeNoapte >> camera.esteOcupata;
    return in;
}

template<typename T>
Camera<T>::~Camera() = default;

// Specificați explicit tipurile folosite pentru template-uri la sfârșitul fișierului
template class Camera<std::string>;

extern int SumaDePlata;
