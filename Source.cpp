
#include <iostream>
#include <iomanip>

using namespace std;

class cylinderType
{
public:
	void setRadius(double r);
	void setHeight(double h);
	double getRadius();
	double getHeight();
	double volume();
	double area();

	cylinderType(double r, double h);
	cylinderType();

private:
	double radius;
	double height;
};

void cylinderType::setRadius(double r)
{
	//checking for the correct value of the radius
	if (r >= 0)
		radius = r;
	else
		radius = 0;
}

void cylinderType::setHeight(double h)
{
	//checking for the correct value of the height
	if (h >= 0)
		height = h;
	else
		height = 0;
}

double cylinderType::getRadius()
{
	return radius;
}

double cylinderType::getHeight()
{
	return height;
}

double cylinderType::volume() //calculating the value of volume
{
	return 3.14 * (radius * radius) * height;
}

double cylinderType::area() //calculating the value of area
{
	return (2 * 3.14 * radius * height) + (2 * 3.14 * radius * radius);
}

cylinderType::cylinderType(double r, double h)
{
	setRadius(r);
	setHeight(h);
}

cylinderType::cylinderType()
{
	radius = 0;
	height = 0;
}

int main()
{
	double radius;
	double height;
	double ship_Cost;
	double paint_Cost;
	double paint_Total;
	double total;
	char answer = 'x';

	cylinderType program;

	//user inputted information to make the program run and do calculations
	cout << "Welcome to Amanda & Tyler's Cylinder Painting and Shipping Services.\n\n";
	cout << "Please enter the dimensions of your container (radius & height).\n";
	cout << "Radius (in feet): ";
	cin >> radius;
	cout << "\nHeight (in feet): ";
	cin >> height;
	
	//sets the values of radius & height from the users input
	program.setRadius(radius);
	program.setHeight(height);

	//shipping cost inputs from the user
	cout << "\nPlease enter the shipping cost per liter: $";
	cin >> ship_Cost;
	cout << endl << fixed << showpoint << setprecision(2);
	//converts from liters to cubic ft & then calculates the total shipping cost
	total = ship_Cost * program.volume() * 28.32;
	cout << "Based on the containers shipping cost and dimensions your total cost comes to $" << total << endl;

	//Provides the option to paint the outside of the container and outputs the cost of painting separately
	while (answer != 'Y' && answer != 'N')
	{
		cout << "\nWould you like the container to be painted?" << endl;
		cout << "Enter Y for Yes or N for No: ";
		cin >> answer;
		cout << endl;
		//will calculate for another shipping container and then exit
		if (answer == 'Y' || answer == 'y')
		{
			cout << "Please enter the paint cost per square foot: ";
			cin >> paint_Cost;
			cout << endl;
			//formula to arrive a final cost
			paint_Total = paint_Cost * program.area();
			total = (ship_Cost * program.volume()) + (paint_Cost * program.area());
			cout << "The cost of painting the container comes to $" << paint_Total << endl;
			cout << "Your new total, including shipping and painting cost, is $" << total;
			cout << "\n\nThank you for choosing Amanda & Tyler's Cylinder Painting and Shipping services." << endl;
		}
		//prints out final figures and exits
		else if (answer == 'N' || answer == 'n') 
		{
			cout << "Your final total is $" << total << endl << endl;
			cout << "Thank you for choosing Amanda & Tyler's Cylinder Painting and Shipping services." << endl;
		}
		break;
	}
	return 0;
}