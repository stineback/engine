#include "gtest/gtest.h"
#include "Plane.h"
#include "Point3.h"
#include "Vector3.h"

TEST(Plane, Assignment) {
  Plane<float> p(Vector3<float>(1,0,0),Point3<float>(0,0,0));
  Plane<float> q(Vector3<float>(0,1,0),Point3<float>(0,0,0));

  EXPECT_TRUE(p!=q);

  p = q;

  EXPECT_TRUE(p==q);
}

TEST(Plane, Equality) {
  Plane<float> p(Vector3<float>(1,0,0),Point3<float>(0,0,0));
  Plane<float> q(Vector3<float>(0,1,0),Point3<float>(0,0,0));

  EXPECT_TRUE(p==p);
  EXPECT_FALSE(q!=q);
  EXPECT_FALSE(p==q);
  EXPECT_TRUE(p!=q);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}