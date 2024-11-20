#pragma once
#include "Ball.h"
class BallSDL : public Ball
{
public:
	BallSDL();
	virtual ~BallSDL();

public:

	virtual void Init(const std::string& PathToTexture) override;


};

