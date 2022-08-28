#pragma once
#include "Crop.h"

// 분류 :
// 용도 :
// 설명 :
class potato : public Crop
{
private:	// Static Var
public:		// Static Func
private:	// member Var

public:		//constructer destructer
	potato();
	~potato();

public:		// delete constructer
	potato(const potato& _Other) = delete;
	potato(const potato&& _Other) = delete;

public:		//delete operator
	potato& operator=(const potato& _Other) = delete;
	potato& operator=(const potato&& _Other) = delete;

public:		//member Func
	void Start() override;
	void DeathTask() override;
};

