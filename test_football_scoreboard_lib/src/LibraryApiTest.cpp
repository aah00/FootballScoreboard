#include <gtest/gtest.h>
#include "ScoreBoard.hpp"
#include "Result.hpp"

using namespace LiveScore;

/**
 * This framework defines test cases to verify
 * adding and deleting a match, or updating and
 * getting results of ongoing matches.
 * Note: No advanced or corner test-cases are
        defined here.
 * 
 */
class LibraryApiTest: public ::testing::Test
{
public: 
    LibraryApiTest()
    {
        
        sb = new ScoreBoard();
    }

    // code here will execute just before the test ensues
    void SetUp()
    {
    }

    // code here will be called just after the test completes
    void TearDown()
    {
        delete sb;
    }

    // cleanup any pending stuff
    ~LibraryApiTest()
    {
    }

    // put in any custom data members
    ScoreBoard *sb;

    std::string home_team = "Norway";
    std::string away_team = "Spain";
    unsigned int home_team_score = 1;
    unsigned int away_team_score = 0;
};

// Test case: call start_game to start a new game with the
// participating team-names.
TEST_F (LibraryApiTest, StartGame)
{
    Result result = sb->start_game(home_team, away_team);
    EXPECT_EQ(Result::Ok, result);
}

// Test case: update the score of an ongoing match, identified
// by the participating team-names and also provide the score-line.
TEST_F (LibraryApiTest, UpdateScore)
{
    Result result = sb->start_game(home_team, away_team);
    result = sb->set_score(home_team, away_team, home_team_score, away_team_score);
    EXPECT_EQ(Result::Ok, result);
}

// Test case: delete an ongoing match, identified
// by the participating team-names.
TEST_F (LibraryApiTest, EndGame)
{
    Result result = sb->start_game(home_team, away_team);
    result = sb->set_score(home_team, away_team, home_team_score, away_team_score);
    result = sb->end_game(home_team, away_team);
    EXPECT_EQ(Result::Ok, result);
}

// Test case: get the summarized result of ongoing matches.
TEST_F (LibraryApiTest, GetSummary)
{
    Result result = sb->start_game(home_team, away_team);
    result = sb->set_score(home_team, away_team, home_team_score, away_team_score);
    std::string summary = sb->get_summary();
    EXPECT_NE("", summary);
}