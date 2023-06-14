//Name:¼B®a¦¨
//Date: 2023/3/28
//Last Update: 2023/3/28
//Problem statement: Hot dog stand class demonstration

#include <iostream>
#include "HotDogStand.h"
using namespace std;

int main() {
	HotDogStand stand1("Stand1", 0);
	HotDogStand stand2("Stand2", 100);
	HotDogStand stand3("Stand3");
	stand1.justSold();
	stand2.justSold();
	stand3.justSold();
	stand1.print();
	stand2.print();
	stand3.print();
	std::cout << "Total Sold : " << HotDogStand::allStandSoldAmount() << std::endl;
	return 0;

}