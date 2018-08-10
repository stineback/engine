#include "gtest/gtest.h"
#include "Point2.h"
#include "Vector2.h"

TEST(Point2, Assignment) {
  Point2<float> p;
  Point2<float> q(-2,5);

  EXPECT_TRUE(p!=q);

  p = q;

  EXPECT_TRUE(p==q);
}

TEST(Point2, Equality) {
  Point2<float> zero;
  Point2<float> p(-2,5);
  Vector2<float> v(p.getX(), p.getY());

  EXPECT_TRUE(zero==zero);
  EXPECT_FALSE(zero!=zero);
  EXPECT_TRUE(zero!=p);
  EXPECT_FALSE(zero==p);
  EXPECT_TRUE(p==p);
  EXPECT_FALSE(p!=p);
  EXPECT_FALSE(p==v);
  EXPECT_TRUE(p!=v);
}

TEST(Point2, Add) {
  Point2<float> zeroPoint;
  Vector2<float> zeroVector;
  Point2<float> p(-2,5);
  Vector2<float> v(1,-2);

  EXPECT_EQ (zeroPoint, zeroPoint+zeroVector);
  EXPECT_EQ (p, p+zeroVector);
  EXPECT_EQ (Point2<float>(v.getX(), v.getY()), zeroPoint+v);
  EXPECT_EQ (Point2<float>(-1,3), p+v);
}

TEST(Point2, Subtract) {
  Point2<float> zero;
  Point2<float> p(-2,5);
  Point2<float> q(1,-2);

  EXPECT_EQ(Vector2<float>(), zero-zero);
  EXPECT_EQ(Vector2<float>(p.getX(), p.getY()), p-zero);
  EXPECT_EQ(Vector2<float>(-3,7), p-q);
}

TEST(Point2, Distance){
  Point2<float> zero;
  Point2<float> p(-3,4);

  EXPECT_EQ(0, p.distance(p));
  EXPECT_EQ(5, zero.distance(p));
  EXPECT_EQ(p.distance(zero), zero.distance(p));
}

TEST(Point2, DistanceSquared){
  Point2<float> zero;
  Point2<float> p(-3,4);

  EXPECT_EQ(0, p.distanceSquared(p));
  EXPECT_EQ(25, zero.distanceSquared(p));
  EXPECT_EQ(p.distanceSquared(zero), zero.distanceSquared(p));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}