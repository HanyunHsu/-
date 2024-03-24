#include "../src/find.h"
class FindCase : public ::testing::Test {
protected:
    Novel n1 = {1, "Red Riding Hood", "Gerlin"};
    Novel n2 = {2, "Harry Potter and the Sorcerer's Stone", "J.K. Rowling"};
    Novel n3 = {3, "Harry Potter and the Chamber of Secrets", "J.K. Rowling"};
    Novel n4 = {4, "Harry Potter and the Prisoner of Azkaban", "J.K. Rowling"};
    Magazine magazine1 = {5, "Times", "Sam Jacobs", "May 26, 2016"};
    std::vector<Publication *> publications = {{&n1, &n2, &n3, &n4, &magazine1}};
};

// bool find_by_author(Publication * lhs, std::string rhs){
//     return lhs->author() == rhs;
// }

// class FindByAuthor {
// public:
//     bool operator() (Publication * lhs, std::string rhs){
//         return lhs->author() == rhs;
//     }
// };

// TEST_F(FindCase, FindByAuthorLambda) {
//     std::vector<Publication *> result = find(publications, "J.K. Rowling", [](Publication * lhs, std::string rhs){
//         return lhs->author() == rhs;
//     });

//     ASSERT_EQ(*result.at(0), n2);
//     ASSERT_EQ(*result.at(1), n3);
//     ASSERT_EQ(*result.at(2), n4);
// }

// TEST_F(FindCase, FindByAuthorFunc) {
//     std::vector<Publication *> result = find(publications, "J.K. Rowling", find_by_author);

//     ASSERT_EQ(*result.at(0), n2);
//     ASSERT_EQ(*result.at(1), n3);
//     ASSERT_EQ(*result.at(2), n4);
// }

// TEST_F(FindCase, FindByAuthorClass) {
//     FindByAuthor findByAuthor;
//     std::vector<Publication *> result = find(publications, "J.K. Rowling", findByAuthor);

//     ASSERT_EQ(*result.at(0), n2);
//     ASSERT_EQ(*result.at(1), n3);
//     ASSERT_EQ(*result.at(2), n4);
// }

bool find_by_name(Publication * lhs, std::string rhs){
    if (lhs->name().find(rhs) != std::string::npos)
        return true;
    return false;
}

class FindByName {
public:
    bool operator() (Publication * lhs, std::string rhs){
        if (lhs->name().find(rhs) != std::string::npos)
            return true;
        return false;
    }
};

TEST_F(FindCase, FindByNameLambda) {
    std::vector<Publication *> result = find(publications.begin(), publications.end(), "Harry Potter", [](Publication * lhs, std::string rhs){
        if (lhs->name().find(rhs) != std::string::npos)
            return true;
        return false;
    });

    ASSERT_EQ(*result.at(0), n2);
    ASSERT_EQ(*result.at(1), n3);
    ASSERT_EQ(*result.at(2), n4);
}

TEST_F(FindCase, FindByNameFunc) {
    std::vector<Publication *> result = find(publications.begin(), publications.end(), "Harry Potter", find_by_name);

    ASSERT_EQ(*result.at(0), n2);
    ASSERT_EQ(*result.at(1), n3);
    ASSERT_EQ(*result.at(2), n4);
}

TEST_F(FindCase, FindByNameClass) {
    FindByName findByName;
    std::vector<Publication *> result = find(publications.begin(), publications.end(), "Harry Potter", findByName);

    ASSERT_EQ(*result.at(0), n2);
    ASSERT_EQ(*result.at(1), n3);
    ASSERT_EQ(*result.at(2), n4);
}

bool find_by_type(Publication * lhs, std::string rhs){
    return lhs->name_of_type() == rhs;
}

class FindByType {
public:
    bool operator() (Publication * lhs, std::string rhs){
        return lhs->name_of_type() == rhs;
    }
};

TEST_F(FindCase, FindByTypeLambda) {
    std::vector<Publication *> result = find(publications.begin(), publications.end(), "magazine", [](Publication * lhs, std::string rhs){
        return lhs->name_of_type() == rhs;
    });

    ASSERT_EQ(*result.at(0), magazine1);
}

TEST_F(FindCase, FindByTypeFunc) {
    std::vector<Publication *> result = find(publications.begin(), publications.end(), "magazine", find_by_type);

    ASSERT_EQ(*result.at(0), magazine1);
}

TEST_F(FindCase, FindByTypeClass) {
    FindByType findByType;
    std::vector<Publication *> result = find(publications.begin(), publications.end(), "magazine", findByType);

    ASSERT_EQ(*result.at(0), magazine1);
}