/******************************************************************************

COCI 2020/2021 Contest #5
Task 3. Magenta

My solution was to create the graph using maps, where the edges are inserted
as described in the problem input. The general solution was to test several
conditions that could determine the winner.

Ultimate, I realized that the winner could be determined by brute force by
'asking' the right questions. For example, if Paula has no edges such that
she can move, she will lose the game (as she goes first). Likewise, if Paula
can move but Marin cannot, then Marin will lose on his turn.

Here are the basic test cases, unfinished as I ran out of time:
    
    (determines "can move" aka "does player immediately lose" status)
    # blue and magenta edges connected to Paula's starting position > 0
    # red and magenta edges connected to Marin's starting position > 0
    
    (determines "can not lose" status)
    depth of red edges on any of Paula's accessible paths > 1
    depth of red edges on any of Marin's accessible paths > 1
    
    (determines "can win" status)
    does Paula and Marin have a connected path?
    
    (determines "will win" status)
    is the path length even or odd? 
        even >> Paula
        odd >> Marin

From here it is easy to find if a player will win or if there is a draw. If
both players do not immediately lose, and both players can not lose, then the
game will draw. If any player can not lose, then they will win only if they
have the can win and will win statuses. These are hard to actually implement,
so that is why we got stuck coding it out.

Running Time: it takes O(n log(n-1)) time to run djikstra algorithm as there are
n nodes and n-1 possible edges. We will need to build a graph to find the depth
of red and blue edges for the "can not lose" status. Therefore, the running time
should be approximately O(n log n) or less.

*******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

int N;

typedef Node int;
Node P, M;

map<Node,vector<Node>> nbrs;
map<pair<Node,Node>,string> edges;
unordered_map<Node,int> dist_P;
unordered_map<Node,int> dist_M;
unordered_map<Node,Node> path_P;
unordered_map<Node,Node> path_M;

int main()
{
    ifstream input("input");

    input >> N;
    edge all[N];

    input >> P >> M;
    
    for (int i=0; i<N; i++) {
        int a, b;
        string c;
        
        input >> a >> b >> c;
        
        nbrs[a].emplace_back(b);
        nbrs[b].emplace_back(a);
        
        edges[makepair(a,b)] = c;
    }
    
    queue<Node> find_P_path;
    
    dist_P[P] = 0;
    find_P_path.push(P);
    
    while(!find_P_path.empty()) {
        Node x = find_P_path.front();
        find_P_path.pop();
        
        for (auto n : nbrs[x]) {
            dist_P[n] = dist_P[x] + 1;
            path_P[n] = x;
            find_P_path.push(n);
        }
    }
    
    queue<Node> find_M_path;
    
    dist_M[M] = 0;
    find_M_path.push(M);
    
    while(!find_M_path.empty()) {
        Node x = find_M_path.front();
        find_M_path.pop();
        
        for (auto n : nbrs[x]) {
            dist_M[n] = dist_M[x] + 1;
            path_M[n] = x;
            find_M_path.push(n);
        }
    }
    
}
