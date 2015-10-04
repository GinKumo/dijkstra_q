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


// ----
// eval
// ----
/*
TEST(DijkstraQFixture, eval_0) {
    const int v = dijkstraq_eval(1000, 1000);
    ASSERT_EQ(0, v);}

TEST(DijkstraQFixture, eval_1) {
    const int v = dijkstraq_eval(6, 4);
    ASSERT_EQ(2, v);}

TEST(DijkstraQFixture, eval_2) {
    const int v = dijkstraq_eval(1, 10);
    ASSERT_EQ(9, v);}

TEST(DijkstraQFixture, eval_3) {
    const int v = dijkstraq_eval(2, 16);
    ASSERT_EQ(14, v);}

TEST(DijkstraQFixture, eval_4) {
    const int v = dijkstraq_eval(16, 2);
    ASSERT_EQ(3, v);}

TEST(DijkstraQFixture, eval_5) {
    const int v = dijkstraq_eval(5678, 1234);
    ASSERT_EQ(528, v);}

TEST(DijkstraQFixture, eval_6) {
    const int v = dijkstraq_eval(9383, 886);
    ASSERT_EQ(305, v);}

TEST(DijkstraQFixture, eval_7) {
    const int v = dijkstraq_eval(100, 99);
    ASSERT_EQ(50, v);}

TEST(DijkstraQFixture, eval_8) {
    const int v = dijkstraq_eval(3, 1);
    ASSERT_EQ(3, v);}
*/

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

