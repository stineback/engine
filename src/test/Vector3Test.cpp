#include "gtest/gtest.h"
#include "Vector3.h"
#include "Point3.h"

TEST(Vector3, Assignment) {
  Vector3<float> v;
  Vector3<float> w(-2,5,10);

  EXPECT_TRUE(v!=w);

  v = w;

  EXPECT_TRUE(v==w);
}


TEST(Vector3, Equality) {
  Vector3<float> zero;
  Vector3<float> v(-2,5,10);
  Point3<float> p(-2,5,10);

  EXPECT_TRUE(zero==zero);
  EXPECT_FALSE(zero!=zero);
  EXPECT_TRUE(zero!=v);
  EXPECT_FALSE(zero==v);
  EXPECT_TRUE(v==v);
  EXPECT_FALSE(v!=v);
  EXPECT_FALSE(v==p);
  EXPECT_TRUE(v!=p);
}

TEST(Vector3, Add) {
  Vector3<float> zero;
  Vector3<float> v(-2,5,10);
  Vector3<float> w(1,-2,4);

  EXPECT_EQ(zero, zero+zero);
  EXPECT_EQ(v, v+zero);
  EXPECT_EQ(w+v, v+w);
  EXPECT_EQ(Vector3<float>(-1,3,14), v+w);
}

TEST(Vector3, Subtract) {
  Vector3<float> zero;
  Vector3<float> v(-2,5,10);
  Vector3<float> w(1,-2,4);

  EXPECT_EQ(zero, zero-zero);
  EXPECT_EQ(v, v-zero);
  EXPECT_EQ(Vector3<float>(-3,7,6), v-w);
}

TEST(Vector3, UnaryMinus) {
  Vector3<float> zero;
  Vector3<float> v(-2,5,10);

  EXPECT_EQ (zero, -zero);
  EXPECT_EQ (Vector3<float>(2, -5, -10), -v);
}

TEST(Vector3, Multiply) {
  Vector3<float> zero;
  Vector3<float> v(-2,5,10);

  EXPECT_EQ(zero, zero*2);
  EXPECT_EQ(zero, 2*zero);
  EXPECT_EQ(zero, v*0);
  EXPECT_EQ(zero, 0*v);
  EXPECT_EQ(2*v, v*2);
  EXPECT_EQ(Vector3<float>(-4,10,20), v*2);
}

TEST(Vector3, Divison) {
  Vector3<float> zero;
  Vector3<float> v(-2,5,10);

  EXPECT_EQ(zero, zero/2);
  EXPECT_EQ(Vector3<float>(-1,2.5,5), v/2);
}

TEST(Vector3, Dot){
  Vector3<float> zero;
  Vector3<float> v(-2,5,10);
  Vector3<float> w(1,-2,4);

  EXPECT_EQ(0, zero.dot(v));
  EXPECT_EQ(0, v.dot(zero));
  EXPECT_EQ(w.dot(v), v.dot(w));
  EXPECT_EQ(28, v.dot(w));
}

TEST(Vector3, Cross){
  Vector3<float> zero;
  Vector3<float> v(-2,5,10);
  Vector3<float> w(1,-2,4);

  EXPECT_EQ(zero, zero.cross(v));
  EXPECT_EQ(zero, v.cross(zero));
  EXPECT_EQ(-w.cross(v), v.cross(w));
  EXPECT_EQ(Vector3<float>(40,18,-1), v.cross(w));
}

TEST(Vector3, Magnitude){
  Vector3<float> zero;
  Vector3<float> v(-4,3,-2);

  EXPECT_EQ(0, zero.magnitude());
  EXPECT_FLOAT_EQ(sqrt(29), v.magnitude());
}

TEST(Vector3, MagnitudeSquared){
  Vector3<float> zero;
  Vector3<float> v(-4,3,-2);

  EXPECT_EQ(0, zero.magnitudeSquared());
  EXPECT_EQ(29, v.magnitudeSquared());
}

TEST(Vector3, Normalized){
  Vector3<float> zero;
  Vector3<float> v(-4,3,-2);

  EXPECT_EQ(zero, zero.normalized());
  EXPECT_EQ(v/v.magnitude(), v.normalized());
}


TEST(Vector3, Angle){
  Vector3<float> v(1,0,0);
  Vector3<float> w(0,1,0);
  Vector3<float> u(-1,0,0);

  Vector3<float> normal = v.cross(w);
  EXPECT_EQ(0, v.angle(v, normal));
  EXPECT_EQ(v.angle(w, normal), -w.angle(v, normal));
  EXPECT_FLOAT_EQ(M_PI/2, v.angle(w, normal));
  EXPECT_FLOAT_EQ(M_PI, u.angle(v, normal));
}

TEST(Vector3, Projection){
  Vector3<float> zero;
  Vector3<float> v(-2,5,10);
  Vector3<float> w(1,-2,4);

  EXPECT_EQ(zero, zero.projection(v));
  EXPECT_EQ(w*28.0/21.0, v.projection(w));
}

TEST(Vector3, IsRightHanded){
  const Vector3<float> v(1,0,0);
  const Vector3<float> w(0,1,0);
  const Vector3<float> u(0,0,1);

  EXPECT_TRUE(Vector3<float>::isRightHanded(v, w, u));
  EXPECT_FALSE(Vector3<float>::isRightHanded(v, -w, u));
}

TEST(Vector3, IsBasis){
  const Vector3<float> v(1,0,0);
  const Vector3<float> w(1,1,1);
  const Vector3<float> u(1,0,1);

  EXPECT_TRUE(Vector3<float>::isBasis(v, w, u));
  EXPECT_FALSE(Vector3<float>::isBasis(v, -v, w));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}