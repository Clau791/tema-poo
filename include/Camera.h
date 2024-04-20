#include <iostream>
#include <string>

class Camera {
private:
    int numar;
    std::string tip;
    int pretPeNoapte;
    bool esteOcupata;

public:
    [[nodiscard]] int getPret() const;
    [[nodiscard]] int getNumar() const;
    [[nodiscard]] bool getEsteOcupata() const;

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
