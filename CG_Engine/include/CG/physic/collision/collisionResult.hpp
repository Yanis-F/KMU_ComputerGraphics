#pragma once

#include "CG/math/Vector3.hpp"

namespace CG {

struct CollisionResult {

	// normal of the surface of object 2
	Vector3 hitNormal;

	Vector3 hitPosition;

	// depth of the penetration 
	double penetration;
};

}