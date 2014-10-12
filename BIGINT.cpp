#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

class BigInt {
	public:
		BigInt();
		BigInt(const BigInt&);
		BigInt(int);
		BigInt(long long);
		BigInt(long);
		BigInt(string);
		virtual ~BigInt();
		BigInt operator +(const BigInt&);
		BigInt operator -(const BigInt&);
		BigInt operator *(const BigInt&);
		BigInt operator /(const BigInt&);
		BigInt operator %(const BigInt&);
		BigInt operator ^(BigInt&);
		void operator +=(const BigInt&);
		void operator -=(const BigInt&);
		void operator *=(const BigInt&);
		void operator /=(const BigInt&);
		void operator %=(const BigInt&);
		BigInt & operator ++();
		BigInt operator ++(int);
		BigInt & operator --();
		BigInt operator --(int);
		void operator =(const BigInt&);
		bool operator ==(const BigInt&);
		bool operator !=(const BigInt&);
		bool operator<(const BigInt&);
		bool operator <=(const BigInt&);
		bool operator>(const BigInt&);
		bool operator >=(const BigInt&);
		friend ostream & operator <<(ostream&, const BigInt&);
		static BigInt factorial(const BigInt&);
		static BigInt mod(const BigInt&);
		static bool isPalindrome(const BigInt&);
		static bool isPrime(const BigInt&);
		static bool isEven(const BigInt&);
		static BigInt reverseNumber(const BigInt&);
		static long sumOfDigit(const BigInt&);
		static int numberOfDigit(const BigInt&);
	private:
		char *number;

		enum SIGN {
			negative = -1,
			zero,
			positive
		};
		SIGN sign;
};

const short divisionByZero = 4;

template <class Type>
int
digitCount(Type number) {
	if (!number)
		return 1;
	int digit = 0;
	while (number) {
		digit++;
		number /= 10;
	}
	return digit;
}

void *
CALLOC(unsigned int nElement, unsigned int size) {
	void *ptr = calloc(nElement, size);
	if (nElement && size && !ptr) {
		cerr << "memory allocation failed\n";
		exit(0);
	}
	return ptr;
}

bool
lessThan(const char *number1, const char *number2) {
	unsigned long length1 = strlen(number1), length2 = strlen(number2);
	if (length1 < length2)
		return true;
	else if (length1 > length2)
		return false;
	else {
		for (unsigned long i = 0; i < length1; i++) {
			if (number1[i] < number2[i])
				return true;
			else if (number1[i] > number2[i])
				return false;
		}
		return false;
	}
}

bool
equal(const char *number1, const char *number2) {
	if (!strcmp(number1, number2))
		return true;
	return false;
}

BigInt
addition(const char *number1, const char *number2) {
	unsigned int minLength = strlen(number1) <= strlen(number2) ? strlen(number1)
		: strlen(number2),
		maxLength = strlen(number1) >= strlen(number2) ? strlen(number1)
			: strlen(number2), i;
	char *temp1 = (char *) CALLOC(maxLength + 1, sizeof (char)),
	     *temp2 = (char *) CALLOC(maxLength + 1, sizeof (char)),
	     *result = (char *) CALLOC(maxLength + 2, sizeof (char));
	for (i = 1; i <= maxLength - minLength; i++)
		*(temp1 + i - 1) = '0';
	if (minLength == strlen(number1)) {
		strcpy(temp1 + i - 1, number1);
		strcpy(temp2, number2);
	} else {
		strcpy(temp1 + i - 1, number2);
		strcpy(temp2, number1);
	}
	memset(result, '0', maxLength + 1);
	result[maxLength + 1] = '\0';
	for (int i = maxLength - 1; i >= 0; i--) {
		result[i + 1] += temp1[i] + temp2[i] - 2 * '0';
		if (result[i + 1] > '9') {
			result[i + 1] -= 10;
			result[i] = '1';
		}
	}
	free(temp1);
	free(temp2);
	i = 0;
	while (result[i + 1] != '\0' && result[i] == '0')
		i++;
	BigInt sum(result + i);
	free(result);
	return sum;
}

