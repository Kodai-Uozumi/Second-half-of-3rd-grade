#include "catch.hpp"
#include "bmi_check.h"

TEST_CASE( "calcBMI computation", "[checkBMI]" ) {
    REQUIRE( calcBMI(1.8, 50.0) == Approx(15.432).epsilon(0.01) );
    REQUIRE( calcBMI(1.7, 60.0) == Approx(20.761).epsilon(0.01) );
    REQUIRE( calcBMI(1.6, 100.0) == Approx(39.063).epsilon(0.01) );
}

TEST_CASE( "checkBMI works correct", "[calcBMI]" ) {
    REQUIRE( checkBMI(15.4, 15) == UNKNOWN );
    REQUIRE( checkBMI(39.1, 18) == FAT );
    REQUIRE( checkBMI(20.0, 20) == STANDARD );
    REQUIRE( checkBMI(15.4, 20) == SLIM );
    REQUIRE( checkBMI(15.4, 60) == SLIM );
    REQUIRE( checkBMI(15.4, 80) == SLIM );
}
