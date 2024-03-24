#include "../src/matrix.h"
#include "../src/math_vector.h"
#include <iostream>

TEST(create, create_1)
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};

    Matrix mu{{u1, u2}};

    MathVector row1 = mu.at_row(1);
    MathVector row2 = mu.at_row(2);

    ASSERT_EQ(row1.at(1),2);
    ASSERT_EQ(row1.at(2),1);
    ASSERT_EQ(row2.at(1),-3);
    ASSERT_EQ(row2.at(2),-1);
}

TEST(add, add_1)
{
    MathVector u1 = {{2, 1}};
    MathVector u2 = {{-3, -1}};
    MathVector v1 = {{1, 1}};
    MathVector v2 = {{0, -1}};

    Matrix mu{{u1, u2}};
    Matrix mv{{v1, v2}};

    Matrix result = mu + mv;

    ASSERT_EQ(result[0].at(1),3);
    ASSERT_EQ(result[0].at(2),2);
    ASSERT_EQ(result[1].at(1),-3);
    ASSERT_EQ(result[1].at(2),-2);
}
TEST(minus, minus_1)
{
    MathVector u1 = {{2, 1}};
MathVector u2 = {{-3, -1}};
MathVector v1 = {{1, 1}};
MathVector v2 = {{0, -1}};

Matrix mu {{u1, u2}};
Matrix mv {{v1, v2}};

Matrix result = mu - mv;

    ASSERT_EQ(result[0].at(1),1);
    ASSERT_EQ(result[0].at(2),0);
    ASSERT_EQ(result[1].at(1),-3);
    ASSERT_EQ(result[1].at(2),0);
}

TEST(multiply,multiply_1)
{
    MathVector u1 = {{2, 1}};
MathVector u2 = {{-3, -1}};

Matrix mu {{u1, u2}};

Matrix result = 2 * mu;
ASSERT_EQ(result[0].at(1),4);
ASSERT_EQ(result[0].at(2),2);
ASSERT_EQ(result[1].at(1),-6);
ASSERT_EQ(result[1].at(2),-2);

}

TEST(multiply,multiply_1_MathVector)
{
    MathVector u1 = {{2, 1}};
MathVector u2 = {{-3, -1}};

Matrix mu {{u1, u2}};

Matrix result = mu * 2;
ASSERT_EQ(result[0].at(1),4);
ASSERT_EQ(result[0].at(2),2);
ASSERT_EQ(result[1].at(1),-6);
ASSERT_EQ(result[1].at(2),-2);

}
TEST(multiply,multiply_1_MathVector_MathVector)
{
    MathVector u1 = {{2, 1}};
MathVector u2 = {{-3, -1}};

double result = u1 * u2;


ASSERT_EQ(result,-7);


}
TEST(multiply,multiply_2)
{
    MathVector u1 = {{2, 1}};
MathVector u2 = {{-3, -1}};

Matrix mu {{u1, u2}};

Matrix result = mu * 2;
ASSERT_EQ(result[0].at(1),4);
ASSERT_EQ(result[0].at(2),2);
ASSERT_EQ(result[1].at(1),-6);
ASSERT_EQ(result[1].at(2),-2);

}
TEST(at_column,at_column_1)
{
    MathVector v1 = {{1, 2, 3}};
MathVector v2 = {{0, -6, 7}};

Matrix mv = {{v1, v2}};
    MathVector u = mv.at_column(1);
    ASSERT_EQ(u.at(1),1);
    ASSERT_EQ(u.at(2),0);
}

TEST(transpose, transpose_1){
    MathVector v1 = {{1, 2, 3}};
MathVector v2 = {{0, -6, 7}};

Matrix mv = {{v1, v2}};

Matrix transpose = mv.transpose();


ASSERT_EQ(transpose[0].at(1),1);
ASSERT_EQ(transpose[0].at(2),0);
ASSERT_EQ(transpose[1].at(1),2);
ASSERT_EQ(transpose[1].at(2),-6);
ASSERT_EQ(transpose[2].at(1),3);
ASSERT_EQ(transpose[2].at(2),7);
}

TEST(multiply,multiply_3)
{
    MathVector u1 = {{2, 3, 4}};
MathVector u2 = {{1, 0, 0}};
MathVector v1 = {{0, 1000}};
MathVector v2 = {{1, 100}};
MathVector v3 = {{0, 10}};

Matrix mu = {{u1, u2}};
Matrix mv = {{v1, v2, v3}};

Matrix result = mu * mv;
ASSERT_EQ(result[0].at(1),3);

ASSERT_EQ(result[0].at(2),2340);

ASSERT_EQ(result[1].at(1),0);

ASSERT_EQ(result[1].at(2),1000);

}

TEST(multiply,multiply_mistake)
{
    MathVector u1 = {{2, 3, 4}};
MathVector u2 = {{1, 0, 0}};
MathVector v1 = {{0, 1000}};
MathVector v2 = {{1, 100}};
MathVector v3 = {{0, 10}};

Matrix mu = {{u1, u2}};
Matrix mv = {{v1, v2, v3}};

Matrix result = mu * mv;

ASSERT_EQ(result[0].at(1),3);
ASSERT_EQ(result[0].at(2),2340);
ASSERT_EQ(result[1].at(1),0);
ASSERT_EQ(result[1].at(2),1000);

ASSERT_THROW(result.product(mv),std::string);
}


TEST(transform,transform_1)
{
    MathVector u1 = {{1, 3}};
MathVector u2 = {{-2, 0}};
MathVector v = {{-1, 2}};

Matrix mu = {{u1, u2}};

MathVector result = mu.transform(v);
ASSERT_EQ(result.at(1),5);
ASSERT_EQ(result.at(2),2);

}
