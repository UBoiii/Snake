#pragma once

#include <LedControl.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "Vec2.h"

#define INITIAL_SIZE 3
#define STARTING_POS_X 4
#define STARTING_POS_Y 4

class Snake
{
public:
	enum class Direction
	{
		left,
		right,
		up,
		down
	};
private:
	class Segment
	{
	public:
		Segment(LedControl& brd, int brdAddress, Vec2<uint8_t> pos);
		Vec2<uint8_t> GetPos() const { return pos; }
		void SetPos(const Vec2<uint8_t>& newPos);
		void Draw() const;
	private:
		LedControl* pbrd;
		int brdAddress;
		Vec2<uint8_t> pos;
	};
public:
	Snake(LedControl& brd, int brdAddress);
	~Snake();
	void SetDirection(Direction dir);
	void Grow();
	void Advance();
	Vec2<uint8_t> GetHeadPos() const { return snakeHead.GetPos(); }
	bool IsCollidingWithSelf() const;
	bool IsInside(const Vec2<uint8_t>& pos) const;
	void Draw() const;
private:
	LedControl& brd;
	const int brdAddress;
	uint8_t size; //Max size is 64 don't need more than a byte
	Segment* segStack = nullptr;
	Segment snakeHead;
	uint8_t indexOfHeadInStack;
	bool isGrowing = false;
	Direction snakeDirection;
	uint8_t nextSegmentRotation;
};