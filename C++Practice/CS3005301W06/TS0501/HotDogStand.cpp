//Name:¼B®a¦¨
//Date: 2023/3/28
//Last Update: 2023/3/28
//Problem statement: Hot dog stand class demonstration

#include "HotDogStand.h"
#include <iostream>

int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand()
{
}

HotDogStand::HotDogStand(const char* id)
{
	// Constructor with one parameter
	standId = new char[strlen(id) + 1]; // Dynamically allocate memory for the stand ID
	strcpy(standId, id); // Copy the stand ID to the dynamically allocated memory
	hotDogSellAmount = 0; // Initialize the amount of hot dogs sold to 0
}

HotDogStand::HotDogStand(const char* id, int amount)
{
	// Constructor with two parameters
	standId = new char[strlen(id) + 1]; // Dynamically allocate memory for the stand ID
	strcpy(standId, id); // Copy the stand ID to the dynamically allocated memory
	hotDogSellAmount = amount; // Initialize the amount of hot dogs sold to the given amount
	totalSellAmount += amount; // Add the amount sold to the total amount sold by all stands
}

HotDogStand::~HotDogStand()
{
}

void HotDogStand::justSold()
{
	// Increment the amount of hot dogs sold by this stand and by all stands
	hotDogSellAmount++;
	totalSellAmount++;
}

void HotDogStand::print()
{
	// Print the stand ID and the amount of hot dogs sold by this stand
	std::cout << standId << " " << hotDogSellAmount << std::endl;
}

int HotDogStand::thisStandSoldAmount()
{
	// Return the amount of hot dogs sold by this stand
	return hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount()
{
	// Return the total amount of hot dogs sold by all stands
	return totalSellAmount;
}