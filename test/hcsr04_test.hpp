#ifndef HCSR04_TEST_HPP
#define HCSR04_TEST_HPP

#include "HCSR04.hpp"
#include "catch.hpp"
#include "hcsr04_test_bench.hpp"

/**
 * @brief HCSR04 Sonar Test Using HCSR04TestBench
 *
 * @details
 * This test case tests the calculated values of the HCSR04 class.
 * Values are expected to be in centimeters and have an error range
 * of max 1 cm. This is because timing may not be perfect on the
 * platform that is being tested on. This does not affect
 * the credibility of this test, because this test primarily tests
 * the underlying algorithm of properly detecting the I/O pulses
 * of the HCSR04 sonar.
 */
TEST_CASE("HCSR04 Sonar Test Using HCSR04TestBench", "[sensor]") {
    SECTION("> 23280 microseconds") {
        HCSR04TestBench testBench = {50000};
        HCSR04 hcsr04 = HCSR04(testBench.getTriggerPin(), testBench.getEchoPin());
        REQUIRE(hcsr04.getDistance() == 400);
    }
    SECTION("23280 microseconds") {
        HCSR04TestBench testBench = {23280};
        HCSR04 hcsr04 = HCSR04(testBench.getTriggerPin(), testBench.getEchoPin());
        const uint32_t distance = hcsr04.getDistance();
        REQUIRE(distance >= 399);
        REQUIRE(distance <= 401);
    }
    // Speed of sound: 343 m/s
    // delay: 0,016s
    // Roundtrip distance: 343 * 0,016 = 5,488m
    // Travel distance: 5,488 / 2 = 2,744m

    SECTION("16000 microseconds") {
        HCSR04TestBench testBench = {16000};
        HCSR04 hcsr04 = HCSR04(testBench.getTriggerPin(), testBench.getEchoPin());
        const uint32_t distance = hcsr04.getDistance();
        REQUIRE(distance >= 273);
        REQUIRE(distance <= 275);
    }

    SECTION("12000 microseconds") {
        HCSR04TestBench testBench = {12000};
        HCSR04 hcsr04 = HCSR04(testBench.getTriggerPin(), testBench.getEchoPin());
        const uint32_t distance = hcsr04.getDistance();
        REQUIRE(distance >= 205);
        REQUIRE(distance <= 207);
    }

    SECTION("8000 microseconds") {
        HCSR04TestBench testBench = {8000};
        HCSR04 hcsr04 = HCSR04(testBench.getTriggerPin(), testBench.getEchoPin());
        const uint32_t distance = hcsr04.getDistance();
        REQUIRE(distance >= 136);
        REQUIRE(distance <= 138);
    }

    SECTION("4000 microseconds") {
        HCSR04TestBench testBench = {4000};
        HCSR04 hcsr04 = HCSR04(testBench.getTriggerPin(), testBench.getEchoPin());
        const uint32_t distance = hcsr04.getDistance();
        REQUIRE(distance >= 67);
        REQUIRE(distance <= 69);
    }

    SECTION("2000 microseconds") {
        HCSR04TestBench testBench = {2000};
        HCSR04 hcsr04 = HCSR04(testBench.getTriggerPin(), testBench.getEchoPin());
        const uint32_t distance = hcsr04.getDistance();
        REQUIRE(distance >= 33);
        REQUIRE(distance <= 35);
    }
}

#endif // HCSR04_TEST_HPP