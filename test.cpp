// Copyright 2024 by Juan Fernando Ruiz

#include <fstream>
#include <SFML/System.hpp>
#include "EDistance.hpp"
// #include "EDistance.cpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(optDistanceTest) {
    EDistance ed("ATCGT", "AACGT");
    BOOST_CHECK_EQUAL(ed.optDistance(), 1);
}

BOOST_AUTO_TEST_CASE(alignmentTest) {
    EDistance ed("ATA", "ATA");
    std::string expectedAlignment = "A A 0\nT T 0\nA A 0\n";
    BOOST_CHECK_EQUAL(ed.alignment(), expectedAlignment);
}

BOOST_AUTO_TEST_CASE(test_optDistance_empty) {
    EDistance ed("", "");
    BOOST_REQUIRE_EQUAL(ed.optDistance(), 0);
}

// Test the alignment function with empty strings
BOOST_AUTO_TEST_CASE(test_alignment_empty) {
    EDistance ed("", "");
    BOOST_REQUIRE_NO_THROW(ed.alignment());
}

// Test the alignment function with identical strings
BOOST_AUTO_TEST_CASE(test_alignment_identical_strings) {
    EDistance ed("AGCT", "AGCT");
    BOOST_REQUIRE_NO_THROW(ed.alignment());
}
