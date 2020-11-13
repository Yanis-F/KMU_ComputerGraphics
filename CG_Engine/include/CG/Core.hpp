#pragma once

#include <memory>

#include "CG/Game.hpp"

namespace CG {

class Core
{
public:
	Core(std::unique_ptr<AGame> game);

	int run();

private:
	std::unique_ptr<AGame> m_game;
};

}