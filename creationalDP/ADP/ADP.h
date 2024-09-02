#pragma once
#ifndef _ADP_
#define _ADP_
#include <iostream>

/*Writing an interface for Button */
class iButton
{
public:
	virtual void pressButton() = 0;

};

/*doing some operation on windows Button */
class winButton : public iButton
{
public:
	void pressButton() {
		std::cout << "Windows Button Pressed" << std::endl;
	}
};

/*doing some operation on unix Button */
class unixButton : public iButton
{
public:
	void pressButton() {
		std::cout << "Unix Button Pressed" << std::endl;
	}
};

/*Writing an interface for textBox */
class iTextBox {
public:
	virtual void writeTextBox() = 0;
};

/* doing some operation for windows text box*/
class winTextBox : public iTextBox{
public:
	void writeTextBox() {
		std::cout << "Writing in window textbox is done." << std::endl;
	}
};

/* doing some operation for unix text box*/
class unixTextBox : public iTextBox {
public:
	void writeTextBox() {
		std::cout << "Writing in unix textbox is done." << std::endl;
	}
};

/* creating an interface for factory*/
class iFactory {
public:
	virtual iButton* createButton() = 0;
	virtual iTextBox* createTextBox() = 0;
};

/* creating windows factory*/
class winFactory : public iFactory {
public:
	iButton* createButton() {
		return new winButton();
	}
	iTextBox* createTextBox() {
		return new winTextBox();
	}
};

/* creating unix factory*/
class unixFactory : public iFactory {
public:
	iButton* createButton() {
		return new unixButton();
	}
	iTextBox* createTextBox() {
		return new unixTextBox();
	}
};

/* Creating the final factory for win or unix*/
class abstractFactory {
public:
	static iFactory* createFactory(std::string osType) {
		if (osType == "win")
			return new winFactory();
		else if (osType == "unix")
			return new unixFactory();
		else
			return new winFactory();
	}
};

#endif // !_ADP_

