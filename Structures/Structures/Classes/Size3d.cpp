#include <iostream>
#include "Size3d.h"

Size3d::Size3d(float width, float height, float depth)
	: m_width{ width }
	, m_height{ height }
	, m_depth{ depth }
{
	std::cout << "[Size3d] Se ha creado un Size3d \n";
}

Size3d::~Size3d()
{
	std::cout << "[Size3d] Destroy\n";
}

Size3d::Size3d(const Size3d& other) noexcept
	: m_width{ other.m_width }
	, m_height{ other.m_height }
	, m_depth{ other.m_depth }
{
	std::cout << "[Size3d] Copy\n";
}

Size3d& Size3d::operator = (const Size3d& other) noexcept 
{
	if (this != &other)
	{
		std::cout << "[Size3d] Copy assignment\n";
		m_width = other.m_width;
		m_height = other.m_height;
		m_depth = other.m_depth;
	}

	return *this;
}

Size3d::Size3d(Size3d&& other) noexcept
	: m_width{ std::exchange(other.m_width, 0) }
	, m_height{ std::exchange(other.m_height, 0) }
	, m_depth{ std::exchange(other.m_depth, 0) }
{

	std::cout << "[Size3d] Move\n";
}

Size3d& Size3d::operator = (Size3d&& other) noexcept
{
	if (this != &other)
	{
		std::cout << "[Size3d] Move assingment\n";
		m_width = std::exchange(other.m_width, 0);
		m_height = std::exchange(other.m_height, 0);
		m_depth = std::exchange(other.m_depth, 0);
	}
	
	return *this;
}

void Size3d::print() const noexcept
{
	std::cout << "[Size3d] width = " << m_width << "\t";
	std::cout << "height = " << m_height << "\t";
	std::cout << "depth = " << m_depth << "\n";
}