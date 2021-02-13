#pragma once
#include<iostream>
#include<string>

using namespace std;
class myExeptions
{
public:
	myExeptions(const string& exMessage = "Unknown error!!") : exMessage(exMessage)
	{}
	virtual const  string& what() const
	{
		return exMessage;
	}

private:
	 string exMessage;
};

class Reservoirs
{
public:
	enum class  TypeReservoirs { sea, ocean, lake, river, swamp, other, undefined };
	const  string getTypeStr() const;
	void Print() const;
	void setName(string Name);
	void setType(TypeReservoirs type);
	void setSizeReservoirs(float width, float height, float depth);
	static bool comparisonType(const  Reservoirs& one, const  Reservoirs& two);
	static int comparisonAmoult(const  Reservoirs& one, const  Reservoirs& two);
	static Reservoirs TheLargestAmoult(const  Reservoirs* one, TypeReservoirs type);
	string getName() const;
	TypeReservoirs getType() const;
	float* getSizeReservoirs() const;
	Reservoirs(string Name, float width, float height, float depth, TypeReservoirs type = TypeReservoirs::undefined);
	Reservoirs();
private:
	string Name;
	TypeReservoirs type;
	float width = 0;
	float height = 0;
	float depth = 0;
	float amount = 0;
	float square = 0;
	static size_t QuntityReservoirs;
};
inline string Reservoirs::getName() const {
	return Name;
}

class WrongLengthException : public myExeptions
{
public:
	WrongLengthException(const  string& exMessage = "Wrong length") : myExeptions(exMessage)
	{}

};

class WrongDepthException : public myExeptions
{
public:
	WrongDepthException(const  string& exMessage = "Wrong depth") : myExeptions(exMessage)
	{}

};

class WrongWidthExceptio : public myExeptions
{
public:
	WrongWidthExceptio(const  string& exMessage = "Wrong width") : myExeptions(exMessage)
	{}

};

class WrongTypeException : public myExeptions
{
public:
	WrongTypeException(const  string& exMessage = "Wrong type") : myExeptions(exMessage)
	{}

};

inline Reservoirs::TypeReservoirs Reservoirs::getType() const
{
	return type;
}

inline float* Reservoirs::getSizeReservoirs() const {
	float size[] = { width,height,depth };
	return size;
}

inline Reservoirs::Reservoirs(string Name, float width, float height, float depth, TypeReservoirs type)
{
	QuntityReservoirs++;
	setName(Name);
	setType(type);
	setSizeReservoirs(width, height, depth);
}

inline Reservoirs::Reservoirs() : Reservoirs("NoName", 1, 1, 1, TypeReservoirs::undefined)
{
}