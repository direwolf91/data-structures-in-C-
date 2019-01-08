// CPP program to find the closest Palindrome number
#include<string>
#include<iostream>
using namespace std; 

#define CToI(x) (x - '0') 
#define IToC(x) (x + '0') 

// function check Palindrome 
bool isPalindrome(string n) 
{ 
	for (int i = 0; i < n.size() / 2; i++) 
		if (n[i] != n[n.size() - 1 - i]) 
			return false; 
	return true; 
} 

// check all 9's 
bool checkAll9(string num) 
{ 
	for (int i = 0; i < num.size(); i++) 
		if (num[i] != '9') 
			return false; 
	return true; 
} 

// Add carry to the number of given size 
string carryOperaion(string num, int carry, int size) 
{ 
	if (carry == -1) 
	{ 
		int i = size - 1; 
		while (i >= 0 && num[i] == '0') 
			num[i--] = '9'; 
		if (i >= 0) 
			num[i] = IToC(CToI(num[i]) - 1); 
	} 
	else
	{ 
		for (int i = size - 1; i >= 0; i--) 
		{ 
			int digit = CToI(num[i]); 
			num[i] = IToC((digit + carry) % 10); 
			carry = (digit + carry) / 10; 
		} 
	} 
	return num; 
} 

// function return the closest number 
// to given number 
string MIN(long long int num, 
		long long int num1, 
		long long int num2, 
		long long int num3) 
{ 

	long long int Diff1 = abs(num - num1); 
	long long int Diff2 = abs(num - num2); 
	long long int Diff3 = abs(num3 - num); 

	if (Diff1 < Diff2 && Diff1 < Diff3 && 
		num1 != num) 
		return to_string(num1); 
	else if (Diff3 < Diff2 && (Diff1 == 0 || 
			Diff3 < Diff1)) 
		return to_string(num3); 
	else
		return to_string(num2); 
} 

// function return closest Palindrome number 
string closestPlandrome(string num) 
{ 

	// base case 
	if (num.size() == 1) 
		return (to_string(stoi(num) - 1)); 

	// case 2: 
	// If a number contains all 9's 
	if (checkAll9(num)) 
	{ 
		string str = "1"; 
		return str.append(num.size() - 1, '0') + "1"; 
	} 

	int size_ = num.size(); 

	// case 1 a: 
	// copy first half and reverse it and append it 
	// at the end of first half 
	string FH = num.substr(0, size_ / 2); 
	string odd; 

	// odd length 
	if (size_ % 2 != 0) 
		odd = num[size_ / 2]; 

	// reverse 
	string SH = FH; 
	reverse(SH.begin(), SH.end()); 

	// store three nearest Palindrome numbers 
	string RPNUM = "", EPNUM = "", LPNUM = ""; 
	string tempFH = ""; 
	string tempSH = ""; 

	if (size_ % 2 != 0) 
	{ 
		EPNUM = FH + odd + SH; 
		if (odd == "0") 
		{ 
			tempFH = carryOperaion(FH, -1, FH.size()); 
			tempSH = tempFH; 
			reverse(tempSH.begin(), tempSH.end()); 
			RPNUM = tempFH + "9" + tempSH; 
		} 
		else
			RPNUM = FH + to_string(stoi(odd) - 1) + SH; 

		// To handle carry 
		if (odd == "9") 
		{ 
			tempFH = carryOperaion(FH, 1, FH.size()); 
			tempSH = tempFH; 
			reverse(tempSH.begin(), tempSH.end()); 
			LPNUM = tempFH + "0" + tempSH; 
		} 
		else
			LPNUM = FH + to_string(stoi(odd) + 1) + SH; 
	} 

	// for even case 
	else
	{ 
		int n = FH.size(); 
		tempFH = FH; 
		EPNUM = FH + SH; 
		if (FH[n - 1] == '0') 
			tempFH = carryOperaion(FH, -1, n); 
		else
			tempFH[n - 1] = IToC(CToI(FH[n - 1]) - 1); 

		tempSH = tempFH; 
		reverse(tempSH.begin(), tempSH.end()); 
		RPNUM = tempFH + tempSH; 

		tempFH = FH; 
		if (FH[n - 1] == '9') 
			tempFH = carryOperaion(FH, 1, n); 
		else
			tempFH[n - 1] = IToC(CToI(tempFH[n - 1]) + 1); 

		tempSH = tempFH; 
		reverse(tempSH.begin(), tempSH.end()); 
		LPNUM = tempFH + tempSH; 
	} 

	// return the closest palindrome numbers 
	return MIN(stoll(num), stoll(EPNUM), stoll(RPNUM), 
										stoll(LPNUM)); 
} 

// Driver program to test above function 
int main() 
{ 
	string num = "99"; 
	cout << closestPlandrome(num) << endl; 
	return 0; 
} 
