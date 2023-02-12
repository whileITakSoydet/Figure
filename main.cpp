#include <iostream>
#include "Shape.h"

using namespace std;

int main()
{
	Shape** arr = new Shape * [] {new Square(4), new Rectangle(3, 4), new Circle(5), new Ellipse(4, 5)};
	for (int i = 0; i < 4; i++)
	{
		arr[i]->save();
	}
	Shape** arr1 = new Shape * [] {new Square(0), new Rectangle(0, 0), new Circle(0), new Ellipse(0, 0)};
	for (int i = 0; i < 4; i++)
	{
		arr1[i]->load();
	}
	cout << "\n\n\n";
	for (int i = 0; i < 4; i++)
	{
		arr1[i]->show();
	}


	return 0;
}

ostream& operator<<(ostream& out, Square s)
{
	out << "Square " << s.width << endl;
	return out;
}

ostream& operator<<(ostream& out, Rectangle r)
{
	out << "Rectangle " << r.width << " " << r.height << endl;
	return out;
}

ostream& operator<<(ostream& out, Circle c)
{
	out << "Circle " << c.width << endl;
	return out;
}

ostream& operator<<(ostream& out, Ellipse e)
{
	out << "Ellipse " << e.width << " " << e.height << endl;
	return out;
}