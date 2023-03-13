
#include "ScoreBoard.hpp"
#include "Match.hpp"
#include <algorithm>
#include <vector>

using namespace LiveScore;

// Constructor
ScoreBoard::ScoreBoard()
{}

// Destructor
ScoreBoard::~ScoreBoard()
{}

/**
* Start a game with the given team names.
*
* @param home_team Name of the home team.
* @param away_team Name of the away team.
* @return Result::Ok when the operation is successful or
          Result::Game_already_exist if the game already exists.
*/
Result ScoreBoard::start_game(std::string home_team, std::string away_team)
{
    ParticipatingTeams participants(home_team, away_team);
    auto team_compare = [participants](const Match& m) { return m.get_teams() == participants; };
    if (find_if(score_board_list.begin(), score_board_list.end(), team_compare) != score_board_list.end())
    {
        return Result::Game_already_exist;
    }

    score_board_list.push_back(Match(home_team, away_team));
    sort_score_board();
    return Result::Ok;
}

/**
* Update the score of an ongoing game.
*
* @param home_team Name of the home team.
* @param away_team Name of the away team.
* @param home_score Abosulute score of the home team.
* @param away_score Absolute score of the away team.

* @return Result::Ok when the operation is successful or
          Result::Game_not_found if the game does not exist.
*/
Result ScoreBoard::set_score (std::string home_team, std::string away_team,
        unsigned int home, unsigned int away)
{
    throw "Function not implemented.";
}

/**
* End a gave given by two team-names.
*
* @param home_team Name of the home team.
* @param away_team Name of the away team.

* @return Result::Ok when the operation is successful or
          Result::Game_not_found if the game does not exist.
*/
Result ScoreBoard::end_game (std::string home_team, std::string away_team)
{
    throw "Function not implemented.";
}

/**
* Get the summary of ongoing games.

* @return summary of ongoing games in sorted order.
*/
std::string ScoreBoard::get_summary() const
{
    throw "Function not implemented.";
}

/**
* Get the summary of ongoing games.
* @param ScoreBoard::summary empty vector to be updated by match results.
* 
* @return Result::Ok when the operation is successful
*/
Result ScoreBoard::get_summary(std::vector<std::string>& summary) const
{
    throw "Function not implemented.";
}

void ScoreBoard::sort_score_board() {
    std::sort(score_board_list.begin(), score_board_list.end(),
        [](const auto &lhs, const auto &rhs) {
            if (lhs.get_total_score() == rhs.get_total_score())
            {
                return lhs.get_start_time() > rhs.get_start_time();
            }
            else
            {
                return lhs.get_total_score() > rhs.get_total_score();
            }
        }
    );
}
