#include "../src/sort.h"
#include "../src/eraser.h"
#include "../src/pencil.h"
#include "../src/stationery.h"
#include <gtest/gtest.h>




            
class SortTest : public testing::Test{
    
    protected:
        

        void SetUp() override{
            items.push_back(&p1);
            items.push_back(&p2);
            items.push_back(&p3);
            items.push_back(&e1);
        }
        Pencil p1{"Hank",18, "H"};
        Pencil p2{"Hank",15, "2B"};
        Pencil p3{"Hank",12, "2H"};
        Eraser e1{"Hank","Small", "MUJI"};
        std::vector<Stationery *> items ;

};

template<class T>
bool compare(T a, T b){
    return a-> price()<b->price();
}


TEST(Sortbyprice,sortbyprice_case1){
    Pencil p1("Hank",18, "H");
    Pencil p2("Hank",15, "2B");
    Pencil p3("Hank",12, "2H");
    Eraser e1("Hank","Large", "MUJI");

    std::vector<Stationery *> items = {&p1, &p2, &p3, &e1};
    sortByPrice(items);


    ASSERT_EQ(items[0]->price(),p2.price());
    ASSERT_EQ(items[1]->price(),p3.price());
    ASSERT_EQ(items[2]->price(),p1.price());
    ASSERT_EQ(items[3]->price(),e1.price());


}

TEST(Sortbyprice,sortbyprice_case2){
    Pencil p1("Hank",18, "H");
    Pencil p2("Hank",15, "2B");
    Pencil p3("Hank",12, "2H");
    Eraser e1("Hank","Small", "MUJI");

    std::vector<Stationery *> items = {&p1, &p2, &p3, &e1};
    sortByPrice(items);


    ASSERT_EQ(items[0]->price(),e1.price());
    ASSERT_EQ(items[1]->price(),p2.price());
    ASSERT_EQ(items[2]->price(),p3.price());
    ASSERT_EQ(items[3]->price(),p1.price());


}

TEST(Sortbyprice,sortbyprice_case3){
    Pencil p1("Hank",18, "H");
    Pencil p2("Hank",15, "2B");
    Pencil p3("Hank",12, "2H");
    Eraser e1("Hank","Small", "MUJI");

    std::vector<Stationery *> items = {&p1, &p2, &p3, &e1};
    sortByPrice(items);


    ASSERT_EQ(items[0]->name(),"Small MUJI Eraser");
    ASSERT_EQ(items[1]->name(),"2B Pencil");
    ASSERT_EQ(items[2]->name(),"2H Pencil");
    ASSERT_EQ(items[3]->name(),"H Pencil");


}

TEST_F(SortTest,sortbyprice_case_down){
    
    sortByPrice(items,[](Stationery * b,Stationery * c){
                                
                                return b -> price() > c -> price();
                                });


    EXPECT_EQ(items[3]->name(),"Small MUJI Eraser");
    EXPECT_EQ(items[2]->name(),"2B Pencil");
    EXPECT_EQ(items[1]->name(),"2H Pencil");
    EXPECT_EQ(items[0]->name(),"H Pencil");


}

TEST_F(SortTest,sortbyprice_case_up){
    
    sortByPrice(items,[](Stationery * b,Stationery * c){
                                
                                return b -> price() < c -> price();
                                });


    EXPECT_EQ(items[0]->name(),"Small MUJI Eraser");
    EXPECT_EQ(items[1]->name(),"2B Pencil");
    EXPECT_EQ(items[2]->name(),"2H Pencil");
    EXPECT_EQ(items[3]->name(),"H Pencil");


}

TEST_F(SortTest,sortbyprice_anonymous_function){
    

    

     sortByPrice(items,compare);
    EXPECT_EQ(items[0]->name(),"Small MUJI Eraser");
    EXPECT_EQ(items[1]->name(),"2B Pencil");
    EXPECT_EQ(items[2]->name(),"2H Pencil");
    EXPECT_EQ(items[3]->name(),"H Pencil");


}