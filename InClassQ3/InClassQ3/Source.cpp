#include <iostream>
#include <string>
using namespace std;

class DayOfYear
{
private:
	int day;
public:
	static int daysEndOfMnth[];
	static string mnthNme[];
	void print();
	void setDay(int day) { this->day = day; }
	DayOfYear operator++(int);
	DayOfYear operator++();
	DayOfYear operator--(int);
	DayOfYear operator--();
};

int DayOfYear::daysEndOfMnth[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

string DayOfYear::mnthNme[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };



// Conversion   
void DayOfYear::print()
{
	int month = 0;

	while (daysEndOfMnth[month] < day)
		month = (month + 1) % 12;

	if (month == 0)
		cout << "\nJanuary " << day << endl << endl;

	else
	{
		cout << endl << mnthNme[month] << " "	<< day - daysEndOfMnth[month - 1]<< endl << endl;
	}

}

//The Postfix++
DayOfYear DayOfYear::operator++(int)
{
	DayOfYear mwa;
	mwa.day = day;
	day = (day++) % 365;
	return mwa;
}


//The PostFix++
DayOfYear DayOfYear::operator--(int)
{
	DayOfYear Mwa;

	Mwa.day = day;
	day = (day--) % 365;
	return Mwa;
}

//The Prefix--
DayOfYear DayOfYear::operator++()

{
	DayOfYear Mwa;

	day = (day++) % 365;
	Mwa.day = day;
	return Mwa;
}

//The Prefix--
DayOfYear DayOfYear::operator--()
{
	DayOfYear Mwa;

	day = (day--) % 365;
	Mwa.day = day;
	return Mwa;
}

int main()
{
	DayOfYear dayOfYearObj, x, y;

	int TheDay; 
	cout << "This program converts a number \n"	<< "into a string representing the \n"<< "month and day.\n\n";

	// Input a day.   
	cout << "\nEnter a whole number between 1 and 365: ";
	cin >> TheDay;

	// Set day.
	dayOfYearObj.setDay(TheDay);

	// This will have the object to be outputted.
	dayOfYearObj.print();
	x = dayOfYearObj++;
	dayOfYearObj.print();
	y = --x;
	x.print();
	y.print();
	system("pause");
	return 0;

}

