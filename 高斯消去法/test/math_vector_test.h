#include "../src/math_vector.h"

TEST(math_vector_case,math_vector_case1){
    MathVector v1 = {{1,2,3}};
    MathVector v2 = {{4,5,6}};
    MathVector v3 = {{7,8,9}};
    std::vector<MathVector> result = {v1,v2,v3};
    ASSERT_EQ(result[0].at(1),1);
    ASSERT_EQ(result[0].at(2),2);
    ASSERT_EQ(result[0].at(3),3);
    ASSERT_EQ(result[1].at(1),4);
    ASSERT_EQ(result[1].at(2),5);
    ASSERT_EQ(result[1].at(3),6);
    ASSERT_EQ(result[2].at(1),7);
    ASSERT_EQ(result[2].at(2),8);
    ASSERT_EQ(result[2].at(3),9);
}

TEST(add_vector,add_vector_case1){
    MathVector v1 = {{1,2,3}};
    MathVector v2 = {{4,5,6}};

    MathVector result = v1.add(v2);
    ASSERT_EQ(result.at(1),5);
    ASSERT_EQ(result.at(2),7);
    ASSERT_EQ(result.at(3),9);
}

TEST(multiply_vector,multiply_vector_case1){
    MathVector v1 = {{1,2,3}};
    double a = 2;
    MathVector result = v1.multiply(a);
    ASSERT_EQ(result.at(1),2);
    ASSERT_EQ(result.at(2),4);
    ASSERT_EQ(result.at(3),6);
}