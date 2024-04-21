#include <gtest/gtest.h>
#include <Camera.h>
#include "CameraVIP.h"
#include "CameraECO.h"
#include <sstream>



TEST(SuiteName, TestName) {
    EXPECT_EQ(10, 10);
    // Other assertions: https://google.github.io/googletest/reference/assertions.html#boolean
}

// Test pentru constructorul CameraStandard
TEST(CameraTest, ConstructorTest) {
    Camera camera(1, "Dubla", 200, false);
    ASSERT_EQ(camera.getNumar(), 1);
    ASSERT_EQ(camera.getPret(), 200);
    ASSERT_FALSE(camera.getEsteOcupata());
}

// Test pentru setter-ul de stare ocupată
TEST(CameraTest, SetterOcupataTest) {
    Camera camera(1, "Dubla", 100, false);
    camera.SetterOcupata();
    ASSERT_TRUE(camera.getEsteOcupata());
}
// Test pentru a verifica constructorul clasei CameraVIP
TEST(CameraVIP, Constructor) {
    CameraVIP vip(101, 500.0, false);
    EXPECT_EQ(vip.getNumar(), 101);
    EXPECT_DOUBLE_EQ(vip.getPret(), 500.0);
    EXPECT_FALSE(vip.getEsteOcupata());
}

TEST(CameraECO, Constructor) {
    CameraEco eco(11, 200.0, false);
    EXPECT_EQ(eco.getNumar(), 11);
    EXPECT_DOUBLE_EQ(eco.getPret(), 200.0);
    EXPECT_FALSE(eco.getEsteOcupata());
}
//functie static
TEST(CameraTest, ActualizeazaReducere) {
    Camera::camereOcupate = 2;
    Camera::actualizeazaReducere();
    EXPECT_EQ(Camera::reducere, 50);

    Camera::camereOcupate = 3;
    Camera::actualizeazaReducere();
    EXPECT_EQ(Camera::reducere, 100);
}

//functie virtuala
TEST(CameraTest, AfiseazaDetalii) {
    // Salvam stream-ul vechi
    std::cout.rdbuf();
    // Redirecționam std::cout la un stringstream
    std::stringstream output;
    std::cout.rdbuf(output.rdbuf());

}
