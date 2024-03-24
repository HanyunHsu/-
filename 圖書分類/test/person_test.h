#include "../src/person.h"
class PersonCase : public ::testing::Test {
protected:
    Person p1 = {1, "Name1"};
    Person p2 = {1, "Name1"};
    Person p3 = {2, "Name2"};
    
    Novel novel1 = {1, "Name1", "Author1"};
    Novel novel2 = {2, "Name2", "Author2"};
    Novel novel3 = {3, "Name3", "Author3"};
    Novel novel4 = {2, "Name4", "Author4"};
};

TEST_F(PersonCase, PersonConstructor) {
    ASSERT_EQ(p1.id(), 1);
    ASSERT_EQ(p1.name(), "Name1");
    ASSERT_TRUE(p1.publicationsBorrowed().empty());
}

TEST_F(PersonCase, EqualOperator) {
    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 == p3);
}

TEST_F(PersonCase, borrowPublication) {
    p1.borrowPublication(&novel1);
    p1.borrowPublication(&novel2);
    ASSERT_EQ(p1.publicationsBorrowed().size(), 2);
    ASSERT_EQ(*p1.publicationsBorrowed().at(0), novel1);
    ASSERT_EQ(*p1.publicationsBorrowed().at(1), novel2);
}

TEST_F(PersonCase, borrowPublicationOverLimitThrowException) {
    p1.borrowPublication(&novel1);
    p1.borrowPublication(&novel2);

    ASSERT_THROW(p1.borrowPublication(&novel3), std::string);
}

TEST_F(PersonCase, AddSamePublicationThrowException) {
    p1.borrowPublication(&novel1);

    ASSERT_THROW(p1.borrowPublication(&novel1), std::string);
}

TEST_F(PersonCase, AddSamePublicationIdThrowException) {
    p1.borrowPublication(&novel2);

    ASSERT_THROW(p1.borrowPublication(&novel4), std::string);
}

TEST_F(PersonCase, HasPublication) {
    p1.borrowPublication(&novel1);
    ASSERT_TRUE(p1.isBorrowed(novel1));
    ASSERT_FALSE(p1.isBorrowed(novel2));
}

TEST_F(PersonCase, returnPublication) {
    p1.borrowPublication(&novel1);
    p1.borrowPublication(&novel2);

    p1.returnPublication(&novel1);

    ASSERT_EQ(p1.publicationsBorrowed().size(), 1);
    ASSERT_EQ(*p1.publicationsBorrowed().at(0), novel2);
}

TEST_F(PersonCase, RemoveNotExistPublicationThrowException) {
    p1.borrowPublication(&novel1);

    ASSERT_THROW(p1.returnPublication(&novel2), std::string);
}