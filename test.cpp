#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

// RemoveTwos
TEST_CASE ( "RemoveTwos behvaior:", "[RemoveTwos]") // tag
{
	SECTION("Valid inputs"){
	REQUIRE( RemoveTwos(16) == 1 );
	REQUIRE( RemoveTwos(7) == 7 );
	REQUIRE( RemoveTwos(26) == 13 );
	REQUIRE( RemoveTwos(52) == 13 );
	}

	SECTION("Invalid inputs") {
	REQUIRE_THROWS_AS(RemoveTwos(0), std::invalid_argument);
    REQUIRE_THROWS_AS(RemoveTwos(-8), std::invalid_argument);
	}
}

// RemoveFirstSubstring
TEST_CASE ( "RemoveFirstSubstring behavior:", "[RemoveFirstSubstring]") // tag
{
	SECTION("Valid inputs"){
	REQUIRE( RemoveFirstSubstring("hellohello", "he") == "llohello" );
	REQUIRE( RemoveFirstSubstring("racecar", "car") == "race" );
	REQUIRE( RemoveFirstSubstring("really long cool string", "long ") == "really cool string" );
	REQUIRE( RemoveFirstSubstring("invincible string!", "!") == "invincible string" );
	}

	SECTION("Invalid inputs") {
	REQUIRE_THROWS_AS(RemoveFirstSubstring("hello", ""), std::invalid_argument);
	}
}

// EvenMask
TEST_CASE ( "EvenMask behavior:", "[EvenMask]") // tag
{
	SECTION("Valid inputs"){
	REQUIRE( EvenMask(std::vector<int>{1, 2, 3, 4, 5}) == std::vector<bool>{false, true, false, true, false});
	REQUIRE( EvenMask(std::vector<int>{0, 0, 0, 1, 1}) == std::vector<bool>{true, true, true, false, false});
	REQUIRE( EvenMask(std::vector<int>{-10, 0, 20, 1, 101}) == std::vector<bool>{true, true, true, false, false});
	REQUIRE( EvenMask(std::vector<int>{11, 21, 31, 44, 555}) == std::vector<bool>{false, false, false, true, false});
	}
/*
	SECTION("Invalid inputs") {
	REQUIRE_THROWS_AS(EvenMask({}) );

	could not think of any invalid inputs
	}
*/
}

// MultiplesFilter
TEST_CASE ( "MultiplesFilter behavior:", "[MultiplesFilter]") // tag
{
	SECTION("Valid inputs"){
	REQUIRE( MultiplesFilter(std::vector<int>{1, 2, 3, 4, 5}, 2) == std::vector<int>{1, 3, 5});
	REQUIRE( MultiplesFilter(std::vector<int>{10, 20, 30, 40, 50}, 3) == std::vector<int>{10, 20, 40, 50});
	REQUIRE( MultiplesFilter(std::vector<int>{6, 12, 18, 24, 36}, 12) == std::vector<int>{6, 18});
	REQUIRE( MultiplesFilter(std::vector<int>{1, 21, 31, 41, 51}, 7) == std::vector<int>{1, 31, 41, 51});
	}
}
/*
	SECTION("Invalid inputs") {
	0 is the only invalid argument, this is covered by `throw`
	}
}
*/