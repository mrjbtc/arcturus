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

*/

#include "DirectorOfPhotography.h"
#include <iostream>
#include <string>

using namespace std;

namespace NS_DIRECTOR_OF_PHOTOGRAPHY {
	int getArtisticPhotographCount(int N, string C, int X, int Y) {
		
		int count = 0, len = C.length();

		for (int i = 0; i < len; i++) {
			
			if (C[i] == '.') continue;


		}

		return count;
	}

	void test() {
		int N, X, Y, count = 0;
		string C;

		/* test case 1 */
		N = 5;
		C = "APABA";
		X = 2;
		Y = 3;

		count = getArtisticPhotographCount(N, C, X, Y);
		cout << " count " << count << endl;

		/* test case 2 */
		N = 5;
		C = "APABA";
		X = 2;
		Y = 3;

		count = getArtisticPhotographCount(N, C, X, Y);
		cout << " count " << count << endl;

		/* test case 3 */
		N = 8;
		C = ".PBAAP.B";
		X = 1;
		Y = 3;

		count = getArtisticPhotographCount(N, C, X, Y);
		cout << " count " << count << endl;

	}
}