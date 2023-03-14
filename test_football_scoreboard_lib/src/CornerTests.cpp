#include <gtest/gtest.h>
#include "ScoreBoard.hpp"
#include "Result.hpp"
#include <vector>

using namespace LiveScore;

/**
 * This framework tests the corner case scenarios such as
 * the summary result once the last match is deleted, performing
 * update/delete operation on non-existing match etc.
 */
class CornerTest: public ::testing::Test
{
public:
    CornerTest()
    {
        // initialization code here
        sb = new ScoreBoard();
    }

    void SetUp()
    {
        // code here will execute just before the test ensues
    }

    void TearDown()
    {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
        delete sb;
    }

    ~CornerTest()
    {
        // cleanup any pending stuff, but no exceptions allowed
    }

    // put in any custom data members that you need
    ScoreBoard *sb;
};

TEST_F (CornerTest, StartTimeScore)
{
    auto result = sb->start_game("Norway", "Spain");
    std::string summary = sb->get_summary();
    EXPECT_EQ("1. Norway 0  -  Spain 0\n", summary);
}

TEST_F (CornerTest, DuplicateMatch)
{
    auto result = sb->start_game("Norway", "Spain");
    result = sb->start_game("Norway", "Spain");
    EXPECT_EQ(Result::Game_already_exist, result);
}

TEST_F (CornerTest, UpdateNotExistingMatch)
{
    auto result = sb->set_score("Norway", "Spain", 1, 0);
    EXPECT_EQ(Result::Game_not_found, result);
}

TEST_F (CornerTest, EndNotExistingMatch)
{
    auto result = sb->end_game("Norway", "Spain");
    EXPECT_EQ(Result::Game_not_found, result);  // check when there is no game
    result = sb->start_game("Germany", "Italy");
    result = sb->end_game("Finland", "Sweden"); // check when there is one or more game
    EXPECT_EQ(Result::Game_not_found, result);
}

TEST_F (CornerTest, EndLastGame)
{
    auto result = sb->start_game("Norway", "Spain");
    result = sb->end_game("Norway", "Spain");
    EXPECT_EQ(Result::Ok, result);
    std::string summary = sb->get_summary();
    EXPECT_EQ("", summary);
}
