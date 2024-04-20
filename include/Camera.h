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

    static int reducereGlobala;
    static int camereOcupate;

    explicit Camera(int numar = 0, std::string tip = "Standard", int pretPeNoapte = 0, bool esteOcupata = false);
    Camera(const Camera& sursa);

    static void actualizeazaReducere();
    void SetterOcupata();
    virtual void AfiseazaDetalii();
    virtual ~Camera();

    friend std::ostream& operator<<(std::ostream& out, const Camera& camera);
    friend std::istream& operator>>(std::istream& in, Camera& camera);
};

extern int SumaDePlata;
