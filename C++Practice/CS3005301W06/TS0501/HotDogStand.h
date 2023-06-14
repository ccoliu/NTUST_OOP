//Name:¼B®a¦¨
//Date: 2023/3/28
//Last Update: 2023/3/28
//Problem statement: Hot dog stand class demonstration

#pragma once

class HotDogStand
{
public:
	HotDogStand();
	HotDogStand(const char *id);
	HotDogStand(const char *id, int amount);
	~HotDogStand();
	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount();
private:
	char *standId;
	int hotDogSellAmount;
	static int totalSellAmount;
};