BigInt
subtraction(const char *number1, const char *number2) {
	unsigned int minLength, maxLength;
	minLength = strlen(number1) <= strlen(number2) ? strlen(number1)
		: strlen(number2);
	maxLength = strlen(number1) >= strlen(number2) ? strlen(number1)
		: strlen(number2);
	char *temp1 = (char *) CALLOC(maxLength + 1, sizeof (char)),
	     *temp2 = (char *) CALLOC(maxLength + 1, sizeof (char));
	char *result;
	result = (char *) CALLOC(maxLength + 1, sizeof (char));
	unsigned int i;
	if (minLength != maxLength) {
		for (i = 1; i <= maxLength - minLength; i++)
			*(temp1 + i - 1) = '0';
		if (minLength == strlen(number1)) {
			strcpy(temp1 + i - 1, number1);
			strcpy(temp2, number2);
		} else {
			strcpy(temp1 + i - 1, number2);
			strcpy(temp2, number1);
		}
	} else {
		strcpy(temp1, number1);
		strcpy(temp2, number2);
		for (i = 0; i <= maxLength - 1; i++) {
			if (number1[i] < number2[i]) {
				strcpy(temp1, number1);
				strcpy(temp2, number2);
				break;
			} else if (number1[i] > number2[i]) {
				strcpy(temp2, number1);
				strcpy(temp1, number2);
				break;
			}
		}
	}
	for (i = 0; i <= maxLength - 1; i++)
		result[i] = '0';
	result[i] = '\0';
	for (int i = maxLength - 1; i >= 0; i--) {
		result[i] += temp2[i] - temp1[i];
		if (result[i] < '0') {
			result[i] += 10;
			temp1[i - 1] += 1;
		}
	}
	free(temp1);
	free(temp2);
	i = 0;
	while (result[i + 1] != '\0' && result[i] == '0')
		i++;
	BigInt subtract(result + i);
	free(result);
	return subtract;
}

BigInt
division(const char *number1, const char *number2) {
	BigInt result(0);
	char zero[] = "0";
	BigInt mulTable[11];
	if (equal(number2, zero))
		throw divisionByZero;
	else if (equal(number1, zero))
		return result;
	else if (lessThan(number1, number2))
		return result;
	else {
		for (int i = 0; i < 11; i++) {
			BigInt temp(number2), multiplier(i);
			mulTable[i] = temp * multiplier;
		}
		int minLength = strlen(number2), maxLength = strlen(number1);
		BigInt ratio(0), multiplier(10);
		char tempDividend[maxLength + 1];
		strncpy(tempDividend, number1, minLength);
		tempDividend[minLength] = '\0';
		BigInt partialDividend(tempDividend);
		for (int i = minLength + 1; i <= maxLength + 1; i++) {
			int count = 0;
			while (mulTable[count] < partialDividend)
				count++;
			if (mulTable[count] != partialDividend)
				count--;
			BigInt counter(count);
			ratio = (ratio * multiplier) + counter;
			if (!count) {
				char ch[2];
				ch[0] = number1[i - 1];
				ch[1] = '\0';
				BigInt nextDigit(ch);
				partialDividend = (partialDividend * multiplier) + nextDigit;
			} else {
				partialDividend -= mulTable[count];
				char ch[2];
				ch[0] = number1[i - 1];
				ch[1] = '\0';
				BigInt nextDigit(ch);
				partialDividend = (partialDividend * multiplier) + nextDigit;
			}
		}
		result = ratio;
	}
	return result;
}

BigInt::BigInt() {
	number = (char *) CALLOC(1, sizeof (char));
	*number = '\0';
}

BigInt::BigInt(const BigInt& original) {
	number = (char *) CALLOC(strlen(original.number) + 1, sizeof (char));
	strcpy(number, original.number);
	sign = original.sign;
}

BigInt::BigInt(int num) {
	if (num < 0) {
		sign = negative;
		num *= -1;
	} else if (num > 0)
		sign = positive;
	else
		sign = zero;
	int i = digitCount<int> (num);
	number = (char *) CALLOC(i + 1, sizeof (char));
	*(number + i) = '\0';
	if (!num)
		*number = '0';
	while (num) {
		i--;
		*(number + i) = num % 10 + '0';
		num /= 10;
	}
}

BigInt::BigInt(long num) {
	if (num < 0) {
		sign = negative;
		num *= -1;
	} else if (num > 0)
		sign = positive;
	else
		sign = zero;
	int i = digitCount<long> (num);
	number = (char *) CALLOC(digitCount(num) + 1, sizeof (char));
	*(number + i) = '\0';
	if (!num)
		*number = '0';
	while (num) {
		i--;
		*(number + i) = num % 10 + '0';
		num /= 10;
	}
}

