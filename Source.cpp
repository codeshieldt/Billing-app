#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

struct details
{
	string name;
	int age;
	long bal;
	long income;
};

struct allbills
{
	long electricity;
	long gas;
	long internet;
	long security;
	long fine;
	details others;
};

bool isloggedin(string username)
{
	string password, pw, un;
	
	cout << "Enter password: ";
	cin >> password;

	ifstream fin;
	fin.open(username + ".txt");
	getline(fin, un);
	getline(fin, pw);

	if (username == un && pw == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class funct
{
public:
	void display();
	void newbills(string);
	void newaccount(string, string);
	void viewaccount(string);
	void previousbills();
};
void funct::display()
{
	cout << "=====================================================" << endl;
	cout << "          Welcome to Online Transaction." << endl;
	cout << "      Created by Dilawar, Usama and Abdullah." << endl;
	cout << "=====================================================" << endl;
}

void funct::newaccount(string username, string password)
{
	allbills bill;
	ofstream fout;
	cout << "Thank you for choosing our system.\nWe will make sure, you wont regret it!" << endl;
	cout << "Please fill in the following details." << endl;
	cout << "Please Enter your name: ";
	cin >> bill.others.name;
	cout << "Your age: ";
	cin >> bill.others.age;
	cout << "Enter your current account balance: ";
	cin >> bill.others.bal;
	cout << "Enter your monthly income: ";
	cin >> bill.others.income;
	cout << "These are the bills that you will being paying." << endl;
	cout << "(1) Electricity" << endl;
	cout << "(2) Gas" << endl;
	cout << "(3) Internet" << endl;
	cout << "(4) Security" << endl;
	cout << "Congratulations, you have sucessfully created an account!" << endl;
	fout.open(username + ".txt", ios::app);
	fout << username << endl;
	fout << password << endl;
	fout << bill.others.bal << endl;
	fout << bill.others.income << endl;
	fout << endl;
	fout << "Asalam Akaikum Mr." << bill.others.name << endl;
	fout << "You will have to pay the following charges every month." << endl;
	fout << "Electricity = 50000" << endl;
	fout << "Gas = 15000" << endl;
	fout << "Internet = 4000" << endl;
	fout << "Security = 10000" << endl;
	fout.close();
}

void funct::newbills(string username)
{
	allbills bills;
	int num;
	char ans;
	string customer;
	string line1, line2, line3, line4;
	ifstream fin;
	ofstream fout;
	fin.open(username + ".txt");
	getline(fin, line1);
	getline(fin, line2);
	getline(fin, line3);
	getline(fin, line4);
	bills.others.bal = stoi(line3);
	bills.others.income = stoi(line4);
	fout.open(username + ".txt", ios::app);
	do
	{
		cout << "Your total account balance is: " << bills.others.bal << endl;
		cout << "Your monthly income is: " << bills.others.income << endl;
		cout << endl;
		cout << "(1) Electricity" << endl;
		cout << "(2) Gas" << endl;
		cout << "(3) Internet" << endl;
		cout << "(4) Security" << endl;
		cout << "Which bill do you want to pay? ";
		cin >> num;
		bills.electricity = 10000;
		bills.gas = 8000;
		bills.internet = 4000;
		bills.security = 5000;
		bills.fine = 500;
		fout << endl;
		if (num == 1)
		{
			cout << "You have to pay " << bills.electricity << " to the electricity company." << endl;
			cout << "Enter customer Id: ";
			cin >> customer;
			if (bills.others.bal >= bills.electricity)
			{
				bills.others.bal = bills.others.bal - bills.electricity;
				cout << "PAID!" << endl;
				cout << "Your remaining balance is " << bills.others.bal << endl;
				fout << "You have PAID your electricity bill." << endl;
			}
			else
			{
				cout << "Your current bank balance is low." << endl;
				cout << "Your income will be added up in 2 days, due to which you" << endl;
				cout << "will have to pay the fine as well, which is" << bills.fine << endl;
				cout << endl;
				bills.electricity += bills.fine;
				cout << "So, now the bill is " << bills.electricity << endl;;
				bills.others.bal = bills.others.bal + bills.others.income;
				fout << "Late payment, due to which fine was added." << endl;
			}
		}
		else if (num == 2)
		{
			cout << "You have to pay " << bills.gas << " to the gas company." << endl;
			cout << "Enter customer Id: ";
			cin >> customer;
			if (bills.others.bal >= bills.gas)
			{
				bills.others.bal = bills.others.bal - bills.gas;
				cout << "PAID!" << endl;
				cout << "Your remaining balance is " << bills.others.bal << endl;
				fout << "You have PAID your gas bill." << endl;
			}
			else
			{
				cout << "Your current bank balance is low." << endl;
				cout << "Your income will be added up in 2 days, due to which you" << endl;
				cout << "will have to pay the fine as well, which is" << bills.fine << endl;
				cout << endl;
				bills.gas += bills.fine;
				cout << "So, now the bill is " << bills.gas << endl;;
				bills.others.bal = bills.others.bal + bills.others.income;
				fout << "Late payment, due to which fine was added." << endl;
			}
		}
		else if (num == 3)
		{
			cout << "You have to pay " << bills.internet << " to the internet company." << endl;
			cout << "Enter customer Id: ";
			cin >> customer;
			if (bills.others.bal >= bills.internet)
			{
				bills.others.bal = bills.others.bal - bills.internet;
				cout << "PAID!" << endl;
				cout << "Your remaining balance is " << bills.others.bal << endl;
				fout << "You have PAID your internet bill." << endl;
			}
			else
			{
				cout << "Your current bank balance is low." << endl;
				cout << "Your income will be added up in 2 days, due to which you" << endl;
				cout << "will have to pay the fine as well, which is" << bills.fine << endl;
				cout << endl;
				bills.internet += bills.fine;
				cout << "So, now the bill is " << bills.internet << endl;;
				bills.others.bal = bills.others.bal + bills.others.income;
				fout << "Late payment, due to which fine was added." << endl;
			}
		}
		else if (num == 4)
		{
			cout << "You have to pay " << bills.security << " to the security company." << endl;
			cout << "Enter customer Id: ";
			cin >> customer;
			if (bills.others.bal >= bills.security)
			{
				bills.others.bal = bills.others.bal - bills.security;
				cout << "PAID!" << endl;
				cout << "Your remaining balance is " << bills.others.bal << endl;
				fout << "You have PAID your security bill." << endl;
			}
			else
			{
				cout << "Your current bank balance is low." << endl;
				cout << "Your income will be added up in 2 days, due to which you" << endl;
				cout << "will have to pay the fine as well, which is" << bills.fine << endl;
				cout << endl;
				bills.security += bills.fine;
				cout << "So, now the bill is " << bills.security << endl;;
				bills.others.bal = bills.others.bal + bills.others.income;
				fout << "Late payment, due to which fine was added." << endl;
			}
		}
		else
		{
			cout << "No bill" << endl;
		}
		cout << "Do you want to pay the bills (y / n)? ";
		cin >> ans;
	} while (ans == 'y');
}

void funct::viewaccount(string username)
{
	ifstream fin;
	char file[500];
	fin.open(username + ".txt");
	if (!fin.fail())
	{
		while (fin >> file)
		{
			cout << file << " ";
		}
	}
}

void funct::previousbills()
{
	stack <string> electricity;
	stack <string> gas;
	stack <string> internet;
	stack <string> security;
	electricity.push("Paid");
	electricity.push("10000");
	gas.push("Paid");
	gas.push("8000");
	internet.push("Paid");
	internet.push("4000");
	security.push("Paid");
	security.push("5000");
	cout << "Electricity!" << endl;
	while (!electricity.empty())
	{
		cout << "Records: " << electricity.top() << endl;
		electricity.pop();
	}
	cout << endl;
	cout << "Gas!" << endl;
	while (!gas.empty())
	{
		cout << "Records: " << gas.top() << endl;
		gas.pop();
	}
	cout << endl;
	cout << "Internet!" << endl;
	while (!internet.empty())
	{
		cout << "Records: " << internet.top() << endl;
		internet.pop();
	}
	cout << endl;
	cout << "Security!" << endl;
	while (!security.empty())
	{
		cout << "Records: " << security.top() << endl;
		security.pop();
	}
	cout << endl;
}

int main()
{
	funct functions;
	functions.display();
	allbills bill;
	string username, password;
	int choice;
	char ans;
	cout << "Press 1 to Create new account." << endl;
	cout << "Press 2 to log in." << endl;
	cout << "Press 3 to exit." << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	if (choice == 1)
	{
		cout << "Select a username: ";
		cin >> username;
		cout << "Select a password: ";
		cin >> password;
		functions.newaccount(username, password);
		main();
	}
	else if (choice == 2)
	{
		cout << "Enter username: ";
		cin >> username;
		bool status = isloggedin(username);
		if (!status)
		{
			cout << "False log in" << endl;
			return false;
		}
		else
		{
			cout << "You have been sucessfully logged in!" << endl;
			cout << "Do you want to pay new bills or see the previous one\nor view your account (n / p / v)?";
			cin >> ans;
			if (ans == 'n')
			{
				functions.newbills(username);
			}
			else if (ans == 'p')
			{
				functions.previousbills();
			}
			else if (ans == 'v')
			{
				functions.viewaccount(username);
			}
			return true;
		}
	}
	
}