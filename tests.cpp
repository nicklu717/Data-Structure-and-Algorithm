#include "gtest/gtest.h"
#include "DataStructure/LinkedList/SingleLinkedList.cpp"

class SingleLinkedListTest: public testing::Test {
protected:
    void SetUp() override {
        list = new SingleLinkedList<int>();
    }

    void TearDown() override {
        delete list;
    }

    SingleLinkedList<int>* list;
};

TEST_F(SingleLinkedListTest, Element) {
    EXPECT_FALSE(list->element(0).has_value());
    EXPECT_FALSE(list->element(1).has_value());
    EXPECT_FALSE(list->element(99).has_value());

    list->append(3);
    EXPECT_TRUE(list->element(0).has_value());

    list->append(5);
    EXPECT_TRUE(list->element(1).has_value());

    list->append(8);
    EXPECT_TRUE(list->element(2).has_value());
}

TEST_F(SingleLinkedListTest, Append) {
    list->append(3);
    EXPECT_EQ(list->element(0).value(), 3);

    list->append(5);
    EXPECT_EQ(list->element(1).value(), 5);

    list->append(8);
    EXPECT_EQ(list->element(2).value(), 8);
}

TEST_F(SingleLinkedListTest, Insert) {
    EXPECT_FALSE(list->insert(3, 10));
    EXPECT_TRUE(list->insert(3, 0));
    EXPECT_EQ(list->element(0).value(), 3);

    EXPECT_TRUE(list->insert(5, 1));
    EXPECT_TRUE(list->insert(8, 2));
    EXPECT_TRUE(list->insert(7, 3));
    EXPECT_TRUE(list->insert(99, 0));
    EXPECT_FALSE(list->insert(23489, 23));

    EXPECT_EQ(list->element(0).value(), 99);
    EXPECT_EQ(list->element(1).value(), 3);
    EXPECT_EQ(list->element(2).value(), 5);
    EXPECT_EQ(list->element(3).value(), 8);
    EXPECT_EQ(list->element(4).value(), 7);
    EXPECT_FALSE(list->element(5).has_value());
}

TEST_F(SingleLinkedListTest, Remove) {
    EXPECT_FALSE(list->remove(0).has_value());

    list->append(3);
    list->append(5);
    list->append(8);
    list->append(10);

    EXPECT_EQ(list->remove(0).value(), 3);
    EXPECT_EQ(list->element(0).value(), 5);

    EXPECT_EQ(list->remove(1).value(), 8);
    EXPECT_EQ(list->element(0).value(), 5);
    EXPECT_EQ(list->element(1).value(), 10);
    EXPECT_FALSE(list->remove(2).has_value());
}