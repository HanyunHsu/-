#include "../src/math_vector.h"
#include "../src/gaussian_elimination.h"

TEST(gaussian_elimination,gaussian_elimination_case1){
MathVector v1 = {{2, 1, -1, 8}};
MathVector v2 = {{-3, -1, 2, -11}};
MathVector v3 = {{-2, 1, 2, -3}};

std::vector<MathVector> matrix = {v1, v2, v3};

std::vector<MathVector> result = gaussian_elimination(matrix);
ASSERT_EQ(result[0].at(1) ,1 );
ASSERT_EQ(result[0].at(2) ,0 );
ASSERT_EQ(result[0].at(3) ,0 );
ASSERT_EQ(result[0].at(4) ,2 );
ASSERT_EQ(result[1].at(1) ,0 );
ASSERT_EQ(result[1].at(2) ,1 );
ASSERT_EQ(result[1].at(3) ,0 );
ASSERT_EQ(result[1].at(4) ,3 );
ASSERT_EQ(result[2].at(1) ,0 );
ASSERT_EQ(result[2].at(2) ,0 );
ASSERT_EQ(result[2].at(3) ,1 );
ASSERT_EQ(result[2].at(4) ,-1 );
}

TEST(gaussian_elimination,gaussian_elimination_case2){
MathVector v1 = {{2, 4, 6, 10}};
MathVector v2 = {{1, 2, 3, 5}};

std::vector<MathVector> matrix = {v1, v2};

std::vector<MathVector> result = gaussian_elimination(matrix);
ASSERT_EQ(result[0].at(1) ,1 );
ASSERT_EQ(result[0].at(2) ,2 );
ASSERT_EQ(result[0].at(3) ,3 );
ASSERT_EQ(result[0].at(4) ,5 );
ASSERT_EQ(result[1].at(1) ,0 );
ASSERT_EQ(result[1].at(2) ,0 );
ASSERT_EQ(result[1].at(3) ,0 );
ASSERT_EQ(result[1].at(4) ,0 );


}
TEST(gaussian_elimination,gaussian_elimination_case2_1){
MathVector v1 = {{0, 2, 4, 10}};
MathVector v2 = {{0, 1, 2, 5}};

std::vector<MathVector> matrix = {v1, v2};

std::vector<MathVector> result = gaussian_elimination(matrix);
ASSERT_EQ(result[0].at(1) ,0 );
ASSERT_EQ(result[0].at(2) ,1 );
ASSERT_EQ(result[0].at(3) ,2 );
ASSERT_EQ(result[0].at(4) ,5);
ASSERT_EQ(result[1].at(1) ,0 );
ASSERT_EQ(result[1].at(2) ,0 );
ASSERT_EQ(result[1].at(3) ,0 );
ASSERT_EQ(result[1].at(4) ,0 );


}
TEST(gaussian_elimination,gaussian_elimination_case2_2){
MathVector v1 = {{2, 2, 2, 2}};
MathVector v2 = {{0, 0, 0, 0}};

std::vector<MathVector> matrix = {v1, v2};

std::vector<MathVector> result = gaussian_elimination(matrix);
ASSERT_EQ(result[0].at(1) ,1 );
ASSERT_EQ(result[0].at(2) ,1 );
ASSERT_EQ(result[0].at(3) ,1 );
ASSERT_EQ(result[0].at(4) ,1 );
ASSERT_EQ(result[1].at(1) ,0 );
ASSERT_EQ(result[1].at(2) ,0 );
ASSERT_EQ(result[1].at(3) ,0 );
ASSERT_EQ(result[1].at(4) ,0 );


}
TEST(gaussian_elimination,gaussian_elimination_case2_3){
MathVector v1 = {{2, 6, 8, 10}};
MathVector v2 = {{0, 0, 0, 0}};

std::vector<MathVector> matrix = {v1, v2};

std::vector<MathVector> result = gaussian_elimination(matrix);
ASSERT_EQ(result[0].at(1) ,1 );
ASSERT_EQ(result[0].at(2) ,3 );
ASSERT_EQ(result[0].at(3) ,4 );
ASSERT_EQ(result[0].at(4) ,5 );
ASSERT_EQ(result[1].at(1) ,0 );
ASSERT_EQ(result[1].at(2) ,0 );
ASSERT_EQ(result[1].at(3) ,0 );
ASSERT_EQ(result[1].at(4) ,0 );


}




