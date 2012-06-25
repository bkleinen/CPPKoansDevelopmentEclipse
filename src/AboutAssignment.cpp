/*
 * AboutAssignment.cpp
 *
 *  Created on: Jun 25, 2012
 *      Author: kleinen
 */

#include "AboutAssignment.h"
#include "Assert.h"
class List{
public:
	int i;
	List* next;
};

void assignmentCopies(){
	List l1;
	l1.i = 5;
	List l2 = l1;
	l2.i = 6;
	expectThat("l1 remains...",5,l1.i);
	expectThat("l2 has changed",6,l2.i);

}
void AboutAssignment::meditate() {
	assignmentCopies();
}

