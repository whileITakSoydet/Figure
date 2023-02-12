#pragma once
#include <iostream>
#include <fstream>
#include <string>
#define PI 3.1415926

using namespace std;

class Shape
{
public:
	virtual double area() = 0; //площадь
	virtual void show() = 0; //вывод на экран информации о фигуре
	virtual void save() = 0; //сохранение фигуры в файл
	virtual void load() = 0; //считывание фигуры из файла
};

class Square : public Shape
{
public:
	double width;
	Square(double width) : width{ width } {}

	double area() override {
		return width * width;
	}

	void show() override
	{
		cout << "Square , area = " << area() << endl;
	}

	void save() override
	{
		fstream fout;
		fout.open("file.txt", ofstream::app);
		if (fout.is_open())
		{
			fout << *this;
		}
		else
		{
			cout << "error\n";
		}
		fout.close();
	}

	virtual void load() override
	{
		ifstream fin;
		fin.open("file.txt");
		if (fin.is_open())
		{
			string str;
			double x;
			while (!fin.eof())
			{
				str = "";
				fin >> str;
				if (str == "Square")
				{
					cout << str;
					fin >> x;
					width = x;
					cout << " : " << x << endl;
				}
			}
		}
		else
		{
			cout << "error\n";
		}
		fin.close();
	}

	friend ostream& operator<<(ostream& out, Square s);
};

class Rectangle :public Square 
{
public:
	double height;
	Rectangle(double width, double height) : Square(width), height{ height } {}

	double area() override
	{
		return width * height;
	}

	void show() override
	{
		cout << "Square, area = " << area() << endl;
	}

	void save() override
	{
		fstream fout;
		fout.open("file.txt", ofstream::app);
		if (fout.is_open())
		{
			fout << *this;
		}
		else
		{
			cout << "error";
		}
		fout.close();
	}

	virtual void load() override
	{
		ifstream fin;
		fin.open("file.txt");
		if (fin.is_open())
		{
			string str;
			double x, y;
			while (!fin.eof())
			{
				str = "";
				fin >> str;
				if (str == "Rectangle")
				{
					cout << str;
					fin >> x;
					width = x;
					fin >> y;
					height = y;
					cout << " : " << x << " : " << y << endl;
				}
			}
		}
		else
		{
			cout << "error\n";
		}
		fin.close();
	}

	friend ostream& operator<<(ostream& out, Rectangle r);
};

class Circle : public Square
{
public:
	Circle(double w) : Square(w) {}

	double area() override
	{
		return (width * width / 4) * PI;
	}

	void show() override
	{
		cout << "Circle, area = " << area() << endl;
	}

	void save() override
	{
		fstream fout;
		fout.open("file.txt", ofstream::app);
		if (fout.is_open())
		{
			fout << *this;
		}
		else
		{
			cout << "error";
		}
		fout.close();
	}

	virtual void load() override
	{
		ifstream fin;
		fin.open("file.txt");
		if (fin.is_open())
		{
			string str;
			double x;
			while (!fin.eof())
			{
				str = "";
				fin >> str;
				if (str == "Circle")
				{
					cout << str;
					fin >> x;
					width = x;
					cout << " : " << x << endl;
				}
			}
		}
		else
		{
			cout << "error\n";
		}
		fin.close();
	}

	friend ostream& operator<<(ostream& out, Circle c);
};

class Ellipse : public Rectangle
{
public:
	Ellipse(double w, double h) : Rectangle(w, h) {}

	double area() override
	{
		return (width * height / 4) * PI;
	}

	void show() override
	{
		cout << "Rectangle, area = " << area() << endl;
	}

	void save() override
	{
		fstream fout;
		fout.open("file.txt", ofstream::app);
		if (fout.is_open())
		{
			fout << *this;
		}
		else
		{
			cout << "error";
		}
		fout.close();
	}

	virtual void load() override
	{
		ifstream fin;
		fin.open("file.txt");
		if (fin.is_open())
		{
			string str;
			double x, y;
			while (!fin.eof())
			{
				str = "";
				fin >> str;
				if (str == "Ellipse")
				{
					cout << str;
					fin >> x;
					width = x;
					fin >> y;
					height = y;
					cout << " : " << x << " : " << y << endl;
				}
			}
		}
		else
		{
			cout << "error\n";
		}
		fin.close();
	}

	friend ostream& operator<<(ostream& out, Ellipse e);
};