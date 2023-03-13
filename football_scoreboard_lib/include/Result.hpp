#pragma once

namespace LiveScore
{

// Expected return values from the
// ScoreBoard library functions.
enum class Result
{
	Ok, // when the operation is successful
	Game_not_found, // expected update/delete operation failed as requested match is not running
	Game_already_exist, // failed to start a game as it is started already

};

// static const char *enum_to_string[] ={
//    "OK"
// };


}
