#pragma once
#include "Ball.h"
class BallRaylib : public Ball
{
public:
	BallRaylib();
	virtual ~BallRaylib();

public:

	virtual void Init(const std::string& PathToTexture) override;

};

