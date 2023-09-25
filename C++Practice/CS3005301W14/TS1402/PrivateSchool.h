#pragma once
#include "School.h"

class PrivateSchool : public School
{
private:
	int dropout_wave = 0;
public:
	PrivateSchool(string name, int studentAmount) : School(name, studentAmount) {};
	void dropouts(float amount) override;
};
