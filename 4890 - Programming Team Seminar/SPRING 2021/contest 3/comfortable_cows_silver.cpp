/******************************************************************************
USACO 2021 February Contest, Silver
Problem 1. Comfortable Cows

We worked as a team to try and solve this problem. We got pretty close to how I
think the solution should be!

Our general strategy to solve this problem was to insert the cows placed into a
2D array with a large buffer, so that after each placement we could recursively
determine how many new cows would need to be added to make every cow 
uncomfortable. Our solution correctly 'finds' when a cow needs to be added, as
our output matches the right times when cows are added in the sample output.

However, it seems that our recursive function is not remembering when cows from
the past needed a cow to be placed. For example, lets say this is the input:

    . _ . _ . _ . _ .
    \ c \ c \ c \   \
    . _ . _ . _ . _ .
    \   \ c \ c \   \
    . _ . _ . _ . _ .
    \   \   \   \   \
    . _ . _ . _ . _ .

If we insert a new cow 'n' at location (2,2), then the grid looks like this

    . _ . _ . _ . _ .
    \ c \ c \ c \   \
    . _ . _ . _ . _ .
    \   \ c \ c \   \
    . _ . _ . _ . _ .
    \   \   \ n \   \
    . _ . _ . _ . _ .
    
Our code correctly reads that a cow 'u' needs to be added at (3,1):

    . _ . _ . _ . _ .
    \ c \ c \ c \   \
    . _ . _ . _ . _ .
    \   \ c \ c \ u \
    . _ . _ . _ . _ .
    \   \   \ n \   \
    . _ . _ . _ . _ .

But it does not 'remember' that a cow 'v' should also be added at (1,-1):
          v
    . _ . _ . _ . _ .
    \ c \ c \ c \   \
    . _ . _ . _ . _ .
    \   \ c \ c \ u \
    . _ . _ . _ . _ .
    \   \   \ n \   \
    . _ . _ . _ . _ .
    

This is presumably because our recurse function does not ever reach that spot,
even with the buffer we added.

We could not find a nice implementation of code for this, although the code that
we have now works better than our first iterations.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

//grid with large buffer to ignore boundaries
int arr[2000][2000] = {{0}};

//vector to keep track of outputs
vector<int> output;

vector<pair<int,int>> neighbors;

//will tell us how many cows need to be added for a specific insertion
int recurse (int x, int y, int depth) {
    
    int total=0;
    
    //neighbor x and y
    int nx, ny;
    
    //when we add a cow
    if (depth == 3 || arr[x][y] == 0) return 0;
    
    //1. check if this cow is comfortable
    //2. if it is, add the last neighbor into the arr
    if (arr[x+1][y] + arr[x-1][y] + arr[x][y+1] + arr[x][y-1] == 3) {
        if (!arr[x+1][y]) {
            arr[x+1][y] = 1;
            nx = x+1;
            ny = y;
            
            total += 1 + recurse (x+1,y, depth);
        }
        else if (!arr[x-1][y]) {
            arr[x-1][y] = 1;
            nx = x-1;
            ny = y;
            
            total += 1 + recurse (x-1,y, depth);
        }
        else if (!arr[x][y+1]) {
            arr[x][y+1] = 1;
            nx = x;
            ny = y+1;
            
            total += 1 + recurse (x,y+1, depth);
        }
        else { 
            arr[x][y-1] = 1;
            nx = x;
            ny = y-1;
            
            total += 1 + recurse (x,y-1, depth);
        }
        
        neighbors.emplace_back(make_pair(nx,ny));
        
    } else {
        total += recurse (x+1,y, depth+1);
        total += recurse (x-1,y, depth+1);
        total += recurse (x,y+1, depth+1);
        total += recurse (x,y-1, depth+1);
    }
    
    //if not, ignore and check neighbors
    
    //3. recurse on its neighbors (including the cow added)
    
    //4. remove the cow you added
    
    //5. return total
    return total;
}

int main()
{
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++) {
        
        int x, y;
        
        cin >> x >> y;
        
        x += 500;
        y += 500;
        
        arr[x][y] = 1;
        
        output.emplace_back(recurse(x,y,1));
        
        for (auto nbr : neighbors)
            arr[nbr.first][nbr.second] = 0;
        
    }
    
    for (auto x : output)
        cout << x << endl;
}

