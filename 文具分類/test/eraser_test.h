#include "../src/eraser.h"
#include <gtest/gtest.h>

class EraserTest : public testing::Test{
    protected:
        void SetUp() override{

        }
        void TearDown()override{

        }
};

TEST(EraserCase,Eraser_name){
    Eraser e1("Hank","Small","MUJI");
    Eraser e2("Hank","Medium","Staedtler");
    Eraser e3("Hank","Large","Pentel");

    ASSERT_EQ(e1.name(),"Small MUJI Eraser");
    ASSERT_EQ(e2.name(),"Medium Staedtler Eraser");
    ASSERT_EQ(e3.name(),"Large Pentel Eraser");
}

TEST(EraserCase,Eraser_error_size){
    
    ASSERT_THROW(Eraser e1("Hank","BBBBig","MUJI"),std::string);
}

TEST(EraserCase,Eraser_error_brand){
    ASSERT_ANY_THROW(Eraser e1("Hank","Small","Family"));
}

TEST(EraserCase,Eraser_Price){
    Eraser e1("Hank","Small","MUJI");
    Eraser e2("Hank","Medium","Staedtler");
    Eraser e3("Hank","Large","Pentel");

    ASSERT_NEAR(e1.price(),29,0.01);
    ASSERT_NEAR(e2.price(),30,0.01);
    ASSERT_NEAR(e3.price(),156,0.01);

}

TEST_F(EraserTest,Eraser_have_id){
    Eraser e1("Hank","Small","MUJI");
    Eraser e2("Hank","Medium","Staedtler");
    Eraser e3("Hank","Large","Pentel");

    EXPECT_EQ(e1.name(),"Small MUJI Eraser");
    EXPECT_EQ(e2.name(),"Medium Staedtler Eraser");
    EXPECT_EQ(e3.name(),"Large Pentel Eraser");
}

TEST_F(EraserTest,Eraser_non_have_id){
    Eraser e1("Small","MUJI");
    Eraser e2("Hank","Medium","Staedtler");
    Eraser e3("Hank","Large","Pentel");

    EXPECT_EQ(e1.name(),"Small MUJI Eraser");
    EXPECT_EQ(e2.name(),"Medium Staedtler Eraser");
    EXPECT_EQ(e3.name(),"Large Pentel Eraser");
}

TEST_F(EraserTest,Eraser_id){
    Eraser e1("Hank","Small","MUJI");

    EXPECT_EQ(e1.id(),"Hank");
}