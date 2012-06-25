/*
 * AboutVectors.cpp
 *
 *  Created on: 14.03.2012
 *      Author: merlin
 *  see
 *  http://www.cplusplus.com/reference/stl/vector/
 */
#include "stdafx.h"
#include <vector>

#include "AboutVectors.h"
#include "Assert.h"

using namespace std;

vector<string> philosophers() {
	vector<string> philosopher(4);
	philosopher[0] = "Kant";
	philosopher[1] = "Plato";
	philosopher[2] = "Hume";
	philosopher[3] = "Kierkegaard";
	return philosopher;
}

void aboutUsingVectors() {
	vector<string> p = philosophers();
	expectThat("the third is...", string("Hume"), p[2]);

}

vector<double> aboutVectorInitialization() {
	vector<double> doubles(1000, -1.2); // initialisiert mit -1.2
	expectThat("now all values are initialized", -1.2, doubles[234]);
	return doubles;
}
void aboutFlexibleVectorSize() {

	vector<double> temps;
	temps.push_back(76.3); // fuegt am ende einen wert an
	temps.push_back(43.2);
	temps.push_back(65.2);

	double d[] = { 76.3, 43.2, 65.2 };
	for (unsigned int i = 0; i < temps.size(); ++i) {
		expectThat("vector push back", d[i], temps[i]);
	}
}

void AboutVectors::meditate() {
	aboutUsingVectors();
	aboutFlexibleVectorSize();
	aboutVectorInitialization();
}
