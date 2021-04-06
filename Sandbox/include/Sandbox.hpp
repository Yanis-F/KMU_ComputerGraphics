#pragma once

#include <vector>
#include <imgui.h>

#include "CG/Game.hpp"
#include "CG/Color.hpp"
#include "CG/math/Vector2.hpp"
#include "CG/math/Vector3.hpp"

#include "CG/ui/imfilebrowser.h"
#include <CG/prefabs/PointLight.hpp>
#include <CG/prefabs/Cube.hpp>

class Sandbox : public CG::AGame {
public:
	Sandbox() : CG::AGame(CG::Vector2{ 1600, 900 }, "Sandbox")
	{}

	void start() override;
	void update(double deltatime) override;

private:
	void createAxis();
	void createGrid(const CG::Vector2 &size);
	void resetSimulation();

	auto getRandomSpawnPoint() -> CG::Vector3 const;

	void handleBallDragDrop();
private:
	CG::prefabs::PointLight *m_pointLight;

	float m_simulationTime;

	CG::AGameObject *m_dragging = nullptr;
};