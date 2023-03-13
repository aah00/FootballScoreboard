#include <gtest/gtest.h>
#include "ScoreBoard.hpp"
#include "Result.hpp"
#include <vector>

using namespace LiveScore;

/**
 * This framework tests the sorting order of the
 * ongoing matches.
 */
class TestSortingOrder: public ::testing::Test
{
public:
    TestSortingOrder()
    {
        // initialization code here
        sb = new ScoreBoard();
    }

    std::vector<std::string> expected_starttime_order;
    std::vector<std::string> expected_scoreline_order;
    std::vector<std::string> expected_mixed_order;

    void SetUp()
    {
        // code here will execute just before the test ensues
        sb->start_game("Norway", "Spain");
        sb->start_game("Brazil", "Argentina");
        sb->start_game("Germany", "Italy");

        expected_starttime_order.push_back("Germany:0::Italy:0");
        expected_starttime_order.push_back("Brazil:0::Argentina:0");
        expected_starttime_order.push_back("Norway:0::Spain:0");

        expected_scoreline_order.push_back("Brazil:1::Argentina:3");
        expected_scoreline_order.push_back("Norway:1::Spain:0");
        expected_scoreline_order.push_back("Germany:0::Italy:0");

        expected_mixed_order.push_back("Brazil:1::Argentina:3");
        expected_mixed_order.push_back("Germany:1::Italy:0");
        expected_mixed_order.push_back("Norway:1::Spain:0");
    }

    void TearDown()
    {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
        delete sb;
    }

    ~TestSortingOrder()
    {
        // cleanup any pending stuff, but no exceptions allowed
        expected_starttime_order.clear();
        expected_scoreline_order.clear();
        expected_mixed_order.clear();
    }

    // put in any custom data members that you need
    ScoreBoard *sb;
};


TEST_F (TestSortingOrder, OrderedByStartTime)
{
    std::vector<std::string> summary;
    auto result = sb->get_summary(summary);
    EXPECT_EQ(Result::Ok, result);
    EXPECT_EQ(expected_starttime_order.size(), summary.size());
    for(size_t i=0; i<summary.size(); i++)
    {
        EXPECT_EQ(expected_starttime_order[i], summary[i]);
    }
}

TEST_F (TestSortingOrder, OrderedByScore)
{
    std::vector<std::string> summary;
    sb->set_score("Norway", "Spain", 1, 0);
    sb->set_score("Brazil", "Argentina", 1, 3);

    auto result = sb->get_summary(summary);
    EXPECT_EQ(Result::Ok, result);
    EXPECT_EQ(expected_scoreline_order.size(), summary.size());
    for(size_t i=0; i<summary.size(); i++)
    {
        EXPECT_EQ(expected_scoreline_order[i], summary[i]);
    }
}

TEST_F (TestSortingOrder, OrderedByScoreAndStartTime)
{
    std::vector<std::string> summary;
    sb->set_score("Germany", "Italy", 1, 0);
    sb->set_score("Norway", "Spain", 1, 0);
    sb->set_score("Brazil", "Argentina", 1, 3);

    auto result = sb->get_summary(summary);
    EXPECT_EQ(Result::Ok, result);
    EXPECT_EQ(expected_mixed_order.size(), summary.size());
    for(size_t i=0; i<summary.size(); i++)
    {
        EXPECT_EQ(expected_mixed_order[i], summary[i]);
    }
}