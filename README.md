# FootballScoreboard
A simple c++ based library to show all the ongoing matches and their scores.

The scoreboard supports the following operations:
- Start a new game, assuming initial score 0 – 0 and adding it the scoreboard.
This should capture following parameters:
  - Home team
  - Away team
- Update score. This should receive a pair of absolute scores: home team score and away
team score.
- Finish game currently in progress. This removes a match from the scoreboard.
- Get a summary of games in progress ordered by their total score. The games with the same
total score will be returned ordered by the most recently started match in the scoreboard.

</br>

# Pre-requisite
- CMake (version 3.17 or newer)
- Make
- gcc/g++ (with version c++20 support)
- GTest utilities


