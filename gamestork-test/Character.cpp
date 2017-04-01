#include <UnitTest++.h>
#include <PathfinderFeat.h>
#include <PathfinderSkill.h>
#include <PathfinderDwarf.h>
#include <PathfinderElf.h>
#include <PathfinderHuman.h>
#include <PathfinderCharacter.h>

SUITE(FeatAndSkillTests) {

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
		CHECK(feat.meetsProficiencyPrerequisite(prof));
	}

	TEST(SkillEquality) {
		PathfinderSkill skillA(DISABLE_DEVICE, "Disable Device", DEXTERITY, false);
		PathfinderSkill skillB(DISABLE_DEVICE, "Disable Device", DEXTERITY, true);
		CHECK(skillA == skillB);
	}

	TEST(SkillInequality) {
		PathfinderSkill skillA(DISABLE_DEVICE, "Disable Device", DEXTERITY, false);
		PathfinderSkill skillB(RIDE, "Ride", DEXTERITY, true);
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

SUITE(RaceTests) {
	TEST(RaceString) {
		PathfinderDwarf dwarf;
		PathfinderRace *race = &dwarf;
		CHECK_EQUAL("Dwarf", race->toString());
	}

	TEST(HumanBonus) {
		PathfinderHuman human(STRENGTH);
		PathfinderRace *race = &human;
		CHECK_EQUAL(2, race->abilityBonus(STRENGTH));
	}

	TEST(HumanNotBonus) {
		PathfinderHuman human(STRENGTH);
		PathfinderRace *race = &human;
		CHECK_EQUAL(0, race->abilityBonus(DEXTERITY));
	}
}

SUITE(CompleteCharacterTests) {
	TEST(DefaultAbilityNoRace) {
		PathfinderCharacter character(FIGHTER);
		CHECK_EQUAL(3, character.getAbilityScore(STRENGTH));
	}

	TEST(DefaultAbilityDwarf) {
		PathfinderCharacter character(FIGHTER);
		character.setRace(DWARF);
		CHECK_EQUAL(5, character.getAbilityScore(CONSTITUTION));
	}

	TEST(DefaultAbilityBonusDwarf) {
		PathfinderCharacter character(FIGHTER);
		character.setRace(DWARF);
		CHECK_EQUAL(-3, character.getAbilityBonusMod(CONSTITUTION));
	}


}