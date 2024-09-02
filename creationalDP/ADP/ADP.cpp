#include "ADP.h"

int main() {
	/*Passing with OS Type windows*/
	std::string osType = "win";
	iFactory* fact = abstractFactory::createFactory(osType);
	fact->createButton()->pressButton();
	fact->createTextBox()->writeTextBox();

	/*Passing with OS Type Unix*/
	std::string osType1 = "unix";
	iFactory* fact1 = abstractFactory::createFactory(osType1);
	fact1->createButton()->pressButton();
	fact1->createTextBox()->writeTextBox();

	/*Passing with OS Type empty in this case it should create windows object*/
	std::string osType2 = " ";
	iFactory* fact2 = abstractFactory::createFactory(osType2);
	fact2->createButton()->pressButton();
	fact2->createTextBox()->writeTextBox();

	return 0;
}