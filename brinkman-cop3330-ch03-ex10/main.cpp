#include "main.h"

double add(double num1, double num2) { return num1 + num2; }
double subtract(double num1, double num2) { return num1 - num2; }
double mult(double num1, double num2) { return num1 * num2; }
double divide(double num1, double num2) { return num1 / num2; }

void CheckSize(vector<string> elements)
{
	if (elements.size() != 3)
	{
		cout << "Incorrect word count. Please enter in the following format: \"operator number number\"";
		exit(0);
	}
}

double TryToConvert(double num, vector<string> elements, int index)
{
	try { num = stod(elements[index]); }
	catch (exception)
	{
		cout << "Incorrect value. Please enter in the following format: \"operator number number\"";
		exit(0);
	}
	return num;
}

void SplitString(string str, vector<string>& vec) {

	string temp = "";
	for (int i = 0; (unsigned)i < str.length(); ++i) {

		if (str[i] == ' ') {
			vec.push_back(temp);
			temp = "";
		}
		else {
			temp.push_back(str[i]);
		}

	}
	vec.push_back(temp);
}

int main()
{
	vector<string> elements;
	string input;
	double num1 = 0, num2 = 0, result = 0;

	cout << "Please enter your operation and values\n";
	getline(cin, input);

	SplitString(input, elements);

	CheckSize(elements);
	num1 = TryToConvert(num1, elements, 1);
	num2 = TryToConvert(num2, elements, 2);

	if (elements[0] == "+")
		result = add(num1, num2);
	else if (elements[0] == "-")
		result = subtract(num1, num2);
	else if (elements[0] == "*")
		result = mult(num1, num2);
	else if (elements[0] == "/")
		result = divide(num1, num2);
	else
	{
		cout << "Invalid Operand. Please enter in the following format: \"operator number number\"";
		result;
		exit(0);
	}

	cout << result;
}