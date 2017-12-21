#pragma once

#include "Graphics.h"
#include "Dude.h"

class Poo
{
public:
	void Init(int x_init, int y_init, int vx_init, int vy_init);
	void Update(); // neither const nor by ref because this IS a mutator function
	bool TestCollision( const Dude& dude ) const; // call by const ref because function is read only
	void Draw(Graphics& gfx) const; // const member function (non-mutator) because it does not change Poo or its members
	// bool IsEaten() const; // Getter function, gets the value of a member variable
private:
	int x;  
	int y;
	int vx;
	int vy;
	static constexpr int width = 24;
	static constexpr int height = 24;
	/*
	bool isEaten = false; // original became inaccessible when made private required the getter above
	*/
	bool initialized = false;
};