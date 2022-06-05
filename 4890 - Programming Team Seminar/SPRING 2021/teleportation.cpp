/******************************************************************************

USACO 2018 February Contest, Bronze
Problem 1. Teleportation

*******************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    
    int a, b, x, y, dist_n, dist_front, dist_back;
    
    cin >> a >> b >> x >> y;
    
    dist_n = abs(b - a);
    dist_front = abs(x - a) + abs(y - b);
    dist_back = abs(y - a) + abs(x - b);
    
    if (dist_n <= dist_front && dist_n <= dist_back) {
        cout << dist_n;
    } else if (dist_front <= dist_n && dist_front <= dist_back) {
        cout << dist_front;
    } else {
        cout << dist_back;
    }
    
    return 0;
}


