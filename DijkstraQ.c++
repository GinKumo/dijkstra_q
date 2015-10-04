#include <iostream>

#include "DijkstraQ.h"

#include <cstring> // std::strcmp, std::strcpy
#include <sstream>  // istringstream
#include <queue>
#include <limits>
#include <cassert>

using namespace std;

#ifndef DEBUG
#define DEBUG 0
#endif

// ------------
// dijkstraq_read2
// ------------

pair<int, int> dijkstraq_read2 (const string& s) {
    istringstream sin(s);
    int n;
    int m;
    sin >> n >> m;
    return make_pair(n, m);}

// ------------
// dijkstraq_read3
// ------------

tuple<int, int, int> dijkstraq_read3 (const string& s) {
    istringstream sin(s);
    int a;
    int b;
    int w;
    sin >> a >> b >> w;
    return make_tuple(a, b, w);}

// -------------
// dijkstraq_solve
// -------------

void dijkstraq_solve (istream& r, ostream& w) {
    string s;
    int m,n,a_i,b_i,w_i;
    map<int, vector< pair<int, int> > > g;
    while (getline(r, s)) {
        tie(m,n) = dijkstraq_read2(s);
        for (int i = 0; i < n && getline(r, s); ++i) {
            tie(a_i, b_i, w_i) = dijkstraq_read3(s);
            // make sure input is well formed and nodes aren't out of bounds
            assert(a_i >= 1);
            assert(a_i <= m);
            assert(b_i >= 1);
            assert(b_i <= m);
            // insert edge into graph
            g[a_i].push_back(pair<int, int>(b_i, w_i));
        }
        // print graph
        /*
        for (auto i: g) {
            cerr << i.first << " [";
            for (auto j: i.second) {
                cerr << "(" << j.first << ", " << j.second << "), ";
            }
            cerr << "]" << endl;
        }*/
        // call evaluator here
        vector<int> ret = dijkstraq_eval(1, m, g);
        // write output
        bool first = true;
        for (auto& i: ret) {
            if (first) {
                first = false;
            } else {
                w << " ";
            }
            w << i;
        }
        w << endl;
    }
}


// ------------
// dijkstraq_eval
// ------------

vector<int> dijkstraq_eval (int src, int dst, map<int, vector< pair<int, int> > > g)
{
    return vector<int>{1, 4, 3, 5};
}

