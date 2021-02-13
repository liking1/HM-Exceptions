#include <iostream>
#include <vector>
#include "Figure.h"
#include "Reservoirs.h"

int main()
{
	//1
	try {
		Triangle triangle(2, 5, 8);
	}
	catch (const double& ex) {
		cout << "Bad side " << ex << endl;
	}
	catch (const string& ex) {
		cout << ex << endl;
	}
	try {
		Reservoirs triangle("ddepth", 2, 5, 8);
	}
	catch (const myExeptions& ex) {
		cout << ex.what() << endl;
	}
	catch (const string& ex) {
		cout << ex << endl;
	}

	//2
	try {
		vector<string> v{ "5","6","2" };
		v.at(5) = 5;
		for (auto& i : v)
		{
			cout << i << endl;
		}
	}
	catch (const out_of_range& ex) {
		cout << ex.what() << endl;
	}

}