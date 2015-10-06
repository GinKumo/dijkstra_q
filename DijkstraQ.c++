#include <iostream>

#include "DijkstraQ.h"

#include <cstring> // std::strcmp, std::strcpy
#include <sstream>  // istringstream
#include <queue>
#include <limits>
#include <cassert>
#include <climits>
#include <cstdlib> // abs

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

#define N_CONN 0
#define N_WGHT 1
#define N_IDX  2
#define N_VIS  3

typedef std::tuple<int, int, int, int> quadruple_t;

class my_lessthan  {
public:
    bool operator() (const quadruple_t& a, const quadruple_t& b) const
    {
        return get<N_WGHT>(a) > get<N_WGHT>(b);
        return false;
    }
};


void dijkstraq_solve (istream& r, ostream& w) {
    string s;
    int m,n,a_i,b_i,w_i;
    //map<int, vector< pair<int, int> > > g;
    vector<vector< pair<int, int> > > g;
    while (getline(r, s)) {
        tie(m,n) = dijkstraq_read2(s);
        g.resize(m+1);
        for (int i = 0; i < n && getline(r, s); ++i) {
            tie(a_i, b_i, w_i) = dijkstraq_read3(s);
            // make sure input is well formed and nodes aren't out of bounds
            //assert(a_i >= 1);
            //assert(a_i <= m);
            //assert(b_i >= 1);
            //assert(b_i <= m);
            // insert edge into graph
            g[a_i].push_back(pair<int, int>(b_i, w_i));
            g[b_i].push_back(pair<int, int>(a_i, w_i));
        }
        // print graph
        /*for (auto i: g) {
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
        for (auto i = ret.end()-1; i>=ret.begin(); --i) {
            if (first) {
                first = false;
            } else {
                w << " ";
            }
            w << *i;
        }
        w << endl;
    }
}




// ------------
// dijkstraq_eval
// ------------

//vector<int> dijkstraq_eval (int src, int dst, map<int, vector< pair<int, int> > >& g)
vector<int>& dijkstraq_eval (int src, int dst, vector<vector< pair<int, int> > >& g)
{
    vector<quadruple_t > ninfo(dst+1);
    //map<int, quadruple_t> ninfo;

    std::priority_queue<quadruple_t&, std::vector<quadruple_t>, my_lessthan> q;

    for (int i=0;i<=dst;++i) {
        get<N_CONN>(ninfo[i]) = 0;
        get<N_WGHT>(ninfo[i]) = INT_MAX;
        get<N_IDX>(ninfo[i]) = i;
        get<N_VIS>(ninfo[i]) = false;
    }
    get<N_CONN>(ninfo[src]) = src;
    get<N_WGHT>(ninfo[src]) = 0;
    q.push(ninfo[src]);
    while (!q.empty()) {
        quadruple_t cur = q.top();
        q.pop();
        int& curnode = get<N_IDX>(cur);
        int& curdist = get<N_WGHT>(cur);

        if (curdist < get<N_WGHT>(ninfo[curnode]) || (get<N_VIS>(ninfo[curnode]))) {
            continue;
        }

        for (auto& cn: g[curnode]) {
            // cn has (dest_node, dist from curnode to dest_node)
            int& dest_node = cn.first;
            if (get<N_VIS>(ninfo[dest_node])) {
                continue;
            }
            quadruple_t& cn_info = ninfo[dest_node];
            int& cn_dist = get<N_WGHT>(cn_info);
            // look for a new lower distance to desination node
            if (curdist + cn.second < cn_dist) {
                cn_dist = curdist + cn.second;
                get<N_CONN>(cn_info) = curnode;
                if (dest_node != dst) {
                    q.push(cn_info);
                }
            }
        }
        get<N_VIS>(ninfo[curnode]) = true;
    }
    //cout << q.empty() << endl;

    static vector<int> ret(128);
    ret.resize(0);
    if (get<N_CONN>(ninfo[dst]) == 0) {
        ret.push_back(-1);
    } else {
        auto& curidx = dst;
        while (curidx != src) {
            ret.push_back(curidx);
            curidx =  get<N_CONN>(ninfo[curidx]);
        }
        ret.push_back(curidx);
    }
    return ret;
}

