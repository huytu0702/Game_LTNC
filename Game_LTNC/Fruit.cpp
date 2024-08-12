#include "Fruit.h"

bool fruit::init()
{
	string fruitPath = "assets/image/Strawberry.png";
	if (Load(fruitPath.c_str(), 2))
	{
		setPosition(650, rand() % (SCREEN_HEIGHT - LAND_HEIGHT - 50));
		return true;
	}
	return false;
}

void fruit::render() 
{
	Render(fruitRect.x, fruitRect.y, 0);
}

void fruit::update()
{
	fruitRect.x -= 2;
}

void fruit::setPosition(int x, int y)
{
	fruitRect.x = x;
	fruitRect.y = y;
}

void fruit::Free()
{
	free();
}

int fruit::getX()
{
	return fruitRect.x;
}

int fruit::getY()
{
	return fruitRect.y;
}

