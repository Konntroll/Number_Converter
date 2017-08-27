// numberConverter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>

const std::array<std::string, 19> digitsTeens{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
const std::array<std::string, 8> doubleDigits{ "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
const std::array<std::string, 21> largeNumbers{ "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion", "nonillion", "decillion", "undecillion", "duodecillion", "tredecillion", "quattuordecillion", "quindecillion", "sexdecillion", "septendecillion", "octodecillion", "novemdecillion", "vigintillion" };
int bigNumIndex = 0;

void indexOfBigNumbers(int num) {
	if (num > 999) {
		bigNumIndex++;
		indexOfBigNumbers(num / 1000);
	}
}

std::string doubleDigit(int doubleD) {
	if (doubleD < 20) {
		return digitsTeens[doubleD - 1];
	}
	else if (doubleD % 10 != 0) {
		return (doubleDigits[doubleD / 10 - 2] + " " + digitsTeens[doubleD % 10 - 1]);
	}
	else {
		return doubleDigits[doubleD / 10 - 2];
	}
}

std::string tripleDigit(int tripleD) {
	if (tripleD > 99) {
		return (digitsTeens[tripleD / 100 - 1] + " hundred " + doubleDigit(tripleD % 100));
	}
	else {
		return doubleDigit(tripleD % 100);
	}
}

void numCon(int num) {
	if (num > 999) {
		numCon(num / 1000);
		std::cout << " " << largeNumbers[--bigNumIndex];
	}
	std::cout << " " << tripleDigit(num % 1000);
}


int main()
{
	std::cout << "Enter the integer you want to convert: ";
	int num;
	std::cin >> num;
	indexOfBigNumbers(num);
	numCon(num);
	std::cout << "\n";
	return 0;
}

