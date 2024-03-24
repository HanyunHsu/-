#include <gtest/gtest.h>
#include "./math_vector_test.h"
#include "./gaussian_elimination_test.h"

int main(int argc, char * argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
