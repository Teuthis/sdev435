#pragma once
#include "PathfinderClass.h"
class PathfinderRogue :
	public PathfinderClass
{
public:
	PathfinderRogue();
	~PathfinderRogue();

	/// Returns a string representation of the object
	/// @return The object as string
	std::string toString() const { return "Rogue"; }

	/// Returns a collection of strings representing class features
	/// @return The list of features
	std::vector<std::string> getClassFeatures() const;

	/// Gets the information to display in the Spells/Magic section
	/// @return A vector of strings to populate the Magic box
	std::vector<std::string> getMagic() const;

};

