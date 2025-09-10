/*

A photography set consists of N  cells in a row, numbered from 1 to N in order, and can be represented by a string C
of length N. Each cell i is one of the following types (indicated by Ci, the ith character of C):

If Ci = “P”, it is allowed to contain a photographer
If Ci = “A”, it is allowed to contain an actor
If Ci = “B”, it is allowed to contain a backdrop
If Ci = “.”, it must be left empty

A photograph consists of a photographer, an actor, and a backdrop, such that each of them is placed in a valid cell, 
and such that the actor is between the photographer and the backdrop. 
Such a photograph is considered artistic if the distance between the photographer and the actor is between X and Y 
cells (inclusive), and the distance between the actor and the backdrop is also between X and Y cells (inclusive). 

The distance between cells i and j is ∣i−j∣ (the absolute value of the difference between their indices).

Determine the number of different artistic photographs which could potentially be taken at the set. 
Two photographs are considered different if they involve a different photographer cell, actor cell, and/or backdrop cell.

##################################################

Sample test case #1
N = 5
C = APABA
X = 1
Y = 2
Expected Return Value = 1

##################################################

Sample test case #2
N = 5
C = APABA
X = 2
Y = 3
Expected Return Value = 0

##################################################

Sample test case #3
N = 8
C = .PBAAP.B
X = 1
Y = 3
Expected Return Value = 3

##################################################

Sample Explanation

In the first case, the absolute distances between photographer/actor and actor/backdrop must be between 1 and 2.
The only possible photograph that can be taken is with the 3 middle cells, and it happens to be artistic.

In the second case, the only possible photograph is again taken with the 3 middle cells. However, as the distance requirement is between
2 and 3, it is not possible to take an artistic photograph.

In the third case, there are 4 possible photographs, illustrated as follows:

.P.A...B
.P..A..B
..BA.P..
..B.AP..


Solution:
  [1] Identify each indexes of valid characters such as P, A, and B.
  [2] For PAB permutations, loop throuch each indexes and make sure distance from P - A and A - B are between X - Y.
  [3] Do the same thing for BAP permutations, and increment for each valid permutations.
  
*/

#include "DirectorOfPhotography.h"
#include <iostream>


using namespace std;

namespace NS_DIRECTOR_OF_PHOTOGRAPHY {
	

	int getArtisticPhotographCount(int N, string C, int X, int Y) {
		
		int count = 0;
		vector<int> P, A, B;

		for (int i = 0; i < N; i++) {
			char c = C[i];
			if (c == 'P') {
				P.push_back(i);
			}
			if (c == 'A') {
				A.push_back(i);
			}
			if (c == 'B') {
				B.push_back(i);
			}

		}

		// P A B permutations
		for (int p : P) {
			for (int a: A) {
				if (p > a) {
					continue;
				}
				for (int b: B) {

					if (a > b) {
						continue;
					}
					int distance_pa = a-p;
					int distance_ab = b-a;

					// validate distance for P - A between X - Y, as well as for A - B
					if (distance_pa >= X && distance_pa <= Y && distance_ab >= X && distance_ab <= Y) {
						if (a > p && b > a) {
							count++;
							cout << p << " " << a << " " << b << endl;
						}
					}
					
				}
			}
		}

		// B A P permutations
		for (int b: B) {
			for (int a: A) {
				if (b > a) {
					continue;
				} 
				for (int p : P) {
					if (a > p) {
						continue;
					}
					int distance_pa = p-a;
					int distance_ab = a-b;

					// validate distance for B - A etween X - Y, as well as for A - P
					if (distance_pa >= X && distance_pa <= Y && distance_ab >= X && distance_ab <= Y) {
						if (a > b && p > a) {
							count++;
							cout << b << " " << a << " " << p << endl;
						}
					}
				}
			}
		} 

		return count;
	}

	void test() {
		int N, X, Y, count = 0;
		string C;

		/* test case 1 */
		N = 5;
		C = "APABA";
		X = 1;
		Y = 3;

		cout << "C: " << C << endl;
		count = getArtisticPhotographCount(N, C, X, Y);
		cout << " count " << count << endl;

		/* test case 2 */
		N = 5;
		C = "APABA";
		X = 2;
		Y = 3;

		cout << "C: " << C << endl;
		count = getArtisticPhotographCount(N, C, X, Y);
		cout << " count " << count << endl;

		/* test case 3 */
		N = 8;
		C = ".PBAAP.B";
		X = 1;
		Y = 3;

		cout << "C: " << C << endl;
		count = getArtisticPhotographCount(N, C, X, Y);
		cout << " count " << count << endl;

	}
}