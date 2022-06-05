/******************************************************************************

USACO 2019 US Open Contest, Bronze
Problem 2. Milk Factory

*******************************************************************************/
#include <iostream>
//#include <map>
using namespace std;

int r[101];

//map<int,int> directions;

int main()
{
    int N;
    
    cin >> N;
    
    for (int i=0; i<101; i++) {
        r[i] = 0;
    }
    
    for (int i=1; i<N; i++) {
        
        int x, y;
        
        cin >> x >> y;
        
        //count how many are receiving
        r[y]++;
        
        //x is pointing to y, who is receiving
        //directions[x] = y;
    }
    
    int candidate = 0;
    int position;
    
    for (int i=1; i<=100; i++) {
        if (r[i] != 0) {
            candidate++;
            position = i;
        }
        
        if (candidate>1) break;
    }
    
    //if more than one candidate is receiving then cannot send out
    if (candidate=1) 
        cout << position;
    else
        cout << -1;
    
    return 0;
}
