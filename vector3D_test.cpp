#include <gtest/gtest.h>

#include "./vector3D.cpp"



TEST(Vector3D, AddingWithEqalTo )
{
   Vector3d<int> vectorA( 1, 2, 3 );
   Vector3d<int> vectorB( 100, 200, 300 );
   vectorB += vectorA;
   
   EXPECT_EQ(vectorB.getX(), 101);
   EXPECT_EQ(vectorB.getY(), 202);
   EXPECT_EQ(vectorB.getZ(), 303);
}

TEST(Vector3D, Adding )
{
   Vector3d<int> vectorA( 1, 2, 3 );
   Vector3d<int> vectorB( 100, 200, 300 );
   Vector3d<int> sum( 0, 0, 0 );
   sum = vectorB + vectorA;
   
   EXPECT_EQ(sum.getX(), 101);
   EXPECT_EQ(sum.getY(), 202);
   EXPECT_EQ(sum.getZ(), 303);
}

TEST(Vector3D, SubtractionWithEqualTo )
{
   Vector3d<int> vectorA( 1, 2, 3 );
   Vector3d<int> vectorB( 101, 202, 303 );
   vectorB -= vectorA;
   
   EXPECT_EQ(vectorB.getX(), 100);
   EXPECT_EQ(vectorB.getY(), 200);
   EXPECT_EQ(vectorB.getZ(), 300);
}

TEST(Vector3D, SubtractionTwoVectors )
{
   Vector3d<int> vectorA( 1, 2, 3 );
   Vector3d<int> vectorB( 101, 202, 303 );
 
   Vector3d<int> sub( 0, 0, 0 );
   sub = vectorB - vectorA;
   
   EXPECT_EQ(sub.getX(), 100 );
   EXPECT_EQ(sub.getY(), 200 );
   EXPECT_EQ(sub.getZ(), 300 );
}

TEST(Vector3D, ScalarMultiplication )
{
   Vector3d<int> vectorB( 1, 2, 3 );
   Vector3d<int> result( 0, 0, 0 );
   
   result = vectorB * 2;
   
   EXPECT_EQ(result.getX(), 2);
   EXPECT_EQ(result.getY(), 4);
   EXPECT_EQ(result.getZ(), 6);
}

TEST(Vector3D, TwoVectorsMultiplication )
{
   Vector3d<int> vectorA( 3, 2, 1 );
   Vector3d<int> vectorB( 1, 2, 3 );
   Vector3d<int> product( 1, 1, 1 );
   product = vectorA * vectorB;
   
   EXPECT_EQ(product.getX(), 4 );
   EXPECT_EQ(product.getY(), -8 );
   EXPECT_EQ(product.getZ(), 4 );
   
}

TEST(Vector3D, ProperDividing )
{
   Vector3d<int> vectorA( 4, 4, 4 );
   Vector3d<int> quotient( 0, 0, 0 );
   quotient = vectorA / 2;
   
   EXPECT_EQ(quotient.getX(), 2 );
   EXPECT_EQ(quotient.getY(), 2 );
   EXPECT_EQ(quotient.getZ(), 2 );
   
}

TEST(Vector3D, DivisionByZero )
{
   Vector3d<int> vectorA( 4, 4, 4 );
   Vector3d<int> quotient( 0, 0, 0 );
  // auto quotient = [&] () {return vectorA / 0;};
   
   ASSERT_THROW( vectorA / 0, std::overflow_error );
  
}

