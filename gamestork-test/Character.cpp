#include <UnitTest++.h>
#include <PathfinderFeat.h>

SUITE(CharacterTests) {

	TEST(FeatAbilityPrereqs) {
		PathfinderFeat feat("Test Feat", INTELLIGENCE, 15);
		CHECK(feat.meetsAbilityPrerequisite(17, INTELLIGENCE));
	}

	TEST(FeatAbilityTypePrereqs) {
		PathfinderFeat feat("Test Feat", INTELLIGENCE, 15);
		bool result = feat.meetsAbilityPrerequisite(17, STRENGTH);
		CHECK_EQUAL(false, result);
	}

	TEST(FeatClassPrereq) {
		PathfinderFeat feat("Test Feat", INTELLIGENCE, 15, 0,
			MEDIUM_ARMOR | HEAVY_ARMOR, FIGHTER | ROGUE);
		CHECK(feat.meetsClassPrerequisite(FIGHTER));
	}

	TEST(FeatProfiencyMatch) {
		PathfinderFeat feat("Test Feat", INTELLIGENCE, 15, 0,
			MEDIUM_ARMOR | HEAVY_ARMOR, FIGHTER | ROGUE);
		int prof = MEDIUM_ARMOR | HEAVY_ARMOR;
		CHECK(feat.meetsProficiencyPrerequisite(prof));
	}

	TEST(FeatProfiencyPartialMatch) {
		PathfinderFeat feat("Test Feat", INTELLIGENCE, 15, 0,
			MEDIUM_ARMOR | HEAVY_ARMOR, FIGHTER | ROGUE);
		int prof = HEAVY_ARMOR;
		CHECK(!feat.meetsProficiencyPrerequisite(prof));
	}
}