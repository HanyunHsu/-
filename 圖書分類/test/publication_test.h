#include "../src/publication.h"
#include "../src/novel.h"
#include "../src/magazine.h"
class PublicationCase : public ::testing::Test {
protected:
    Magazine magazine = {1, "Times", "Sam Jacobs", "May 26, 2016"};
    Novel novel = {5, "Harry Potter", "J.K. Rowling"};
};

TEST_F(PublicationCase, NovelAndMagazineShouldNotEqual) {
    ASSERT_FALSE(novel == magazine);
}