# FootballScoreboard
A simple c++ (c++14 standard) based library to show all the ongoing matches and their scores.

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

## Assumption
- Two teams can have only one running match unless the game is differentiated by home and away basis, i.e.
    - if Norway(home):Spain(away) is already running, then
      - then a new match Norway(home):Spain(away) cannot be started,
      - but Spain(home):Norway(away) can be started
- Start time of a game is automatically initialized, no need to provide start time manually
- There is no end time of a game unless a call is maded to end the game

</br>

# Pre-requisite
- CMake (version 3.17 or newer)
- Make
- gcc/g++ (require c++14 standard)
- GTest utilities

# How to build the library and execute tests
- Move to `build` directory
- Type `cmake ..`
- Then type `make` and static library `libFootballScoreBoardLib.a` shall be created
- To run the test, type `make test`. Alternatively, can run the test executable
  `test_football_scoreboard_lib/FootballScoreboardLib_test`

# Future work
- Add code-coverage tool to check how much of the code is covered by the written tests
- Configure clang-format to enforce code formatting by CI/CD
- Update CMake configuration to add `GTest` as submodule
