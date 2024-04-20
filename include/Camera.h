#include <iostream>
#include <string>

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

    void SetterOcupata();


    // tema 2 , adaugam o reducere in cazul rezervarii mai multor camere
    // variabile de tip static
    static int reducere;
    static int camereOcupate;

    explicit Camera(int numar = 0, std::string tip = "Standard", int pretPeNoapte = 0, bool esteOcupata = false);
    Camera(const Camera& sursa);

    //tema 2 , functii static si virtual pentru calcularea reducerii si pentru afisarea detaliilor
    static void actualizeazaReducere();
    // tema 2 , folosim upcasting
    virtual void AfiseazaDetalii();


    //destructor virtual
    virtual ~Camera();

    friend std::ostream& operator<<(std::ostream& out, const Camera& camera);
    friend std::istream& operator>>(std::istream& in, Camera& camera);
};

extern int SumaDePlata;
