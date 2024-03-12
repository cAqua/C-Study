#pragma once

template <typename T>
void myswap(T& a, T& b) {
	T Temp = a;
	a = b;
	b = Temp;
}