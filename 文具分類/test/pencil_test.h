#include "../src/pencil.h"

class PencilTest : public testing::Test{
    protected:
        void SetUp() override{

        }
        void TearDown()override{

        }
};
TEST(PencilCase,pencil_name){
    Pencil p1("Hank",18, "H");
    Pencil p2("Hank",15, "2B");
    Pencil p3("Hank",12, "2H");

    ASSERT_EQ(p1.name(),"H Pencil");
    ASSERT_EQ(p2.name(),"2B Pencil");    
    ASSERT_EQ(p3.name(),"2H Pencil");        

}
TEST(PencilCase, pencil_error_length){

    ASSERT_ANY_THROW(Pencil p1("Hank",0, "H"));
}

TEST(PencilCase, pencil_error_hardness){
    ASSERT_ANY_THROW(Pencil p1("Hank",12, "E"));
}

TEST(PencilCase, pencil_price){
    Pencil p1("Hank",18, "H");
    Pencil p2("Hank",15, "2B");
    Pencil p3("Hank",12, "2H");

    ASSERT_NEAR(p1.price(),55.8,0.1);
    ASSERT_NEAR(p2.price(),30.0,0.1);
    ASSERT_NEAR(p3.price(),31.2,0.1);
}

TEST_F(PencilTest,pencil_have_id){
    Pencil p1("Hank",18, "H");
    Pencil p2("Hank",15, "2B");
    Pencil p3("Hank",12, "2H");

    EXPECT_EQ(p1.name(),"H Pencil");
    EXPECT_EQ(p2.name(),"2B Pencil");    
    EXPECT_EQ(p3.name(),"2H Pencil");        

}

TEST_F(PencilTest,pencil_non_have_id){
    Pencil p1(18, "H");
    Pencil p2("Hank",15, "2B");
    Pencil p3("Hank",12, "2H");

    EXPECT_EQ(p1.name(),"H Pencil");
    EXPECT_EQ(p2.name(),"2B Pencil");    
    EXPECT_EQ(p3.name(),"2H Pencil");        

}