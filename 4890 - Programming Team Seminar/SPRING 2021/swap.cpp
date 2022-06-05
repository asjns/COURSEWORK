/******************************************************************************

USACO 2020 February Contest, Bronze
Problem 3. Swapity Swap

*******************************************************************************/
#include <iostream>
using namespace std;

//maximum cows is 100, so have empty array for all of them
int cows[101];

int main()
{
    //variables in the problem
    int N, K, a1, a2, b1, b2, tmp;
    
    //read in input
    cin >> N >> K;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    
    //initial order
    for (int i=1; i<=N; i++)
        cows[i] = i;
    
    //for k cycles
    for (int k=0; k<K; k++) {
        
        //reverse order of elements between A1 and A2
        for (int i=0; i<(a2-a1+1)/2; i++) {
            tmp = cows[a1+i];
            cows[a1+i] = cows[a2-i];
            cows[a2-i] = tmp;
        }
        
        //reverse order of elements between B1 and B2
        for (int j=0; j<(b2-b1+1)/2; j++) {
            tmp = cows[b1+j];
            cows[b1+j] = cows[b2-j];
            cows[b2-j] = tmp;
        }
    
    }
    
    //print out output
    for (int i=1; i<=N; i++)
        cout << cows[i] << endl;
    
    return 0;
}

