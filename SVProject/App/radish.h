#pragma once
#include "Crop.h"

// �з� :
// �뵵 :
// ���� :
class radish : public Crop
{
private:	// Static Var
public:		// Static Func
private:	// member Var

public:		//constructer destructer
	radish();
	~radish();

public:		// delete constructer
	radish(const radish& _Other) = delete;
	radish(const radish&& _Other) = delete;

public:		//delete operator
	radish& operator=(const radish& _Other) = delete;
	radish& operator=(const radish&& _Other) = delete;

public:		//member Func
	void Start() override;
	void DeathTask() override;
};

