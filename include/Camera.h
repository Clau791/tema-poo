

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

    // [[maybe_unused]] [[nodiscard]] std::string getTip() const {
    //     return tip; }

    // [[maybe_unused]] [[nodiscard]] double getPretPeNoapte() const {
    //     return pretPeNoapte; }

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
    //tema 2
    virtual void AfiseazaDetalii() const {
        std::cout << "Camera " << numar << ": " << tip << ", " << pretPeNoapte << " RON, "
                  << (esteOcupata ? "Ocupata" : "Libera") << std::endl;
    }
    //destructor
    virtual ~Camera() = default;

};

