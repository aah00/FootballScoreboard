#pragma once

namespace LiveScore
{

/**
 * Class definition to keep the score of a game.
*/
class Score
{
public:
    Score(unsigned int home_team_score = 0, unsigned int away_team_score = 0)
    : home(home_team_score)
    , away(away_team_score)
    {}

    /**
    * Get the total score in a game.
    
    * @return sum of home and away team score.
    */
    unsigned int get_total_score() const
    {
        return home + away;
    }

    unsigned int home;  // Score of the home team
    unsigned int away;  // Score of the away team
};

}
