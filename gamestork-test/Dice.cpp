//-----------------------------------------------------------------------------
/**
File: Dice.cpp
System: Gamestork RPG Character Generator
License: LGPL
(c) Chris Aiken 2017

Description: Unit tests for dice rolling simulator
*/
//-----------------------------------------------------------------------------

#include <UnitTest++.h>
#include "DiceRoller.h"

SUITE(DiceTests) {

	TEST(SumCheck) {
		DiceRoller roller;
		int foursixes = roller.getRollSum(4, D6);
		int threetens = roller.getRollSum(3, D10);

		CHECK(foursixes >= 4 && foursixes <= 24 
			&& threetens >= 3 && threetens <= 30);
	}

	TEST(VectorCheck) {
		DiceRoller roller;
		auto fivefours = roller.getRollValues(5, D4);

		CHECK_EQUAL(5, fivefours.size());
	}

	TEST(RollsCheck) {
		DiceRoller roller;
		auto fivefours = roller.getRollValues(5, D4);

		bool correct = true;
		for (int i = 0; i < fivefours.size(); ++i) {
			if (fivefours[i] < 1 || fivefours[i] > 4) {
				correct = false;
			}
		}

		CHECK(correct);
	}
}