#include <gtest/gtest.h>
#include <Camera.h>

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