BigInt::BigInt(long long num) {
	if (num < 0) {
		sign = negative;
		num *= -1;
	} else if (num > 0)
		sign = positive;
	else
		sign = zero;
	int i = digitCount<long long> (num);
	number = (char *) CALLOC(digitCount(num) + 1, sizeof (char));
	*(number + i) = '\0';
	if (!num)
		*number = '0';
	while (num) {
		i--;
		*(number + i) = num % 10 + '0';
		num /= 10;
	}
}

BigInt::BigInt(string str) {
	sign = positive;
	if (str[0] == '-') {
		sign = negative;
		str.erase(0, 1);
	}
	char *temp = (char *) CALLOC(str.length() + 1, sizeof (char));
	strcpy(temp, str.c_str());
	unsigned int i = 0;
	while (temp[i + 1] != '\0' && temp[i] == '0')
		i++;
	number = (char *) CALLOC(strlen(temp + i) + 1, sizeof (char));
	strcpy(number, temp + i);
	if (strlen(number) == 1 && number[0] == '0')
		sign = zero;
	free(temp);
}

BigInt::~BigInt() {
	free(number);
}

void
BigInt::operator=(const BigInt& bigNumber) {
	free(this->number);
	this->number = (char *) CALLOC(strlen(bigNumber.number) + 1, sizeof (char));
	strcpy(this->number, bigNumber.number);
	this->sign = bigNumber.sign;
	return;
}

BigInt
BigInt::operator+(const BigInt& bigNumber) {
	BigInt sum;
	if (this->sign == zero)
		sum = bigNumber;
	if (bigNumber.sign == zero)
		sum = *this;
	if (this->sign != zero && bigNumber.sign != zero) {
		if (this->sign == bigNumber.sign) {
			sum = addition(this->number, bigNumber.number);
			sum.sign = this->sign;
		} else {
			if (equal(this->number, bigNumber.number)) {
				BigInt temp(0);
				sum = temp;
			} else {
				sum = subtraction(this->number, bigNumber.number);
				if (lessThan(this->number, bigNumber.number))
					sum.sign = bigNumber.sign;
				else
					sum.sign = this->sign;
			}
		}
	}
	return sum;
}

BigInt
BigInt::operator*(const BigInt& bigNumber) {
	unsigned int minLength = strlen(this->number) <= strlen(bigNumber.number) ? strlen(this->number)
		: strlen(bigNumber.number),
		maxLength = strlen(this->number) >= strlen(bigNumber.number) ? strlen(this->number)
			: strlen(bigNumber.number);
	char *shortNum = (char *) CALLOC(minLength + 1, sizeof (char)),
	     *longNum = (char *) CALLOC(maxLength + 1, sizeof (char)),
	     **mulTable = (char **) CALLOC(10, sizeof (char *));
	memset(mulTable, int(NULL), 10);
	BigInt result(0);
	SIGN resultSign = positive;
	if (this->sign == zero || bigNumber.sign == zero)
		resultSign = zero;
	else if (this->sign != zero && bigNumber.sign != zero && this->sign != bigNumber.sign)
		resultSign = negative;
	if (minLength == strlen(this->number)) {
		strcpy(shortNum, this->number);
		strcpy(longNum, bigNumber.number);
	} else {
		strcpy(shortNum, bigNumber.number);
		strcpy(longNum, this->number);
	}
	for (int i = minLength - 1, mulFactor = 0; i >= 0; i--, mulFactor++) {
		if (shortNum[i] == '0')
			continue;
		if (!mulTable[shortNum[i] - '0']) {
			mulTable[shortNum[i] - '0'] = (char *) CALLOC(maxLength + 2, sizeof (char));
			for (unsigned int j = 0; j <= maxLength; j++)
				mulTable[shortNum[i] - '0'][j] = '0';
			mulTable[shortNum[i] - '0'][maxLength + 1] = '\0';
			for (int j = maxLength - 1; j >= 0; j--) {
				int temp = (shortNum[i] - '0') * (longNum[j] - '0');
				mulTable[shortNum[i] - '0'][j + 1] += (temp % 10);
				if (mulTable[shortNum[i] - '0'][j + 1] > '9') {
					mulTable[shortNum[i] - '0'][j + 1] -= 10;
					mulTable[shortNum[i] - '0'][j] = '1';
				}
				mulTable[shortNum[i] - '0'][j] += (temp / 10);
			}
		}
		char tempStr[strlen(mulTable[shortNum[i] - '0']) + 1];
		strcpy(tempStr, mulTable[shortNum[i] - '0']);
		if (mulFactor) {
			char zeroStr[mulFactor + 1];
			memset(zeroStr, '0', mulFactor);
			zeroStr[mulFactor] = '\0';
			strcat(tempStr, zeroStr);
		}
		result = addition(result.number, tempStr);
	}
	free(shortNum);
	free(longNum);
	for (int i = 0; i < 10; i++)
		free(mulTable[i]);
	free(mulTable);
	result.sign = resultSign;
	return result;
}

