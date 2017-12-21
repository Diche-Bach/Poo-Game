#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void ClampToScreen(); // neither const nor by ref because this IS a mutator function
	void Draw(Graphics& gfx) const;  // const member function (non-mutator) because it does not change Dude or its member
	void Update(const Keyboard& kbd);
	int GetX() const;
	int GetY() const;
	static int GetWidth();
	static int GetHeight();
private:
	int x = 400;
	int y = 300;
	static constexpr int speed = 1;
	static constexpr int width = 20;
	static constexpr int height = 20;
};