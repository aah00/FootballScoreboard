#pragma once

#include "ParticipatingTeams.hpp"
#include "Result.hpp"
#include "Score.hpp"
#include <ctime>
#include <string>

namespace LiveScore
{

/**
 * Class definition for a match statistics.
*/
class Match
{
public:
    Match(std::string home, std::string away)
    : teams(home, away)
    , score(0,0)
    , start_time(clock())
    {}

    /**
    * Get the participating teams in the game.
    * @return participating teams.
    */
    ParticipatingTeams get_teams() const;

    /**
    * Get the score in a game.
    * @return home and away team score
    */
    Score get_score() const;

    /**
    * Get the total score in a game.
    * @return sum of home and away team score.
    */
    unsigned int get_total_score() const;

    /**
    * Get the start time of a game.
    * @return game start time
    */
    clock_t get_start_time() const;

    /**
    * Get the team-names and the scoreline of the match.
    * @return scoreline
    */
    std::string get_result();

    /**
    * Set the score of an ongoing game
    *
    * @param home_score Home team score.
    * @param away_score Away team score.

    * @return Result::Ok when the operation is successful.
    */
    Result set_score(unsigned int home_score, unsigned int away_score);

private:
    ParticipatingTeams teams;   // name of the home and away teams
    Score score;                // score of home and away teams
    clock_t start_time;         // start time of the game
};

}
