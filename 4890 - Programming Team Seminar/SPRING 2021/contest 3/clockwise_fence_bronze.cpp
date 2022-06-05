/******************************************************************************

USACO 2021 February Contest, Bronze
Problem 3. Clockwise Fence

This was a suprisingly difficult problem for the Bronze set. Neither me or Ben
could figure out exactly a solution, although this implementation works
something like this: for each input string, count up how many times the fence
is placed north, south, east, or west. Our idea was to then find the halfway
mark of the fence and determine based on the frequencies if the fence was to be
clockwise or counter-clockwise. 

I ran into problems determining exactly what 
this code would be, but the basic premise is if I take 30 steps to make a fence
knowing that I will return back to the origin, then after 15 steps I will have
to move on average the opposite way to return to my spot. So if I move north
10 times and west 5 times, then on the way back I will move south 10 times and
east 5 times.

The problem with this solution is that this does not determine the direction 
that the fence is going. There is probably a way to iteratively determine the
direction, but we couldn't think of a solution.

Running Time: it takes O(n) time to read in data, O(s) time to find the solution
where s is the length of the string. Therefore the runtime is O(ns), but since
the values are so small, this is barely noticable.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

vector<string> output;

int main()
{
    int n;
    
    //1 <= N <= 20
    cin >> n;

    stringstream ss;

    for (int i=0; i<n; i++) {
        string line;
        cin >> line;
        
        //verticle
        char v;
        char h;
        
        int count;
        map<char,int> freq;
        
        freq['N'] = 0;
        freq['S'] = 0;
        freq['E'] = 0;
        freq['W'] = 0;
        
        char v = '';
        char h = '';
        
        for (int c=0; c<line.length()/2; c++) {
            
            char direction = line[c];
            
            if (direction == 'N' || direction == 'S')
                if (v == '') {
                    v = direction;
                }
            else
                if (h == '')
                    h = direction;
            
            freq[direction]++;
        }
        
        if (freq['N'] < freq['S'] && freq['W'] < freq['E'])
            if (freq['S'] < freq['E'] || (freq['S'] == freq['E'] && ))
                output.emplace_back("CCW");
            else if (freq['S'] < freq['E'])
        else if (freq['N'] < freq['S'] && freq['W'] < freq['E'])
            output.emplace_back("CW");
        else if (freq['N'] < freq['S'] && freq['W'] < freq['E'])
            output.emplace_back("CW");
        else if (freq['N'] < freq['S'] && freq['W'] < freq['E'])
            output.emplace_back("CCW");
        else
            output.emplace_back("WOOPS")
            
    }

    for (auto x : output)
        cout << x << endl;

    return 0;
}

