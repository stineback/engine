#include "gtest/gtest.h"
#include "Point3.h"
#include "Vector3.h"

TEST(Point3, Assignment) {
  Point3<float> p;
  Point3<float> q(-2,5,10);

  EXPECT_TRUE(p!=q);

  p = q;

  EXPECT_TRUE(p==q);
}

TEST(Point3, Equality) {
  Point3<float> zero;
  Point3<float> p(-2,5,10);
  Vector3<float> v(p.getX(), p.getY(), p.getZ());

  EXPECT_TRUE(zero==zero);
  EXPECT_FALSE(zero!=zero);
  EXPECT_TRUE(zero!=p);
  EXPECT_FALSE(zero==p);
  EXPECT_TRUE(p==p);
  EXPECT_FALSE(p!=p);
  EXPECT_FALSE(p==v);
  EXPECT_TRUE(p!=v);
}

TEST(Point3, Add) {
  Point3<float> zeroPoint;
  Vector3<float> zeroVector;
  Point3<float> p(-2,5,10);
  Vector3<float> v(1,-2,4);

  EXPECT_EQ (zeroPoint, zeroPoint+zeroVector);
  EXPECT_EQ (p, p+zeroVector);
  EXPECT_EQ (Point3<float>(v.getX(), v.getY(), v.getZ()), zeroPoint+v);
  EXPECT_EQ (Point3<float>(-1,3,14), p+v);
}

TEST(Point3, Subtract) {
  Point3<float> zero;
  Point3<float> p(-2,5,10);
  Point3<float> q(1,-2,4);

  EXPECT_EQ(Vector3<float>(), zero-zero);
  EXPECT_EQ(Vector3<float>(p.getX(), p.getY(),p.getZ()), p-zero);
  EXPECT_EQ(Vector3<float>(-3,7,6), p-q);
}

TEST(Point3, Distance){
  Point3<float> zero;
  Point3<float> p(-3,4,-2);

  EXPECT_EQ(0, p.distance(p));
  EXPECT_FLOAT_EQ(sqrt(29), zero.distance(p));
  EXPECT_EQ(p.distance(zero), zero.distance(p));
}

TEST(Point3, DistanceSquared){
  Point3<float> zero;
  Point3<float> p(-3,4,-2);

  EXPECT_EQ(0, p.distanceSquared(p));
  EXPECT_EQ(29, zero.distanceSquared(p));
  EXPECT_EQ(p.distanceSquared(zero), zero.distanceSquared(p));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}