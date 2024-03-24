#include <gtest/gtest.h>
#include "publication_test.h"
#include "library_test.h"
#include "person_test.h"
#include "find_test.h"
#include "magazine_test.h"
#include "novel_test.h"

int main(int argc, char * argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
