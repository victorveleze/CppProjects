#pragma once

class Size3d
{
public:
	Size3d(float width = 0, float height = 0, float depth = 0);
	~Size3d();
	Size3d(const Size3d& other) noexcept;
	Size3d& operator = (const Size3d& other) noexcept;
	Size3d(Size3d&& other) noexcept;
	Size3d& operator = (Size3d&& other) noexcept;

	void print() const noexcept;

private:
	float m_width;
	float m_height;
	float m_depth;
};
