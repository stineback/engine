#include "gtest/gtest.h"
#include "Vector2.h"

TEST(Vector2Test, Add) { 
    Vector2<float> v(-2,5);
    Vector2<float> w(1,-2);

    EXPECT_EQ (Vector2<float>(-1,3), v+w);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}