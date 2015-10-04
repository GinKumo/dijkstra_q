// --------------------------------
// TestDijkstraQ.c++
// Copyright (C) 2015
// Adrian Iley
// --------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "DijkstraQ.h"

using namespace std;

// -----------
// TestDijkstraQ
// -----------

// ----
// read
// ----

TEST(DijkstraQFixture, read2) {
    string s("1 10\n");
    const pair<int, int> p = dijkstraq_read2(s);
    ASSERT_EQ(1, p.first);
    ASSERT_EQ(10, p.second);}

TEST(DijkstraQFixture, read3) {
    int a,b,w;
    string s("1 10 100\n");
    const tuple<int, int, int> p = dijkstraq_read3(s);
    std::tie(a,b,w) = p;
    ASSERT_EQ(1,  a);
    ASSERT_EQ(10,   b);
    ASSERT_EQ(100, w);}

// -----
// solve
// -----

TEST(CollatzFixture, solve_0) {
    istringstream r("5 6\n1 2 2\n2 5 5\n2 3 4\n1 4 1\n4 3 3\n3 5 1\n");
    ostringstream w;
    dijkstraq_solve(r, w);
    ASSERT_EQ("1 4 3 5\n", w.str());}

TEST(CollatzFixture, solve_1) {
    istringstream r("5 6\n1 2 2\n2 5 5\n2 3 4\n1 4 1\n4 3 3\n3 5 1\n");
    ostringstream w;
    dijkstraq_solve(r, w);
    ASSERT_EQ("1 4 3 5\n", w.str());}

