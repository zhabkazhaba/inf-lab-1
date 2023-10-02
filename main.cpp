#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

string ten_to_x(string num,int base){
	string result = "";
	long long int temp;
	long long int inum;
	inum = stol(num);
	while (inum > 0){
		temp = inum % base;
		inum = inum / base;
		if (temp < 10){
			result = char(temp+48) + result;
		} else {
			result = (char)(temp + 55) + result;
		}
	}
	return result;
}

string x_to_ten(string num, int base){
	string result = "";
	int iresult = 0;
	int i;
	char temp;
	int itemp = 0;
	for (i = 0; i < num.length(); i++){
		temp = num[num.length()-1 - i];
		if (isalpha(temp) == 0){
			itemp = temp - 48;
		} else {
			itemp = temp - 55;
		}
		iresult = iresult + itemp * pow(base,(i));
	}
	result = to_string(iresult);
	return result;
}

int main(){
	string num1;
	string num2;
	int base;
	string result;
	char op;
	bool state = 1;
	bool is_modified = 0;
	long long int temp1;
	long long int temp2;
	cout << "Enter number 1\n"; cin >> num1;
	cout << "Enter number 2\n"; cin >> num2;
	cout << "Enter base\n"; cin >> base;
	while (state == 1){
	cout << "\n";
	cout << "Enter operation(t|x|+|-|*|)\n"; cin >> op;
	if (is_modified == 1){
		num1 = ten_to_x(num1,base);
		num2 = ten_to_x(num2,base);
		is_modified = 0;
	}
	switch(op){
	case 't':
		result = x_to_ten(num1,base);
		cout << result + " in base " + to_string(base) + "\n";
		result = x_to_ten(num2,base);
		cout << result + " in base " + to_string(base);
		is_modified = 1;
		break;
	case 'x':
		result = ten_to_x(num1,base);
		cout << result + " in base " + to_string(base) + "\n";
		result = ten_to_x(num2,base);
		cout << result + " in base " + to_string(base);
		break;
	case '+':
		if (base == 10){
			result = to_string(stoi(num1) + stoi(num2));
			cout << result + " in base 10";
		} else {
			num1 = x_to_ten(num1,base);
			num2 = x_to_ten(num2,base);
			is_modified = 1;
			result = to_string(stoi(num1) + stoi(num2));
			cout << result + " in base 10\n";
			result = ten_to_x(result,base);
			cout << result + " in base " + to_string(base);
		}
		break;
	case '-':
		if (base == 10){
			result = to_string(stoi(num1) - stoi(num2));
			cout << result + " in base 10";
		} else {
			num1 = x_to_ten(num1,base);
			num2 = x_to_ten(num2,base);
			is_modified = 1;
			result = to_string(stoi(num1) - stoi(num2));
			cout << result + " in base 10\n";
			result = ten_to_x(result,base);
			cout << result + " in base " + to_string(base);
		}
		break;
	case '*':
		if (base == 10){
			result = to_string(stoi(num1) * stoi(num2));
			cout << result + " in base 10";
		} else {
			num1 = x_to_ten(num1,base);
			num2 = x_to_ten(num2,base);
			is_modified = 1;
			temp1 = stoi(num1);
			temp2 = stoi(num2);
			result = to_string(temp1*temp2);
			cout << result + " in base 10\n";
			result = ten_to_x(result,base);
			cout << result + " in base " + to_string(base);
		}
		break;
	default:
		cout << "Wrong operation!";
		state = 0;
		break;
	}
	}
	return 0;
}

