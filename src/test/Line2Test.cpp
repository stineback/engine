#include "gtest/gtest.h"
#include "Line2.h"
#include "Point2.h"
#include "Vector2.h"

TEST(Line2, Assignment) {
  Line2<float> l(Vector2<float>(1,0),Point2<float>(0,0));
  Line2<float> m(Vector2<float>(0,1),Point2<float>(0,0));

  EXPECT_TRUE(l!=m);

  l = m;

  EXPECT_TRUE(l==m);
}

TEST(Line2, Equality) {
  Line2<float> l(Vector2<float>(1,0),Point2<float>(0,0));
  Line2<float> m(Vector2<float>(0,1),Point2<float>(0,0));

  EXPECT_TRUE(l==l);
  EXPECT_FALSE(l!=l);
  EXPECT_FALSE(l==m);
  EXPECT_TRUE(l!=m);
}

TEST(Line2, pointOnLine){
  Line2<float> l(Vector2<float>(1,0),Point2<float>(0,0));
  Point2<float> expected(2,0);

  Point2<float> result = l.pointOnLine(2);

  EXPECT_TRUE(expected == result);
}

TEST(Line2, positionAccordingToLine){
  Line2<float> l(Vector2<float>(1,0),Point2<float>(0,0));
  Point2<float> p1(1,0);
  Point2<float> p2(0,1);
  Point2<float> p3(0,-1);

  EXPECT_TRUE(l.positionAccordingToLine(p1) == 0);
  EXPECT_TRUE(l.positionAccordingToLine(p2) > 0);
  EXPECT_TRUE(l.positionAccordingToLine(p3) < 0);
}

TEST(Line2, distanceToLine){
  Line2<float> l(Vector2<float>(1,0),Point2<float>(0,0));
  Point2<float> p1(1,0);
  Point2<float> p2(0,1);
  Point2<float> p3(0,-1);

  EXPECT_TRUE(l.distanceToLine(p1) == 0);
  EXPECT_TRUE(l.distanceToLine(p2) == 1);
  EXPECT_TRUE(l.distanceToLine(p3) == 1);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}