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

TEST(Plane, isCoplanar)
{
  Point3<int> p0(1,1,0);
  Point3<int> p1(1,-1,0);
  Point3<int> p2(-1,-1,0);
  Point3<int> p3(-1,1,0);
  Point3<int> p4(0,0,1);

  EXPECT_TRUE(Plane<int>::isCoplanar(p0,p1,p2,p3));
  EXPECT_FALSE(Plane<int>::isCoplanar(p0,p1,p2,p4));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}