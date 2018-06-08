#include "gtest/gtest.h"
#include "Vector2.h"

TEST(Vector2, Add) {
  Vector2<float> zero;
  Vector2<float> v(-2,5);
  Vector2<float> w(1,-2);

  EXPECT_EQ (zero, zero+zero);
  EXPECT_EQ (v, v+zero);
  EXPECT_EQ (w+v, v+w);
  EXPECT_EQ (Vector2<float>(-1,3), v+w);
}

TEST(Vector2, Subtract) {
  Vector2<float> zero;
  Vector2<float> v(-2,5);
  Vector2<float> w(1,-2);

  EXPECT_EQ (zero, zero-zero);
  EXPECT_EQ (v, v-zero);
  EXPECT_EQ (Vector2<float>(-3,7), v-w);
}

TEST(Vector2, UnaryMinus) {
  Vector2<float> zero;
  Vector2<float> v(-2,5);

  EXPECT_EQ (zero, -zero);
  EXPECT_EQ (Vector2<float>(2, -5), -v);
}

TEST(Vector2, Multiply) {
  Vector2<float> zero;
  Vector2<float> v(-2,5);

  EXPECT_EQ (zero, zero*2);
  EXPECT_EQ (zero, 2*zero);
  EXPECT_EQ (zero, v*0);
  EXPECT_EQ (zero, 0*v);
  EXPECT_EQ (2*v, v*2);
  EXPECT_EQ (Vector2<float>(-4,10), v*2);
}

TEST(Vector2, Divison) {
  Vector2<float> zero;
  Vector2<float> v(-2,5);

  EXPECT_EQ (zero, zero/2);
  EXPECT_EQ (Vector2<float>(-1,2.5), v/2);
}

TEST(Vector2, Equality) {
  Vector2<float> zero;
  Vector2<float> v(-2,5);

  EXPECT_TRUE (zero==zero);
  EXPECT_FALSE (zero!=zero);
  EXPECT_TRUE(zero!=v);
  EXPECT_FALSE(zero==v);
  EXPECT_TRUE(v==v);
  EXPECT_FALSE(v!=v);
}

TEST(Vector2, Dot){
  Vector2<float> zero;
  Vector2<float> v(-2,5);
  Vector2<float> w(1,-2);

  EXPECT_EQ(0, zero.dot(v));
  EXPECT_EQ(0, v.dot(zero));
  EXPECT_EQ(w.dot(v), v.dot(w));
  EXPECT_EQ(-12, v.dot(w));
}

TEST(Vector2, PerpDot){
  Vector2<float> zero;
  Vector2<float> v(-2,5);
  Vector2<float> w(1,-2);

  EXPECT_EQ(0, zero.perpDot(v));
  EXPECT_EQ(0, v.perpDot(zero));
  EXPECT_NE(w.perpDot(v), v.perpDot(w));
  EXPECT_EQ(-1, v.perpDot(w));
}

TEST(Vector2, Magnitude){
  Vector2<float> zero;
  Vector2<float> v(-4,3);

  EXPECT_EQ(0, zero.magnitude());
  EXPECT_EQ(5, v.magnitude());
}

TEST(Vector2, MagnitudeSquared){
  Vector2<float> zero;
  Vector2<float> v(-4,3);

  EXPECT_EQ(0, zero.magnitudeSquared());
  EXPECT_EQ(25, v.magnitudeSquared());
}

TEST(Vector2, Normalized){
  Vector2<float> zero;
  Vector2<float> v(-4,3);

  EXPECT_EQ(zero, zero.normalized());
  EXPECT_EQ(v/v.magnitude(), v.normalized());
}


TEST(Vector2, Angle){
  Vector2<float> v(1,0);
  Vector2<float> w(1,1);

  EXPECT_FLOAT_EQ(45.0/180.0*M_PI, v.angle(w));
}

TEST(Vector2, IsBasis){
  const Vector2<float> v(1,0);
  const Vector2<float> w(1,1);

  EXPECT_TRUE(Vector2<float>::isBasis(v, w));
  EXPECT_FALSE(Vector2<float>::isBasis(v, -v));
}

TEST(Vector2, Distance){
  Vector2<float> zero;
  Vector2<float> p(-3,4);

  EXPECT_EQ(0, p.distance(p));
  EXPECT_EQ(5, zero.distance(p));
  EXPECT_EQ(p.distance(zero), zero.distance(p));
}

TEST(Vector2, DistanceSquared){
  Vector2<float> zero;
  Vector2<float> p(-3,4);

  EXPECT_EQ(0, p.distanceSquared(p));
  EXPECT_EQ(25, zero.distanceSquared(p));
  EXPECT_EQ(p.distanceSquared(zero), zero.distanceSquared(p));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}