//Name:¼B®a¦¨
//Date: 2022/3/30
//Last Update: 2022/3/30
//Problem statement: Creating Point class

class Point
{
private:
	int* pos = new int[2];

public:
	void Set(int x, int y);
	void Move(int x, int y);
	void Rotate();
	void Reflect();
	const int GetHorizontal();
	const int GetVertical();
	Point newPoint(Point& point);
;	~Point();
	Point();
};
