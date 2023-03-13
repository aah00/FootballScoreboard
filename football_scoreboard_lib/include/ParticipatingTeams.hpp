#pragma once

#include <string>

namespace LiveScore
{

/**
 * Class definition for the participating teams.
*/
class ParticipatingTeams
{
public:
    ParticipatingTeams() = delete;
    ParticipatingTeams(std::string home_team, std::string away_team)
    : home(home_team)
    , away(away_team)
    {}

    // Operator overloading for == operator
    bool operator==(const ParticipatingTeams &other) const
    {
        return this->home == other.home && this->away == other.away;
    }

    std::string home;   // Name of the home team
    std::string away;   // Name of the away team
};

}
