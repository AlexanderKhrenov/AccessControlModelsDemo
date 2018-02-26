// SystemBiba.cpp
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>
#include "SystemBiba.h"

bool SystemBiba::checkForREAD(Object& inObj)
{
	if (!useGrid) {
		if (currentSubject.getCategory() == inObj.getCategory()) {
			cout << "category check is ok" << endl;
			if (currentSubject.getSecLevel() <= inObj.getSecLevel()) {
				cout << "level check is ok" << endl;
				return true;
			}
			else {
				cout << "level check is NOT ok" << endl;
			}
		}
		cout << "category check is NOT ok" << endl;
		return false;
	}
	else {
		if (inObj.getCategory() % currentSubject.getCategory() == 0) {
			cout << "category check is ok" << endl;
			if (currentSubject.getSecLevel() <= inObj.getSecLevel()) {
				cout << "level check is ok" << endl;
				return true;
			}
			else {
				cout << "level check is NOT ok" << endl;
				return false;
			}
		}
		else {
			cout << "category check is NOT ok" << endl;
			return false;
		}
	}
}

bool SystemBiba::checkForWRITE(Object& inObj)
{
	if (!useGrid) {
		if (currentSubject.getCategory() == inObj.getCategory()) {
			cout << "category check is ok" << endl;
			if (currentSubject.getSecLevel() >= inObj.getSecLevel()) {
				cout << "level check is ok" << endl;
				return true;
			}
			else {
				cout << "level check is NOT ok" << endl;
			}
		}
		cout << "category check is NOT ok" << endl;
		return false;
	}
	else {
		if (inObj.getCategory() % currentSubject.getCategory() == 0) {
			cout << "category check is ok" << endl;
			if (currentSubject.getSecLevel() >= inObj.getSecLevel()) {
				cout << "level check is ok" << endl;
				return true;
			}
			else {
				cout << "level check is NOT ok" << endl;
				return false;
			}
		}
		else {
			cout << "category check is NOT ok" << endl;
			return false;
		}
	}
}