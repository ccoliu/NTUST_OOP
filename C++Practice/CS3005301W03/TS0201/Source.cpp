//Name:¼B®a¦¨
//Date: 2022/3/8
//Last Update: 2022/3/8
//Problem statement:calculating average and deviation.

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

double devManipulate(vector<double> box, double avg, double n) 
{
	double de = 0;
	for (int j = 0; j < n; j++)
	{
		de += pow(box[j] - avg, 2);
	}
	return sqrt(de / n); //return the deviation back to the main function.
}

int main()
{
	double n;
	while (cin >> n)
	{
		double avg = 0;
		double dev = 0;
		vector<double> box;
		for (int i = 0; i < n; i++)
		{
			double num;
			cin >> num;
			avg += num;
			box.push_back(num); //store numbers to the vector and use it to calculate deviation.
		}
		avg /= n;
		dev = devManipulate(box, avg, n);
		cout << "Average:" << avg << "\t" << "Standard deviation:" << dev << endl;
	}
}