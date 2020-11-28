#pragma once

#include "CG/internal/Drawable.hpp"
#include "CG/Color.hpp"

namespace CG {

class PlaneRenderer {
public:
	// TODO: static shader

	PlaneRenderer(const Color &colors);

	inline void draw() const noexcept { m_drawable.draw(); }
private:
	Drawable m_drawable;
};

}