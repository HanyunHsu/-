#include <gtest/gtest.h>
#include "./eraser_test.h"
#include "./pencil_test.h"
#include "./stationery_sort_test.h"

int main(int argc, char * argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
