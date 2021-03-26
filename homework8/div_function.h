#pragma once
template <class T>
T Div(T divisor, T dividend)
{
	if (dividend == 0)
		throw "Division By Zero";
	return divisor / dividend;
}
