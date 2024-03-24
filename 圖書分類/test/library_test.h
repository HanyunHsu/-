#include "../src/library.h"
class LibraryCase : public ::testing::Test {
protected:
    Novel novel1 = {1, "Name1", "Author1"};
    Novel novel2 = {2, "Name2", "Author2"};
    Novel novel3 = {3, "Name3", "Author3"};
    Novel novel4 = {4, "Name4", "Author4"};
    Novel novel5 = {5, "Name5", "Author5"};
    Novel novel6 = {6, "Name6", "Author6"};
    Novel novel7 = {7, "Name7", "Author7"};
    Novel novel8 = {2, "Name7", "Author7"};
    Library library;
    Library library2;
    void SetUp() override {
        library = {{&novel1, &novel2, &novel3, &novel4, &novel5}};
        library2 = {{&novel1, &novel3, &novel4, &novel5}};
    }
};

TEST_F(LibraryCase, LibraryConstructor) {
    
    ASSERT_EQ((*library.publications().at(0)).id(), 1);
    ASSERT_EQ((*library.publications().at(1)).id(), 2);
    ASSERT_EQ((*library.publications().at(2)).id(), 3);
    ASSERT_EQ((*library.publications().at(3)).id(), 4);
    ASSERT_EQ((*library.publications().at(4)).id(), 5);
}

TEST_F(LibraryCase, AddPublication) {
    library.addPublication(&novel6);
    library.addPublication(&novel7);
    ASSERT_EQ(library.publications().size(), 7);
    ASSERT_EQ(*library.publications().at(5), novel6);
    ASSERT_EQ(*library.publications().at(6), novel7);
}

TEST_F(LibraryCase, AddSamePublicationThrowException) {
    ASSERT_THROW(library.addPublication(&novel1), std::string);
}

TEST_F(LibraryCase, AddSamePublicationIdThrowException) {
    ASSERT_THROW(library.addPublication(&novel8), std::string);
}

TEST_F(LibraryCase, HasPublication) {
    ASSERT_TRUE(library2.hasPublication(novel1));
    ASSERT_FALSE(library2.hasPublication(novel2));
}

TEST_F(LibraryCase, RemovePublication) {
    library.removePublication(&novel1);

    ASSERT_EQ(library.publications().size(), 4);
    ASSERT_EQ((*library.publications().at(0)), novel2);
    ASSERT_EQ((*library.publications().at(1)), novel3);
    ASSERT_EQ((*library.publications().at(2)), novel4);
    ASSERT_EQ((*library.publications().at(3)), novel5);
}

TEST_F(LibraryCase, RemoveNotExistPublicationThrowException) {
    ASSERT_THROW(library2.removePublication(&novel2), std::string);
}
