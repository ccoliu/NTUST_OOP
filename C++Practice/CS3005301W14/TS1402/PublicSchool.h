#pragma once
#include "School.h"

class PublicSchool : public School
{
private:
	float growing_rate = 0.05;
public:
	PublicSchool(string name, int studentAmount) : School(name , studentAmount) {};
	void apply_growth();
	void dropouts(float amount) override;
};