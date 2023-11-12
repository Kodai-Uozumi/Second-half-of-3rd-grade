#include "catch.hpp"
#include "judge.h"

TEST_CASE( "judge_score works fine", "[judge_score]" ) {
    REQUIRE( judge_score(11, 0) == 1 );
    REQUIRE( judge_score(0, 0) == 1 );
    REQUIRE( judge_score(-1, 0) == 1 );
    REQUIRE( judge_score(-1, 11) == 1 );
    REQUIRE( judge_score(11, -1) == -1 );
    REQUIRE( judge_score(-1, -1) == 0 );
    REQUIRE( judge_score(0, 1) == -1 );
    REQUIRE( judge_score(13, 12) == 1 );
    REQUIRE( judge_score(11, 18) == -1 );
    REQUIRE( judge_score(11, 18) == -1 );
}

TEST_CASE( "calc_score works fine", "[calc_score]" ) {
    int cards1[] = {1, 10};
    REQUIRE( calc_score(cards1, sizeof(cards1)/sizeof(int)) == -1 );

    int cards2[] = {12, 1};
    REQUIRE( calc_score(cards2, sizeof(cards2)/sizeof(int)) == -1 );

    int cards3[] = {6, 11};
    REQUIRE( calc_score(cards3, sizeof(cards3)/sizeof(int)) == 16 );

    int cards4[] = {6, 12};
    REQUIRE( calc_score(cards4, sizeof(cards4)/sizeof(int)) == 16 );

    int cards5[] = {6, 13};
    REQUIRE( calc_score(cards5, sizeof(cards5)/sizeof(int)) == 16 );

    int cards6[] = {8, 7, 7};
    REQUIRE( calc_score(cards6, sizeof(cards6)/sizeof(int)) == 0 );

    int cards7[] = {1, 8};
    REQUIRE( calc_score(cards7, sizeof(cards7)/sizeof(int)) == 19 );

    int cards8[] = {1, 8, 9};
    REQUIRE( calc_score(cards8, sizeof(cards8)/sizeof(int)) == 18 );

    int cards9[] = {1, 1};
    REQUIRE( calc_score(cards9, sizeof(cards9)/sizeof(int)) == 12 );

    int cards10[] = {1, 1, 2};
    REQUIRE( calc_score(cards10, sizeof(cards10)/sizeof(int)) == 14 );

    int cards11[] = {1, 1, 13};
    REQUIRE( calc_score(cards11, sizeof(cards11)/sizeof(int)) == 12 );

    int cards12[] = {1, 1, 1};
    REQUIRE( calc_score(cards12, sizeof(cards12)/sizeof(int)) == 13 );

    int cards13[] = {1, 1, 1, 2};
    REQUIRE( calc_score(cards13, sizeof(cards13)/sizeof(int)) == 15 );

    int cards14[] = {1, 1, 1, 10};
    REQUIRE( calc_score(cards14, sizeof(cards14)/sizeof(int)) == 13 );

    int cards15[] = {1, 1, 1, 1};
    REQUIRE( calc_score(cards15, sizeof(cards15)/sizeof(int)) == 14 );

    int cards16[] = {1, 1, 1, 1, 2};
    REQUIRE( calc_score(cards16, sizeof(cards16)/sizeof(int)) == 16 );

    int cards17[] = {1, 1, 1, 1, 10};
    REQUIRE( calc_score(cards17, sizeof(cards17)/sizeof(int)) == 14 );

    int cards18[] = {3, 9};
    REQUIRE( calc_score(cards18, sizeof(cards18)/sizeof(int)) == 12 );

    int cards19[] = {3, 9, 2};
    REQUIRE( calc_score(cards19, sizeof(cards19)/sizeof(int)) == 14 );

    int cards20[] = {3, 9, 2, 4};
    REQUIRE( calc_score(cards20, sizeof(cards20)/sizeof(int)) == 18 );

    int cards21[] = {3, 9, 2, 4, 6};
    REQUIRE( calc_score(cards21, sizeof(cards21)/sizeof(int)) == 0 );

    int cards22[] = {6, 7, 8};
    REQUIRE( calc_score(cards22, sizeof(cards22)/sizeof(int)) == 21 );
}
