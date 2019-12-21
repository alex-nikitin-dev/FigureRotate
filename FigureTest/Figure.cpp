#include "stdafx.h"
#include "Figure.h"
#define _USE_MATH_DEFINES
#include  <cmath>
#include <afxwin.h>
#include <vector>
using namespace std;


Figure::Figure(int x0,int y0,double r,double alfa)
{
	_points[0].x = x0;
	_points[0].y = y0;
	_r = r;
	_alfa = alfa;
	_SetCoords();
}
void Figure::Expand(double koef)
{
	_r *= koef;
	_SetCoords();
}
void Figure::Rotate(double alfa)
{
	_alfa += alfa;
	_SetCoords();
}
void Figure::SetCentre(CPoint point)
{
	_points[0] = point;
}
CPoint Figure::GetCentre()
{
	return CPoint(_points[0].x, _points[0].y);
}
double Figure::GetRadius()
{
	return _r;
}
void Figure::SetRadius(double radius)
{
	if (radius < 0) return;
	_r = radius;
}
void Figure::SetAngle(double alfa)
{
	_alfa = alfa;
}
CRect Figure::GetRectangle()
{
	CPoint topLeft;
	topLeft.x = round(GetCentre().x - sqrt(2)*_r);
	topLeft.y = round(GetCentre().y - sqrt(2)*_r);

	CPoint bottomRight;
	bottomRight.x = round(GetCentre().x + sqrt(2)*_r);
	bottomRight.y = round(GetCentre().y + sqrt(2)*_r);

	return CRect(topLeft, bottomRight);
}
CPoint Figure::GetCoord(double a, double b, double c, double alfa,double beta)
{
	CPoint result;
	result.x = round(sqrt(a*a + b*b)*_r * c*cos(atan(alfa) + beta+ _alfa) + _points[0].x);
	result.y = round(sqrt(a*a + b*b)*_r * c*sin(atan(alfa) + beta+ _alfa) + _points[0].y);
	return result;
}
void Figure::_SetCoords()
{
	_points[1] = GetCoord(1, 0, 1, 0, 0);
	_points[2] = GetCoord(1, 0, 3.5 / 4.5, 0, 0);
	_points[3] = GetCoord(0.5, 4, 1 / 4.5, 0.5 / 4, 0);
	_points[4] = GetCoord(0.5, 3, 1 / 4.5, 0.5 / 3, 0);
	_points[5] = GetCoord(1.5, 3, 1 / 4.5, 1.5 / 3, 0);
	_points[6] = GetCoord(1, 1, 4 / 4.5, 0, M_PI / 4);
	_points[7] = GetCoord(1, 1, 3 / 4.5, 0, M_PI / 4);
	_points[8] = GetCoord(3, 1.5, 1 / 4.5, 3 / 1.5, 0);
	_points[9] = GetCoord(4, 0.5, 1 / 4.5, 4 / 0.5, 0);
	_points[10] = GetCoord(3, 0.5, 1 / 4.5, 3 / 0.5, 0);
	_points[11] = GetCoord(1, 0, 1, 0, M_PI / 2);
	_points[12] = GetCoord(1, 0, 3.5 / 4.5, 0, M_PI / 2);

	_lines[0] = { _points[2],_points[12] };
	_lines[1] = { _points[4],_points[7] };
	_lines[2] = { _points[7],_points[10] };
	_lines[3] = { _points[1],_points[5] };
	_lines[4] = { _points[8],_points[11] };
	_lines[5] = { _points[6],_points[9] };
	_lines[6] = { _points[3],_points[6] };
}

void Figure::Show(CPaintDC *dc)
{
	for (int i = 0; i < 4; i++)
	{
		_alfa += i * M_PI / 2.0;
		_SetCoords();

		for (int i = 0; i < _countLines; i++)
		{
			CPoint arr[2]{ _lines[i].begin,_lines[i].end };
			dc->Polyline(arr, 2);
		}
	}
}

