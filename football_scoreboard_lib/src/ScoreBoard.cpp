
#include <ScoreBoard.hpp>

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
    throw "Function not implemented.";
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
