//Aceasta clasa nu a fost folosita

#include <utility>
#include "Camera.h"

template <typename T>
class [[maybe_unused]] CameraVIP : public Camera<T> {
public:

    [[maybe_unused]] CameraVIP(int numar, T tip, int pretPeNoapte, bool esteOcupata)
            : Camera<T>(numar, tip, pretPeNoapte, esteOcupata) {}


    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Camera<U>& camera);

    template <typename U>
    friend std::istream& operator>>(std::istream& in, Camera<U>& camera);

};


