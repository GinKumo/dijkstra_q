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

TEST(CollatzFixture, solve_1) {
    istringstream r("5 6\n1 2 2\n2 5 5\n2 3 4\n1 4 1\n4 3 3\n3 5 1\n");
    ostringstream w;
    dijkstraq_solve(r, w);
    ASSERT_EQ("1 4 3 5\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("5 6\n1 2 2\n2 5 5\n2 3 4\n1 4 1\n4 3 3\n3 5 1\n");
    ostringstream w;
    dijkstraq_solve(r, w);
    ASSERT_EQ("1 4 3 5\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("2 1\n1 2 1\n");
    ostringstream w;
    dijkstraq_solve(r, w);
    ASSERT_EQ("1 2\n", w.str());}

TEST(CollatzFixture, solve_4) {
    istringstream r("3 1\n1 2 1\n");
    ostringstream w;
    dijkstraq_solve(r, w);
    ASSERT_EQ("-1\n", w.str());}

TEST(CollatzFixture, solve_5) {
    istringstream r("3 3\n1 2 1\n1 3 2\n2 3 1\n");
    ostringstream w;
    dijkstraq_solve(r, w);
    ASSERT_EQ("1 3\n", w.str());}

TEST(CollatzFixture, solve_6) {
    istringstream r("10 10\n1 5 12\n2 4 140\n2 10 149\n3 6 154\n3 7 9\n3 8 226\n3 10 132\n4 10 55\n5 8 33\n7 8 173\n");
    ostringstream w;
    dijkstraq_solve(r, w);
    ASSERT_EQ("1 5 8 7 3 10\n", w.str());}

TEST(CollatzFixture, solve_7) {
    istringstream r("10 10\n1 5 178\n1 8 221\n2 7 92\n2 8 159\n3 5 55\n3 6 179\n3 10 237\n4 8 205\n5 6 191\n8 10 157\n");
    ostringstream w;
    dijkstraq_solve(r, w);
    ASSERT_EQ("1 8 10\n", w.str());}

TEST(CollatzFixture, solve_8) {
    istringstream r("10 10\n1 4 200\n1 9 197\n3 4 79\n3 5 213\n3 6 149\n5 8 3\n5 9 189\n6 7 130\n6 9 51\n8 10 135\n");
    ostringstream w;
    dijkstraq_solve(r, w);
    ASSERT_EQ("1 9 5 8 10\n", w.str());}

TEST(CollatzFixture, solve_9) {
    istringstream r("10 10\n1 4 201\n2 3 238\n3 4 40\n3 6 231\n3 8 45\n4 5 227\n4 6 58\n4 9 55\n5 7 14\n6 10 242\n");
    ostringstream w;
    dijkstraq_solve(r, w);
    ASSERT_EQ("1 4 6 10\n", w.str());}

