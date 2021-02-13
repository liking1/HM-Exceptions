#pragma once
#include <iostream>
#include <string>
#include<tuple>
using namespace std;

class Triangle
{
public:
	template <typename T>Triangle(const tuple<T, T, T>& tuple);
	template <typename T>Triangle(const T& firstSide, const T& secondSide, const T& thirdSide);
	float area() const;
	float length() const;
	friend ostream& operator<<(ostream& os, const Triangle& obj);
	template <typename T> void setTriangle(const T& firstSide, const T& secondSide, const T& thirdSide);
private:
	  tuple<float, float, float> tuple;
};

template<typename T>
inline void Triangle::setTriangle(const T& firstSide, const T& secondSide, const T& thirdSide)
{
	if (firstSide <= 0) {
		throw (double)firstSide;
	}
	else if (firstSide >= secondSide + thirdSide) {
		throw string("Can't create a form from this side : " + to_string(firstSide));
	}
	else {
		get<0>(tuple) = firstSide;
	}
	if (secondSide <= 0) {
		throw (double)secondSide;
	}
	else if (secondSide >= thirdSide + firstSide) {
		throw string("Can't create a form from this side : " + to_string(secondSide));
	}
	else {
		get<1>(tuple) = firstSide;
	}
	if (thirdSide <= 0) {
		throw (double)firstSide;
	}
	else if (thirdSide >= secondSide + firstSide) {
		throw string("Can't create a form from this side : " + to_string(thirdSide));
	}
	else {
		get<2>(tuple) = thirdSide;
	}
}

template <typename T>
inline Triangle::Triangle(const::tuple<T, T, T>& tuple)
{
	setTriangle(get<0>(tuple), get<1>(tuple), get<2>(tuple));
}

template<typename T>
inline Triangle::Triangle(const T& firstSide, const T& secondSide, const T& thirdSide)
{
	setTriangle(firstSide, secondSide, thirdSide);

}

inline float Triangle::area() const
{

	float p = (get<0>(tuple) + get<1>(tuple) + get<2>(tuple)) / 2;
	float s = sqrt(p * (p - get<0>(tuple)) * (p - get<1>(tuple)) * (p - get<2>(tuple)));
	return s;
}

inline float Triangle::length() const
{
	return (get<0>(tuple) + get<1>(tuple) + get<2>(tuple));
}

inline ostream& operator<<(ostream& os, const Triangle& obj)
{
	os << "First side of triangle : " << get<0>(obj.tuple) << endl;
	os << "Second side of triangle : " << get<1>(obj.tuple) << endl;
	os << "Third side of triangle : " << get<2>(obj.tuple) << endl;
	os << "Area : " << obj.area() << endl;
	os << "Length : " << obj.length() << endl;
	os << endl;
	return os;
}