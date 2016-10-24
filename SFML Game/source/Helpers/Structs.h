#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

template <typename T>
struct Vec2 {
	T GetX() {
		return x;
	}
	T GetY() {
		return y;
	}
	T GetMagnitude() {
		return magnitude;
	}
	T GetDirection() {
		return direction;
	}
	void SetX(T X) {
		x = X;
		UpdateMagDir();
	}
	void SetY(T Y) {
		y = Y;
		UpdateMagDir();
	}
	void SetMagnitude(T m) {
		magnitude = m;
		UpdateXY();
	}
	void SetDirection(T d) {
		T revolutions = d / 360;
		T fractpart = revolutions - (int)revolutions;
		direction = fractpart * 360;
		UpdateXY();
	}
private:
	void UpdateXY() {
		x = (T)(magnitude * cos(direction * M_PI / 180));
		y = (T)(magnitude * sin(direction * M_PI / 180));
	}
	void UpdateMagDir() {
		direction = atan2(y, x);
		magnitude = hypot(x, y);
	}

	float direction = 0;
	T magnitude = 0;
	T x = 0;
	T y = 0;
};