/*
 * Assert.h
 *
 *  Created on: 14.03.2012
 *      Author: merlin
 */
#ifndef ASSERT_H_
#define ASSERT_H_

#define ____ 'x'
#define _____  42
#define ______  42.42
#define _______  "42"
#define ________  false
#define _________  true

#include <string>
#include <iostream>
#include <typeinfo>
#include <vector>

#include "StopMeditating.h"
using namespace std;

template<class T>
void expectThatRaw(string message, T expected, T actual) {
	if (expected != actual) {
		reportUnmetExpectation(message, expected, actual);
	}
}
template<class T>
void expectThatNotRaw(string message, T expected, T actual) {
	if (expected == actual)
		reportUnmetExpectation(message, expected, actual);
}

template<class T>
void expectThat(string where, string message, T expected, T actual) {
	expectThatRaw(where + ": " + message, expected, actual);
}
template<class T>
void expectThat(string message, T expected, T actual) {
	expectThatRaw(message, expected, actual);
}

template<class T>
void expectThatNot(string message, T expected, T actual) {
	expectThatNotRaw(message, expected, actual);
}
#define XXXXX
#ifdef XXXXX
template<class T, class U>
void expectThat(string message, T expected, U actual) {
	expectThatRaw(
			message + " (expected was casted to " + typeid(U).name() + ")",
			U(expected), actual);
}

template<class T, class U>
void expectThatNot(string message, T expected, U actual) {
	expectThatNotRaw(
			message + " (expected was casted to " + typeid(U).name() + ")",
			U(expected), actual);
}
#endif

template<class T>
void reportUnmetExpectation(string message, T expected, T actual) {
	cout << "Expectation Failed: " << message << endl;
	cout << "Expected: " << expected << ", but was: " << actual << endl;
	if (QUIT_ON_UNMET_EXPECTATION)
		throw StopMeditating();
}
template<class E>
void reportUnmetExpectation(string message, vector<E> expected,
		vector<E> actual) {
	cout << "Expectation Failed: " << message << endl;
	cout << "Expected: ";
	appendVector(cout, expected);

	cout << ", but was: " << endl;
	appendVector(cout, actual);
	cout << endl;
	if (QUIT_ON_UNMET_EXPECTATION)
		throw StopMeditating();
}

template<class E>
void appendVector(ostream &os, vector<E> v) {
	os << "[";
	string delim = "";
	for (unsigned int i = 0; i < v.size(); ++i) {
		os << delim;
		os << v[i];
		delim = ", ";
	}
	os << "]";
}
#endif /* ASSERT_H_ */
