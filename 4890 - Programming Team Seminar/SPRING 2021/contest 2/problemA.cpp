/******************************************************************************

*******************************************************************************/
#include <cstdlib>
#include <iostream>
#include "stdio.h"
#include <algorithm>

using namespace std;

bool containsDigit(int number, int digit)
{
    while (number != 0)
    {
        int curr_digit = number % 10;
        if (curr_digit == digit) return true;
        number /= 10;
    }

    return false;
}

int main() {

    vector<int> cards;

    int n, s;

    cin >> n >> s;

    for (int i=0; i<n; i++) {
        string temp;
        cin >> temp;
        cards.emplace_back((int)temp);

        if ((temp.find('3') != npos) && (temp.find('4') != npos) 
         && (temp.find('7') != npos)) {
            reverse(temp.begin(), temp.end());

            for (int j=0; j < temp.length(); j++) {
                if (temp[j] == '6') {
                    temp[j] = '9'
                }
                if (temp[j] == '9') {
                    temp[j] = '6'
                }
            }

            cards.emplace_back((int)temp);
         }
    }
}