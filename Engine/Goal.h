#pragma once
#include "Graphics.h"
#include "Dude.h"


class Goal
{
public:
	Goal(int x_init, int y_init)
		:
		x(x_init),
		y(y_init)
	{}
	void Draw(Graphics& gfx) const
	{
		gfx.DrawRectDim(x, y, dimension, dimension, c);
	}
	bool TestCollision(const Dude& dude) const
	{
		const int duderight = dude.GetX() + dude.GetWidth();
		const int dudebottom = dude.GetY() + dude.GetHeight();
		const int goalright = x + dimension;
		const int goalbottom = y + dimension;

		return duderight >= x &&
			dude.GetX() <= goalright &&
			dudebottom >= y &&
			dude.GetY() <= goalbottom;
	}
	void Respawn(int x_respwn, int y_respwn)
	{
		x = x_respwn;
		y = y_respwn;
	}
	void UpdateColor()
	{
		if (colorIncreasing)
		{
			if (c.GetR() >= 253)
			{
				colorIncreasing = false;
			}
			else
			{
				c = Color(c.GetR() + 2, c.GetG() + 4, c.GetB() + 4);
			}

		}
		else
		{
			if (c.GetR() <= 127)
			{
				colorIncreasing = true;
			}
			else
			{
				c = Color(c.GetR() - 2, c.GetG() - 4, c.GetG() - 4);
			}
		}

	}
private:
	static constexpr int dimension = 20;
	Color c = {127, 0, 0};
	bool colorIncreasing = true;

	int x;
	int y;	
};