TEST(gaussian_elimination,gaussian_elimination_case2_7){
MathVector v1 = {{1, 0, 1, 0}};
MathVector v2 = {{1,0, 1, 1}};

std::vector<MathVector> matrix = {v1, v2};

std::vector<MathVector> result = gaussian_elimination(matrix);
ASSERT_EQ(result[0].at(1) ,1 );
ASSERT_EQ(result[0].at(2) ,0 );
ASSERT_EQ(result[0].at(3) ,1 );
ASSERT_EQ(result[0].at(4) ,0 );
ASSERT_EQ(result[1].at(1) ,0 );
ASSERT_EQ(result[1].at(2) ,0 );
ASSERT_EQ(result[1].at(3) ,0 );
ASSERT_EQ(result[1].at(4) ,1 );


}

TEST(gaussian_elimination,gaussian_elimination_case2_4){
MathVector v1 = {{1, 0, 0, 1}};
MathVector v2 = {{1, 0, 0, 2}};

std::vector<MathVector> matrix = {v1, v2};

std::vector<MathVector> result = gaussian_elimination(matrix);
ASSERT_EQ(result[0].at(1) ,1 );
ASSERT_EQ(result[0].at(2) ,0 );
ASSERT_EQ(result[0].at(3) ,0 );
ASSERT_EQ(result[0].at(4) ,1 );
ASSERT_EQ(result[1].at(1) ,0 );
ASSERT_EQ(result[1].at(2) ,0 );
ASSERT_EQ(result[1].at(3) ,0 );
ASSERT_EQ(result[1].at(4) ,1 );


}

TEST(gaussian_elimination,gaussian_elimination_case3){
MathVector v1 = {{1, 2, 3, 4}};
MathVector v2 = {{4, 5, 6, 7}};
MathVector v3 = {{7, 8, 9, 10}};

std::vector<MathVector> matrix = {v1, v2, v3};

std::vector<MathVector> result = gaussian_elimination(matrix);
ASSERT_EQ(result[0].at(1) ,1 );
ASSERT_EQ(result[0].at(2) ,0 );
ASSERT_EQ(result[0].at(3) ,-1 );
ASSERT_EQ(result[0].at(4) ,-2 );
ASSERT_EQ(result[1].at(1) ,0 );
ASSERT_EQ(result[1].at(2) ,1 );
ASSERT_EQ(result[1].at(3) ,2 );
ASSERT_EQ(result[1].at(4) ,3 );
ASSERT_EQ(result[2].at(1) ,0 );
ASSERT_EQ(result[2].at(2) ,0 );
ASSERT_EQ(result[2].at(3) ,0 );
ASSERT_EQ(result[2].at(4) ,0 );
}

TEST(gaussian_elimination,gaussian_elimination_case3_1){
MathVector v1 = {{1, 2, 3, 0}};
MathVector v2 = {{2, 5, 8, 3}};
MathVector v3 = {{1, -1, 3, 0}};

std::vector<MathVector> matrix = {v1, v2, v3};

std::vector<MathVector> result = gaussian_elimination(matrix);
ASSERT_EQ(result[0].at(1) ,1 );
ASSERT_EQ(result[0].at(2) ,2 );
ASSERT_EQ(result[0].at(3) ,3 );
ASSERT_EQ(result[0].at(4) ,0 );
ASSERT_EQ(result[1].at(1) ,0 );
ASSERT_EQ(result[1].at(2) ,1 );
ASSERT_EQ(result[1].at(3) ,2 );
ASSERT_EQ(result[1].at(4) ,3 );
ASSERT_EQ(result[2].at(1) ,0 );
ASSERT_EQ(result[2].at(2) ,0 );
ASSERT_EQ(result[2].at(3) ,0 );
ASSERT_EQ(result[2].at(4) ,9 );
}