BigInt
BigInt::operator-(const BigInt& bigNumber) {
	BigInt result;
	if (bigNumber.sign == zero)
		result = *this;
	if (this->sign == zero && bigNumber.sign != zero) {
		result = bigNumber;
		result.sign = positive;
		if (bigNumber.sign == positive)
			result.sign = negative;
	}
	if (this->sign != zero && bigNumber.sign != zero) {
		if (this->sign != bigNumber.sign) {
			result = addition(this->number, bigNumber.number);
			result.sign = this->sign;
		} else {
			result = subtraction(this->number, bigNumber.number);
			if (equal(this->number, bigNumber.number))
				result.sign = zero;
			else if (lessThan(this->number, bigNumber.number)) {
				result.sign = positive;
				if (this->sign == positive)
					result.sign = negative;
			} else
				result.sign = this->sign;
		}
	}
	return result;
}

BigInt
BigInt::operator/(const BigInt& bigNumber) {
	BigInt result(0);
	int i = 0, j = 0;
	if (this->number[0] == '-')
		i++;
	if (bigNumber.number[0] == '-')
		j++;
	try {
		result = division(this->number + i, bigNumber.number + j);
	} catch (short unUsed) {
		cerr << "Runtime Exception Occurred : Division By Zero in operation ";
		cerr << "\"" << *this << " / " << bigNumber << "\"" << endl;
		cout << "Any further advancement may produce erroneous result\n";
		cout << "\tDo you want to continue (y/n) :    ";
		char ch;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			return *this;
		else
			exit(0);
	}
	result.sign = negative;
	if (this->sign == bigNumber.sign)
		result.sign = positive;
	return result;
}

BigInt
BigInt::operator%(const BigInt& bigNumber) {
	BigInt result(0);
	int i = 0, j = 0;
	if (this->number[0] == '-')
		i++;
	if (bigNumber.number[0] == '-')
		j++;
	try {
		result = division(this->number + i, bigNumber.number + j);
	} catch (short unUsed) {
		cerr << "Runtime Exception Occurred : Division By Zero in operation ";
		cerr << "\"" << *this << " / " << bigNumber << "\"" << endl;
		cout << "Any further advancement may produce erroneous result\n";
		cout << "\tDo you want to continue (y/n) :    ";
		char ch;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			return *this;
		else
			exit(0);
	}
	result.sign = negative;
	if (this->sign == bigNumber.sign)
		result.sign = positive;
	result = *this -(result * bigNumber);
	return result;
}

BigInt
BigInt::operator^(BigInt& bigNumber) {
	if (bigNumber.sign == zero)
		return 1;
	else if (bigNumber.sign == negative)
		return 0;
	else {
		BigInt result(*this), additionalProduct(1);
		SIGN resultSign = positive;
		if ((bigNumber.number[strlen(bigNumber.number) - 1] - '0') % 2)
			resultSign = this->sign;
		while (bigNumber != 1) {
			if (!((bigNumber.number[strlen(bigNumber.number) - 1] - '0') % 2)) {
				result *= result;
				bigNumber /= 2;
			} else {
				--bigNumber;
				additionalProduct *= result;
			}
		}
		result *= additionalProduct;
		result.sign = resultSign;
		return result;
	}
}

ostream &
operator<<(ostream& out, const BigInt& bigNumber) {
	if (bigNumber.sign == BigInt::negative)
		out << "-";
	out << bigNumber.number;
	return out;
}

void
BigInt::operator+=(const BigInt& bigNumber) {
	*this = *this + bigNumber;
}

void
BigInt::operator-=(const BigInt& bigNumber) {
	*this = *this - bigNumber;
}

void
BigInt::operator*=(const BigInt& bigNumber) {
	*this = *this * bigNumber;
}

