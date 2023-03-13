#include "Match.hpp"

using namespace LiveScore;

ParticipatingTeams Match::get_teams() const
{
    return teams;
}

clock_t Match::get_start_time() const
{
    return start_time;
}

Score Match::get_score() const
{
    return score;
}

unsigned int Match::get_total_score() const
{
    return score.home + score.away;
}

std::string Match::get_result()
{
    std::string res = teams.home + " " + std::to_string(score.home) + "  -  "
                    + teams.away + " " + std::to_string(score.away);
    return res;
}

Result Match::set_score(unsigned int home_score, unsigned int away_score)
{
    score.home = home_score;
    score.away = away_score;
}
