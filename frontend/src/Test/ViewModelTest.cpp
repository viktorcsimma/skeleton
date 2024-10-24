#include "ViewModel/HsAppStateWrapper.hpp"
#include "ViewModel/OddParameterException.hpp"

#include <catch2/catch_test_macros.hpp>

#include <catch2/reporters/catch_reporter_event_listener.hpp>
#include <catch2/reporters/catch_reporter_registrars.hpp>

// This file can contain Catch2-based C++ tests.

TEST_CASE("HsAppStateWrapper") {
    HsAppStateWrapper appStateWrapper;
    
    SECTION("exampleInteraction") {
        REQUIRE("hello world" == appStateWrapper.exampleInteraction());
    }
}
