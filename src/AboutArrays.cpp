/*
 * AboutArrays.cpp
 *
 *  Created on: 14.03.2012
 *      Author: merlin
 */
#include "stdafx.h"
#include "AboutArrays.h"
#include "Assert.h"

void aboutArrayDeclarationAndUsage() {

	// there are two ways to allocate memory for arrays:

	int a[10]; // space allocated on heap - no need to call new

	int *b;
	b  = new int[10]; // space allocated on heap
	delete[] b; // memory needs to be freed with a call to delete!

	b = a; // still, both are technically pointers.
	*b = 2;
	expectThat("now the first element of a has changed",2,a[0]);
	*(b+4) = 43;
	expectThat("and the fifth",43,a[4]);
}

void AboutArrays::meditate() {
	aboutArrayDeclarationAndUsage();

}

