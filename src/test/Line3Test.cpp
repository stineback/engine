#include "gtest/gtest.h"
#include "Line3.h"
#include "Point3.h"
#include "Vector3.h"

TEST(Line3, Assignment) {
  Line3<float> l(Vector3<float>(1,0,0),Point3<float>(0,0,0));
  Line3<float> m(Vector3<float>(0,1,0),Point3<float>(0,0,0));

  EXPECT_TRUE(l!=m);

  l = m;

  EXPECT_TRUE(l==m);
}

TEST(Line3, Equality) {
  Line3<float> l(Vector3<float>(1,0,0),Point3<float>(0,0,0));
  Line3<float> m(Vector3<float>(0,1,0),Point3<float>(0,0,0));

  EXPECT_TRUE(l==l);
  EXPECT_FALSE(l!=l);
  EXPECT_FALSE(l==m);
  EXPECT_TRUE(l!=m);
}

TEST(Line3, pointOnLine){
  Line3<float> l(Vector3<float>(1,0,0),Point3<float>(0,0,0));
  Point3<float> expected(2,0,0);

  Point3<float> result = l.pointOnLine(2);

  EXPECT_TRUE(expected == result);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}