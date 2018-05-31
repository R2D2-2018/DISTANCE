#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "filter.cpp"
#include "wrap-hwlib.hpp"

TEST_CASE("Example Test Case") {
    REQUIRE(10 == 10);
}

TEST_CASE("Filter::getMedian") {
    Filter filter;
    int a[] = {1, 2, 3, 4, 5, 6, 8, 9};
    int size = sizeof(a) / sizeof(int);

    REQUIRE(filter.getMedian(a, size) == 4);       // should pass
    REQUIRE_FALSE(filter.getMedian(a, size) == 9); // should fail
}