void
BigInt::operator/=(const BigInt& bigNumber) {
	*this = *this / bigNumber;
}

void
BigInt::operator%=(const BigInt& bigNumber) {
	*this = *this % bigNumber;
}

BigInt &
BigInt::operator++() {
	*this += 1;
	return *this;
}

BigInt
BigInt::operator++(int unUsed) {
	BigInt temp(*this);
	*this += 1;
	return temp;
}

BigInt &
BigInt::operator--() {
	*this -= 1;
	return *this;
}

BigInt
BigInt::operator--(int unUsed) {
	BigInt temp(*this);
	*this -= 1;
	return temp;
}

bool
BigInt::operator==(const BigInt& bigNumber) {
	if (this->sign == bigNumber.sign && equal(this->number, bigNumber.number))
		return true;
	return false;
}

bool
BigInt::operator!=(const BigInt& bigNumber) {
	if (*this == bigNumber)
		return false;
	return true;
}

bool
BigInt::operator<(const BigInt& bigNumber) {
	if (this->sign == negative && (bigNumber.sign == positive || bigNumber.sign == zero))
		return true;
	else if (this->sign == zero && bigNumber.sign == positive)
		return true;
	else if (this->sign == negative && bigNumber.sign == negative &&
			!lessThan(this->number, bigNumber.number) && !equal(this->number, bigNumber.number))
		return true;
	else if (this->sign == positive && bigNumber.sign == positive &&
			lessThan(this->number, bigNumber.number))
		return true;
	else return false;
}

bool
BigInt::operator<=(const BigInt& bigNumber) {
	if (*this < bigNumber || *this == bigNumber)
		return true;
	return false;
}

bool
BigInt::operator>(const BigInt& bigNumber) {
	if (*this < bigNumber || *this == bigNumber)
		return false;
	return true;
}

bool
BigInt::operator>=(const BigInt& bigNumber) {
	if (*this < bigNumber)
		return false;
	return true;
}

BigInt
BigInt::factorial(const BigInt& bigNumber) {
	BigInt result("1");
	if (!strcmp(bigNumber.number, "0"))
		return result;
	BigInt i("1");
	for (; i != bigNumber; i++)
		result *= i;
	return result*i;
}

BigInt
BigInt::mod(const BigInt& bigNumber) {
	BigInt mod(bigNumber);
	if (bigNumber.sign != zero)
		mod.sign = positive;
	return mod;
}

bool
BigInt::isPalindrome(const BigInt& bigNumber) {
	int i = 0, digit = strlen(bigNumber.number), check = digit % 2 == 0 ? digit / 2 : (digit + 1) / 2;
	while (i < check) {
		if (bigNumber.number[i] != bigNumber.number[digit - i - 1])
			return false;
		i++;
	}
	return true;
}

bool
BigInt::isPrime(const BigInt& bigNumber) {
	BigInt testPrime(bigNumber);
	if (testPrime.sign == zero || testPrime.sign == negative)
		return false;
	BigInt testNumber(1), zero(0);
	if (testPrime == testNumber)
		return false;
	testNumber++;
	if (testPrime == testNumber)
		return true;
	if (!((testPrime.number[strlen(testPrime.number) - 1] - '0') % 2))
		return false;
	testNumber++;
	if (testPrime == testNumber)
		return true;
	BigInt testLimit(testPrime);
	do {
		if (testPrime % testNumber == zero)
			return false;
		testLimit = testPrime / testNumber;
		(testNumber++)++;
	} while (testLimit > testNumber);
	return true;
}

bool
BigInt::isEven(const BigInt& bigNumber) {
	int length = strlen(bigNumber.number);
	if (!length)
		return false;
	if (!((bigNumber.number[length - 1] - '0') % 2))
		return true;
	return false;
}

BigInt
BigInt::reverseNumber(const BigInt& bigNumber) {
	string numStr = bigNumber.number, revStr;
	revStr.assign(numStr.rbegin(), numStr.rend());
	BigInt revNum(revStr);
	revNum.sign = bigNumber.sign;
	return revNum;
}

long
BigInt::sumOfDigit(const BigInt& bigNumber) {
	long sum = 0, i = 0;
	while (bigNumber.number[i] != '\0')
		sum += bigNumber.number[i++] - '0';
	return sum;
}

int
BigInt::numberOfDigit(const BigInt& bigNumber) {
	return strlen(bigNumber.number);
}


int main()
{

}
