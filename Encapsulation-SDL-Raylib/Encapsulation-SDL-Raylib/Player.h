#pragma once

#include "Entity.h"

class Player : public Entity
{
public:

	Player();
	virtual ~Player();

protected:

	int mPoints;

	int mUpKey;
	int mDownKey;

public:

	int GetPoints() const { return mPoints; }
	int IncrementPoints(int value) { return mPoints += value; }
	void SetControlKeys(int UpKey, int DownKey);

	virtual void Update() override;
	virtual void Move(float X, float Y) override;

};

