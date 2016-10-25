#ifndef GOLFBALL_H
#define GOLFBALL_H

class GolfBall
{
public:
	float x,y;
	float height;
	float distance;
	float currentHeight;
	GolfBall() : currentHeight(0.0f) , x(0.0f) , y(0.0f) , distance(0.0f), height(0.0f) {};
	
	float getHeight() { return height; };
	float getX() { return x; };
	float getY() { return y; };
	float getDistance() { return distance; };
	float getCurrentHeight() { return currentHeight; };
	
	float setHeight(float iHeight ) { height = iHeight; };
	float setX( float iX ) { x = iX; };
	float setY( float iY ) { y= iY; };
	float setDistance( float iDistance ) { distance = iDistance; };
	float setCurrentHeight( float iCurrentHeight ) { currentHeight = iCurrentHeight; };
};

#endif
