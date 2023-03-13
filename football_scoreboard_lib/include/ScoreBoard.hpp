#pragma once

#include "Result.hpp"
#include <string>
#include <vector>

namespace LiveScore
{

/**
 * ScoreBoard class defines the APIs to perform
 * operations for the Live Football Scoreboard
 * library.
*/
class ScoreBoard
{
public:

    /**
     * Constructor
     */
    ScoreBoard();

    /**
     * Destructor
     */
    ~ScoreBoard();

    /**
    * Start a game with the given team names.
    *
    * @param home_team Name of the home team.
    * @param away_team Name of the away team.
    * @return Result::Ok when the operation is successful or
              Result::Game_already_exist if the game already exists.
    */
    Result start_game(std::string home_team, std::string away_team);

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
    Result set_score (std::string home_team, std::string away_team,
            unsigned int home, unsigned int away);

    /**
    * End a gave given by two team-names.
    *
    * @param home_team Name of the home team.
    * @param away_team Name of the away team.
    
    * @return Result::Ok when the operation is successful or
              Result::Game_not_found if the game does not exist.
    */
    Result end_game (std::string home_team, std::string away_team);

    /**
    * Get the summary of ongoing games.

    * @return summary of ongoing games in sorted order.
    */
    std::string get_summary() const;


    /**
    * Get the summary of ongoing games.
    * @param summary empty vector to be updated by match results.
    * 
    * @return Result::Ok when the operation is successful
    */
    Result get_summary(std::vector<std::string>& summary) const;
};

}
