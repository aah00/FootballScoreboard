set(target FootballScoreBoardLib)

if(DEFINED ${target}_USER_DEFINED)
    set(target ${${target}_USER_DEFINED})
endif()

add_library(${target} STATIC
    src/ScoreBoard.cpp
)

target_include_directories(${target} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

