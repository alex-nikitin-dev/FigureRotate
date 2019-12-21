#pragma once
#define _USE_MATH_DEFINES
#include <vector>
using namespace std;
class Figure
{
public:
	Figure(int x0, int y0, double r, double alfa);
	void Show(CPaintDC *dc);
	void Expand(double koef);
	void Rotate(double alfa);
	void SetCentre(CPoint point);
	CPoint GetCentre();
	double GetRadius();
	void  SetRadius(double radius);
	void  SetAngle(double alfa);
	CRect GetRectangle();
	static const  int _countPoints = 12;
	static const  int _countLines = 7;
private:
	struct Line
	{
		CPoint begin;
		CPoint end;
	};
	CPoint GetCoord(double a, double b, double c, double alfa, double beta);
	CPoint _points[_countPoints];
	Line _lines[_countLines];
	double _r;
	double _alfa;
	void _SetCoords();
};
