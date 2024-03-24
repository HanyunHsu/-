class MagazineCase : public ::testing::Test  {
protected:
    Magazine magazine1 = {1, "Times", "Sam Jacobs", "May 26, 2016"};
    Magazine magazine2 = {2, "Times", "Sam Jacobs", "May 26, 2016"};
    Magazine magazine3 = {2, "Times", "Sam Jacobs", "May 26, 2016"};
};

// TEST_F(MagazineCase, MagazineEqualOverload) {
//     ASSERT_FALSE(magazine1 == magazine2);
//     ASSERT_TRUE(magazine2 == magazine3);
// }

TEST_F(MagazineCase, Constructor) {

    ASSERT_EQ(magazine1.id(), 1);
    ASSERT_EQ(magazine1.name(), "Times");
    ASSERT_EQ(magazine1.editor(), "Sam Jacobs");
    ASSERT_EQ(magazine2.introduction(), "A magazine named Times");

    ASSERT_EQ(magazine2.id(), 2);
    ASSERT_EQ(magazine2.name(), "Times");
    ASSERT_EQ(magazine2.editor(), "Sam Jacobs");
    ASSERT_EQ(magazine2.issue(), "May 26, 2016");
    ASSERT_EQ(magazine2.introduction(), "A magazine named Times");
}