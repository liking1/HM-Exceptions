#include "Reservoirs.h"

size_t Reservoirs::QuntityReservoirs = 0;

const string Reservoirs::getTypeStr() const {
	static const string typeReservoirs[]{ "river","lake","sea","ocean","swamp","undef" };
	return typeReservoirs[(int)type];
}

void Reservoirs::Print() const
{
	cout << "Name " << this->Name << endl;
	cout << "Type " << getTypeStr() << endl;
	cout << "Width " << this->width << endl;
	cout << "Height " << this->height << endl;
	cout << "Max depth" << this->depth << endl;
	cout << "Amoult " << this->amount << endl;
	cout << "Square " << this->square << endl;

}

void Reservoirs::setName(string Name)
{
	if (Name != "") {
		this->Name = Name;
	}
}

void Reservoirs::setType(TypeReservoirs type)
{
	if (type >= TypeReservoirs::lake && type < TypeReservoirs::undefined) {
		this->type = type;
	}
	else {
		throw WrongTypeException();
	}
}

void Reservoirs::setSizeReservoirs(float width, float height, float maxDepth) {
	if (width > 0 && height > 0 && maxDepth > 0) {
		this->width = width;
		this->height = height;
		this->depth = maxDepth;
		this->amount = (width * height * maxDepth);
		this->square = (width * height);
	}
	else if (maxDepth < 0) {
		throw WrongDepthException();
	}
	else if (width < 0) {
		throw WrongWidthExceptio();
	}
	else if (height < 0) {
		throw WrongLengthException();
	}
}

bool Reservoirs::comparisonType(const Reservoirs& one, const Reservoirs& two)
{
	if (one.type == two.type) {
		return true;
	}
	else {
		return false;
	}
}

int Reservoirs::comparisonAmoult(const Reservoirs& one, const Reservoirs& two)
{
	if (one.amount > two.amount) {
		return 1;
	}
	else if (one.amount < two.amount) {
		return -1;
	}
	else {
		return 0;
	}
}

Reservoirs Reservoirs::TheLargestAmoult(const Reservoirs* one, TypeReservoirs type)
{
	Reservoirs maxReservoirs = one[0];
	for (int i = 0; i < QuntityReservoirs; i++) {
		if (one->amount > maxReservoirs.amount) {
			maxReservoirs = one[i];
		}
	}
	return maxReservoirs;
}