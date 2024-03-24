class NovelCase : public ::testing::Test  {
protected:
    Novel novel1 = {1, "Red Riding Hood", "Gerlin"};
    Novel novel2 = {2, "Red Riding Hood", "Gerlin"};
    Novel novel3 = {3, "Harry Potter", "J.K. Rowling"};
};

TEST_F(NovelCase, Constructor) {
    ASSERT_EQ(novel1.id(), 1);
    ASSERT_EQ(novel1.name(), "Red Riding Hood");
    ASSERT_EQ(novel1.author(), "Gerlin");
    ASSERT_EQ(novel1.introduction(), "A novel named Red Riding Hood");
}

// TEST_F(NovelCase, NovelEqualOverload) {
//     ASSERT_TRUE(novel1 == novel2);
//     ASSERT_FALSE(novel2 == novel3);
// }