// -----
// eval
// -----
/*
TEST(DijkstraQFixture, eval_9) {
 const int v = dijkstraq_eval(6, 4);
 ASSERT_EQ(2, v);}

TEST(DijkstraQFixture, eval_10) {
 const int v = dijkstraq_eval(1, 10);
 ASSERT_EQ(9, v);}

TEST(DijkstraQFixture, eval_11) {
 const int v = dijkstraq_eval(2, 1);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_12) {
 const int v = dijkstraq_eval(1, 2);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_13) {
 const int v = dijkstraq_eval(3, 1);
 ASSERT_EQ(3, v);}

TEST(DijkstraQFixture, eval_14) {
 const int v = dijkstraq_eval(1, 3);
 ASSERT_EQ(2, v);}

TEST(DijkstraQFixture, eval_15) {
 const int v = dijkstraq_eval(10, 2);
 ASSERT_EQ(5, v);}

TEST(DijkstraQFixture, eval_16) {
 const int v = dijkstraq_eval(99, 100);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_17) {
 const int v = dijkstraq_eval(100, 99);
 ASSERT_EQ(50, v);}

TEST(DijkstraQFixture, eval_18) {
 const int v = dijkstraq_eval(17, 10);
 ASSERT_EQ(3, v);}

TEST(DijkstraQFixture, eval_19) {
 const int v = dijkstraq_eval(6666, 666);
 ASSERT_EQ(255, v);}

TEST(DijkstraQFixture, eval_20) {
 const int v = dijkstraq_eval(666, 6666);
 ASSERT_EQ(6000, v);}

TEST(DijkstraQFixture, eval_21) {
 const int v = dijkstraq_eval(8192, 1);
 ASSERT_EQ(13, v);}

TEST(DijkstraQFixture, eval_22) {
 const int v = dijkstraq_eval(8193, 1);
 ASSERT_EQ(27, v);}

TEST(DijkstraQFixture, eval_23) {
 const int v = dijkstraq_eval(10000, 9999);
 ASSERT_EQ(5000, v);}

TEST(DijkstraQFixture, eval_24) {
 const int v = dijkstraq_eval(9999, 10000);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_25) {
 const int v = dijkstraq_eval(1, 10000);
 ASSERT_EQ(9999, v);}

TEST(DijkstraQFixture, eval_26) {
 const int v = dijkstraq_eval(5678, 1234);
 ASSERT_EQ(528, v);}

TEST(DijkstraQFixture, eval_27) {
 const int v = dijkstraq_eval(9103, 9102);
 ASSERT_EQ(4552, v);}

TEST(DijkstraQFixture, eval_28) {
 const int v = dijkstraq_eval(1, 8192);
 ASSERT_EQ(8191, v);}

TEST(DijkstraQFixture, eval_29) {
 const int v = dijkstraq_eval(1023, 9912);
 ASSERT_EQ(8889, v);}

TEST(DijkstraQFixture, eval_30) {
 const int v = dijkstraq_eval(500, 100);
 ASSERT_EQ(41, v);}

TEST(DijkstraQFixture, eval_31) {
 const int v = dijkstraq_eval(9999, 9997);
 ASSERT_EQ(4999, v);}

TEST(DijkstraQFixture, eval_32) {
 const int v = dijkstraq_eval(10000, 5000);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_33) {
 const int v = dijkstraq_eval(7997, 4000);
 ASSERT_EQ(3, v);}

TEST(DijkstraQFixture, eval_34) {
 const int v = dijkstraq_eval(10000, 1);
 ASSERT_EQ(20, v);}

TEST(DijkstraQFixture, eval_35) {
 const int v = dijkstraq_eval(8191, 1);
 ASSERT_EQ(14, v);}

TEST(DijkstraQFixture, eval_36) {
 const int v = dijkstraq_eval(10000, 9999);
 ASSERT_EQ(5000, v);}

TEST(DijkstraQFixture, eval_37) {
 const int v = dijkstraq_eval(9998, 9097);
 ASSERT_EQ(4099, v);}

TEST(DijkstraQFixture, eval_38) {
 const int v = dijkstraq_eval(9383, 886);
 ASSERT_EQ(305, v);}

TEST(DijkstraQFixture, eval_39) {
 const int v = dijkstraq_eval(9, 1);
 ASSERT_EQ(7, v);}

TEST(DijkstraQFixture, eval_40) {
 const int v = dijkstraq_eval(10000, 1918);
 ASSERT_EQ(671, v);}

TEST(DijkstraQFixture, eval_41) {
 const int v = dijkstraq_eval(3, 1);
 ASSERT_EQ(3, v);}

TEST(DijkstraQFixture, eval_42) {
 const int v = dijkstraq_eval(4, 1);
 ASSERT_EQ(2, v);}

TEST(DijkstraQFixture, eval_43) {
 const int v = dijkstraq_eval(10000, 2);
 ASSERT_EQ(19, v);}

TEST(DijkstraQFixture, eval_44) {
 const int v = dijkstraq_eval(10000, 3);
 ASSERT_EQ(17, v);}

TEST(DijkstraQFixture, eval_45) {
 const int v = dijkstraq_eval(10000, 4);
 ASSERT_EQ(18, v);}

TEST(DijkstraQFixture, eval_46) {
 const int v = dijkstraq_eval(10000, 9998);
 ASSERT_EQ(4999, v);}

TEST(DijkstraQFixture, eval_47) {
 const int v = dijkstraq_eval(10000, 5000);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_48) {
 const int v = dijkstraq_eval(10000, 5001);
 ASSERT_EQ(2, v);}

TEST(DijkstraQFixture, eval_49) {
 const int v = dijkstraq_eval(1, 10000);
 ASSERT_EQ(9999, v);}

TEST(DijkstraQFixture, eval_50) {
 const int v = dijkstraq_eval(9999, 1);
 ASSERT_EQ(21, v);}

TEST(DijkstraQFixture, eval_51) {
 const int v = dijkstraq_eval(9999, 7777);
 ASSERT_EQ(2779, v);}

TEST(DijkstraQFixture, eval_52) {
 const int v = dijkstraq_eval(100, 2);
 ASSERT_EQ(9, v);}

TEST(DijkstraQFixture, eval_53) {
 const int v = dijkstraq_eval(8722, 10);
 ASSERT_EQ(18, v);}

TEST(DijkstraQFixture, eval_54) {
 const int v = dijkstraq_eval(4561, 848);
 ASSERT_EQ(283, v);}

TEST(DijkstraQFixture, eval_55) {
 const int v = dijkstraq_eval(9973, 9967);
 ASSERT_EQ(4982, v);}

TEST(DijkstraQFixture, eval_56) {
 const int v = dijkstraq_eval(10000, 5555);
 ASSERT_EQ(556, v);}

TEST(DijkstraQFixture, eval_57) {
 const int v = dijkstraq_eval(10000, 999);
 ASSERT_EQ(378, v);}

TEST(DijkstraQFixture, eval_58) {
 const int v = dijkstraq_eval(6, 3);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_59) {
 const int v = dijkstraq_eval(38, 9);
 ASSERT_EQ(8, v);}

TEST(DijkstraQFixture, eval_60) {
    const int v = dijkstraq_eval(1000, 1000);
    ASSERT_EQ(0, v);}

TEST(DijkstraQFixture, eval_61) {
    const int v = dijkstraq_eval(6, 4);
    ASSERT_EQ(2, v);}

TEST(DijkstraQFixture, eval_62) {
    const int v = dijkstraq_eval(1, 10);
    ASSERT_EQ(9, v);}

TEST(DijkstraQFixture, eval_63) {
    const int v = dijkstraq_eval(2, 16);
    ASSERT_EQ(14, v);}

TEST(DijkstraQFixture, eval_64) {
    const int v = dijkstraq_eval(16, 2);
    ASSERT_EQ(3, v);}

TEST(DijkstraQFixture, eval_65) {
    const int v = dijkstraq_eval(5678, 1234);
    ASSERT_EQ(528, v);}

TEST(DijkstraQFixture, eval_66) {
    const int v = dijkstraq_eval(9383, 886);
    ASSERT_EQ(305, v);}

TEST(DijkstraQFixture, eval_67) {
    const int v = dijkstraq_eval(100, 99);
    ASSERT_EQ(50, v);}

TEST(DijkstraQFixture, eval_68) {
    const int v = dijkstraq_eval(3, 1);
    ASSERT_EQ(3, v);}


TEST(DijkstraQFixture, eval_69) {
 const int v = dijkstraq_eval(6, 4);
 ASSERT_EQ(2, v);}

TEST(DijkstraQFixture, eval_70) {
 const int v = dijkstraq_eval(1, 10);
 ASSERT_EQ(9, v);}

TEST(DijkstraQFixture, eval_71) {
 const int v = dijkstraq_eval(2, 1);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_72) {
 const int v = dijkstraq_eval(1, 2);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_73) {
 const int v = dijkstraq_eval(3, 1);
 ASSERT_EQ(3, v);}

TEST(DijkstraQFixture, eval_74) {
 const int v = dijkstraq_eval(1, 3);
 ASSERT_EQ(2, v);}

TEST(DijkstraQFixture, eval_75) {
 const int v = dijkstraq_eval(10, 2);
 ASSERT_EQ(5, v);}

TEST(DijkstraQFixture, eval_76) {
 const int v = dijkstraq_eval(99, 100);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_77) {
 const int v = dijkstraq_eval(100, 99);
 ASSERT_EQ(50, v);}

TEST(DijkstraQFixture, eval_78) {
 const int v = dijkstraq_eval(17, 10);
 ASSERT_EQ(3, v);}

TEST(DijkstraQFixture, eval_79) {
 const int v = dijkstraq_eval(6666, 666);
 ASSERT_EQ(255, v);}

TEST(DijkstraQFixture, eval_80) {
 const int v = dijkstraq_eval(666, 6666);
 ASSERT_EQ(6000, v);}

TEST(DijkstraQFixture, eval_81) {
 const int v = dijkstraq_eval(8192, 1);
 ASSERT_EQ(13, v);}

TEST(DijkstraQFixture, eval_82) {
 const int v = dijkstraq_eval(8193, 1);
 ASSERT_EQ(27, v);}

TEST(DijkstraQFixture, eval_83) {
 const int v = dijkstraq_eval(10000, 9999);
 ASSERT_EQ(5000, v);}

TEST(DijkstraQFixture, eval_84) {
 const int v = dijkstraq_eval(9999, 10000);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_85) {
 const int v = dijkstraq_eval(1, 10000);
 ASSERT_EQ(9999, v);}

TEST(DijkstraQFixture, eval_86) {
 const int v = dijkstraq_eval(5678, 1234);
 ASSERT_EQ(528, v);}

TEST(DijkstraQFixture, eval_87) {
 const int v = dijkstraq_eval(9103, 9102);
 ASSERT_EQ(4552, v);}

TEST(DijkstraQFixture, eval_88) {
 const int v = dijkstraq_eval(1, 8192);
 ASSERT_EQ(8191, v);}

TEST(DijkstraQFixture, eval_89) {
 const int v = dijkstraq_eval(1023, 9912);
 ASSERT_EQ(8889, v);}

TEST(DijkstraQFixture, eval_90) {
 const int v = dijkstraq_eval(500, 100);
 ASSERT_EQ(41, v);}

TEST(DijkstraQFixture, eval_91) {
 const int v = dijkstraq_eval(9999, 9997);
 ASSERT_EQ(4999, v);}

TEST(DijkstraQFixture, eval_92) {
 const int v = dijkstraq_eval(10000, 5000);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_93) {
 const int v = dijkstraq_eval(7997, 4000);
 ASSERT_EQ(3, v);}

TEST(DijkstraQFixture, eval_94) {
 const int v = dijkstraq_eval(10000, 1);
 ASSERT_EQ(20, v);}

TEST(DijkstraQFixture, eval_95) {
 const int v = dijkstraq_eval(8191, 1);
 ASSERT_EQ(14, v);}

TEST(DijkstraQFixture, eval_96) {
 const int v = dijkstraq_eval(10000, 9999);
 ASSERT_EQ(5000, v);}

TEST(DijkstraQFixture, eval_97) {
 const int v = dijkstraq_eval(9998, 9097);
 ASSERT_EQ(4099, v);}

TEST(DijkstraQFixture, eval_98) {
 const int v = dijkstraq_eval(9383, 886);
 ASSERT_EQ(305, v);}

TEST(DijkstraQFixture, eval_99) {
 const int v = dijkstraq_eval(9, 1);
 ASSERT_EQ(7, v);}

TEST(DijkstraQFixture, eval_100) {
 const int v = dijkstraq_eval(10000, 1918);
 ASSERT_EQ(671, v);}

TEST(DijkstraQFixture, eval_101) {
 const int v = dijkstraq_eval(3, 1);
 ASSERT_EQ(3, v);}

TEST(DijkstraQFixture, eval_102) {
 const int v = dijkstraq_eval(4, 1);
 ASSERT_EQ(2, v);}

TEST(DijkstraQFixture, eval_103) {
 const int v = dijkstraq_eval(10000, 2);
 ASSERT_EQ(19, v);}

TEST(DijkstraQFixture, eval_104) {
 const int v = dijkstraq_eval(10000, 3);
 ASSERT_EQ(17, v);}

TEST(DijkstraQFixture, eval_105) {
 const int v = dijkstraq_eval(10000, 4);
 ASSERT_EQ(18, v);}

TEST(DijkstraQFixture, eval_106) {
 const int v = dijkstraq_eval(10000, 9998);
 ASSERT_EQ(4999, v);}

TEST(DijkstraQFixture, eval_107) {
 const int v = dijkstraq_eval(10000, 5000);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_108) {
 const int v = dijkstraq_eval(10000, 5001);
 ASSERT_EQ(2, v);}

TEST(DijkstraQFixture, eval_109) {
 const int v = dijkstraq_eval(1, 10000);
 ASSERT_EQ(9999, v);}

TEST(DijkstraQFixture, eval_110) {
 const int v = dijkstraq_eval(9999, 1);
 ASSERT_EQ(21, v);}

TEST(DijkstraQFixture, eval_111) {
 const int v = dijkstraq_eval(9999, 7777);
 ASSERT_EQ(2779, v);}

TEST(DijkstraQFixture, eval_112) {
 const int v = dijkstraq_eval(100, 2);
 ASSERT_EQ(9, v);}

TEST(DijkstraQFixture, eval_113) {
 const int v = dijkstraq_eval(8722, 10);
 ASSERT_EQ(18, v);}

TEST(DijkstraQFixture, eval_114) {
 const int v = dijkstraq_eval(4561, 848);
 ASSERT_EQ(283, v);}

TEST(DijkstraQFixture, eval_115) {
 const int v = dijkstraq_eval(9973, 9967);
 ASSERT_EQ(4982, v);}

TEST(DijkstraQFixture, eval_116) {
 const int v = dijkstraq_eval(10000, 5555);
 ASSERT_EQ(556, v);}

TEST(DijkstraQFixture, eval_117) {
 const int v = dijkstraq_eval(10000, 999);
 ASSERT_EQ(378, v);}

TEST(DijkstraQFixture, eval_118) {
 const int v = dijkstraq_eval(6, 3);
 ASSERT_EQ(1, v);}

TEST(DijkstraQFixture, eval_119) {
 const int v = dijkstraq_eval(38, 9);
 ASSERT_EQ(8, v);}
*/

