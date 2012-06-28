/*
 * AboutTemplates.cpp
 *
 *  Created on: Jun 28, 2012
 *      Author: kleinen
 */

#include "AboutTemplates.h"
#include <string>
#include "Assert.h"

#define USEMACROxx
#ifdef USEMACRO
#define kleiner(a,b) (a<b)
#else
template<class E>
bool kleiner(E a,E b) {
	return a < b;
}
#endif

void AboutTemplates::meditate() {
	int a = 3, b = 5;
	double d = 3.2, c = 5.3;
	expectThat("template with integers",true,kleiner(a,b));
	expectThat("template with doubles",true,kleiner(d,c));
	string s1 = string("hallo"),s2 = string("berlin");
	expectThat("template with strings",false,kleiner(s1,s2));
}
