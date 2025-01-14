#include <CG/components/CustomPhysicResolver.hpp>
#include <CG/components/Rigidbody.hpp>
#include <CG/components/renderer/LineRenderer.hpp>
#include <CG/components/Transform.hpp>

#include "GameObjects/links/Rod.hpp"

Rod::Rod(CG::GameObject &a, CG::GameObject &b, double length) : m_obj1(a), m_obj2(b), m_length(length)
{
	setTag<"simulation_object"_hs>();

	addComponent<CG::CustomPhysicResolver>([this]() {resolve(); });

	addComponent<CG::LineRenderer>().material.color = CG::Color::Grey();
}


void Rod::resolve() noexcept
{
	auto p1 = m_obj1.getComponent<CG::Transform>().position;
	auto p2 = m_obj2.getComponent<CG::Transform>().position;

	auto im1 = m_obj1.getComponent<CG::Rigidbody>().getInvertMass();
	auto im2 = m_obj2.getComponent<CG::Rigidbody>().getInvertMass();
	auto imTotal = im1 + im2;

	auto distance = CG::Vector3::distance(p1, p2);

	auto p1_p2 = (p2 - p1).normalized();
	auto movePerIm = p1_p2 * (distance - m_length) / imTotal;

	m_obj1.getComponent<CG::Transform>().position += movePerIm * im1;
	m_obj2.getComponent<CG::Transform>().position += -movePerIm * im2;
}

void Rod::lateUpdate(double) 
{
	auto &lr = getComponent<CG::LineRenderer>();
	lr.from = m_obj1.getComponent<CG::Transform>().position;
	lr.to = m_obj2.getComponent<CG::Transform>().position;
}
