/*

A cafeteria table consists of a row of N seats, numbered from 1 to N from left to right.
Social distancing guidelines require that every diner be seated such that K seats to their left and K seats to their right 
(or all the remaining seats to that side if there are fewer than K) remain empty.

There are currently M diners seated at the table, the ith of whom is in seat Si. 
No two diners are sitting in the same seat, and the social distancing guidelines are satisfied.

Determine the maximum number of additional diners who can potentially sit at the table without 
social distancing guidelines being violated for any new or existing diners, 
assuming that the existing diners cannot move and that the additional diners will cooperate 
to maximize how many of them can sit down.

Sample test case #1
N = 10
K = 1
M = 2
S = [2, 6]

Expected Return Value = 3

In the first case, the cafeteria table has N=10 seats, with two diners currently at seats 2 and 6 respectively.
The table initially looks as follows, with brackets covering the K=1 
seat to the left and right of each existing diner that may not be taken.

1 2 3 4 5 6 7 8 9 10
[   ]   [   ]

Three additional diners may sit at seats 4, 8, and 10 without violating the social distancing guidelines.


#####################################################################################################################################

Solutions:

[1]
**** Caveat is this solution is higher in time complexity ****
S is sorted.
From Si, loop and count backwards until it hits the previous occupied seat without violating the distance K.  
Then do the same thing from N to M without violating the distance K.


[2]
S is sorted.
Optimal solution instead of looping backwards, calculate the difference between Si and previous occupied distance. 
If Si is first item then the previous is 1; then divide with distance K+1. 

maxAdditional += (occupied - prev_right)/(K+1);

*/

#include "Cafeteria.h"
#include <iostream>

using namespace std;
// Write any include statements here

namespace NS_CAFETERIA {
  
  long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
    // Write your code here
    
    long long maxAdditional = 0;
    
    /* First Solution */
    
    stable_sort(S.begin(), S.end());
    for (long long i = 0; i < M; i++) {
      
      long long occupied = S[i];
      long long prev_right = i-1 >= 0 ? (S[i-1] + (K+1)) : 1; // default to 1 for first item in the vector S.

      maxAdditional += (occupied - prev_right)/(K+1);
      /*
      while ((occupied - prev_right) >= (K+1)) {
        maxAdditional++;
        occupied -= K+1;
      }*/
      
    }

    // the rest of M to N
    long long last_occupied = S[M-1];
    cout << " (N - last_occupied)/K+1 " << ((N - last_occupied)/(K+1)) << " ";
    maxAdditional += (N - last_occupied)/(K+1);

    /*
    while ((N - last_occupied) >= (K+1)) {
      maxAdditional++;
      N -= K+1;
    }*/

    return maxAdditional;
  }

  void test () {

    long long max;
    long long N = 10;
    long long K = 1;
    int M = 2;
    vector <long long> S = {2, 6}; 
    /*
      1 2 3 4 5 6 7 8 9 10
      [   ]   [   ]
      
      expected output is 3. 
    */
    max = getMaxAdditionalDinersCount(N, K, M, S);
    cout << " max: " << max << endl;


    N = 15;
    K = 2;
    M = 3;
    S = {11, 6, 14};
    /*
      1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
            [                           ] 
      expected output is 1
    */
    max = getMaxAdditionalDinersCount(N, K, M, S);
    cout << " max: " << max << endl;
  }
}