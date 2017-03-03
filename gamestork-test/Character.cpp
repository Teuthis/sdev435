#include <UnitTest++.h>
#include <PathfinderFeat.h>
#include <PathfinderSkill.h>

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

	TEST(SkillEquality) {
		PathfinderSkill skillA("Pickpocketing", DEXTERITY, false);
		PathfinderSkill skillB("Pickpocketing", DEXTERITY, true);
		CHECK(skillA == skillB);
	}

	TEST(SkillInequality) {
		PathfinderSkill skillA("Pickpocketing", DEXTERITY, false);
		PathfinderSkill skillB("Pickpocket", DEXTERITY, false);
		CHECK(skillA != skillB);
	}

	TEST(FeatEquality) {
		PathfinderFeat featA("Test Feat");
		PathfinderFeat featB("Test Feat", CHARISMA, 14);
		CHECK(featA == featB);
	}
	
	TEST(FeatInequality) {
		PathfinderFeat featA("Charge");
		PathfinderFeat featB("Charm", CHARISMA, 14);
		CHECK(featA != featB);
	}

}