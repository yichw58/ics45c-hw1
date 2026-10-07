// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the Stack module. It is graded: the autograder runs it against
// a correct Stack and against several Stacks with one bug each. A test is worth something only
// when it passes on the correct Stack and fails on a broken one, so a test that always fails
// (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for pop, push_all, pop_all, and the edges
// (an empty stack, a stack of one character, a full stack).
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "stack.hpp"

TEST(StackTests, NewStackIsEmptyAndNotFull) {
    Stack stk;
    EXPECT_TRUE(stk.isEmpty());
    EXPECT_FALSE(stk.isFull());
}

TEST(StackTests, PushThenTopSeesTheCharacter) {
    Stack stk;
    stk.push('z');
    EXPECT_EQ(stk.top(), 'z');
}

// ADD YOUR TESTS HERE:
TEST(StackTests, EmptyPopReturnsAt){
    Stack stk;
    EXPECT_EQ(stk.pop(),'@');
}

TEST(StackTests, OnePopEmptiesStack){
    Stack stk;
    stk.push('c');
    stk.pop();
    EXPECT_EQ(stk.pop(),'@');
}

TEST(StackTests, PushAllReversesOrder){
    Stack stk;
    push_all(stk, "abc");
    EXPECT_EQ(stk.pop(),'c');
    EXPECT_EQ(stk.pop(),'b');
    EXPECT_EQ(stk.pop(),'a');
    EXPECT_TRUE(stk.isEmpty());
}

TEST(StackTests, FullStackRejectsExtraPush){
    Stack stk;
    for(int i=0; i < STK_MAX; ++i){
        stk.push('a');
    }
    EXPECT_TRUE(stk.isFull());
    char old_top = stk.top();
    stk.push('a');
    EXPECT_EQ(stk.top(),old_top);

}

TEST(StackTests, PopAllEmptiesStack){
    Stack stk;
    push_all(stk, "abc");

    pop_all(stk);

    EXPECT_TRUE(stk.isEmpty());
    EXPECT_EQ(stk.top(), '@');
}