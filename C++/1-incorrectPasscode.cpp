// One Very Important User (VIU) has a Very Confidential Document (VCD) stored on his Dropbox account. He doesn't let anyone see the VCD, especially his roommates who often have access to his devices.

// Opening the Dropbox mobile app on the VIU's tablet requires a four-digit passcode. To ensure the confidentiality of the stored information, the device is locked out of Dropbox after 10 consecutive failed passcode attempts. We need to implement a function that given an array of attempts made throughout the day and the correct passcode checks to see if the device should be locked, i.e. 10 or more consecutive failed passcode attempts were made.

// Example

// For
// passcode = "1111" and

// attempts = ["1111", "4444",
//             "9999", "3333",
//             "8888", "2222",
//             "7777", "0000",
//             "6666", "7285",
//             "5555", "1111"]
// the output should be
// incorrectPasscodeAttempts(passcode, attempts) = true.

// The first attempt is correct, so the user must have successfully logged in. However, the next 10 consecutive attempts are incorrect, so the device should be locked. Thus, the output should be true.

// For
// passcode = "1234" and

// attempts = ["9999", "9999",
//             "9999", "9999",
//             "9999", "9999",
//             "9999", "9999",
//             "9999", "1234",
//             "9999", "9999"]
// the output should be
// incorrectPasscodeAttempts(passcode, attempts) = false.

// There are only 9 consecutive incorrect attempts, so there's no need to lock the device.

// Input/Output

// [time limit] 500ms (cpp)
// [input] string passcode

// String consisting of exactly 4 digits representing the correct passcode.

// [input] array.string attempts

// Array representing the passcode attempts in the order they were made. Each element of attempts is a string consisting of exactly 4 digits.

// Constraints:
// 0 ≤ attempts.length ≤ 20.

// [output] boolean

// true if 10 or more consecutive failed passcode attempts were made, false otherwise.

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

string passcode = "1111";
string attempts_arr[] = {"1111", 
					 "4444", 
					 "9999", 
					 "3333", 
					 "8888", 
					 "2222", 
					 "7777", 
					 "0000", 
					 "6666", 
					 "7285", 
					 "5555", 
					 "1111"};
vector<string> attempts;

bool incorrectPasscodeAttempts(string passcode, vector<string> attempts) 
{
    bool result;
    result = false;
    int cons = 0;
    int i = 0;
    for (i = 0; i < attempts.size(); i++)
    {
    	cout << passcode << "   " << attempts[i] << endl;
        if (passcode.compare(attempts[i]) == 0)
        {
        	if (cons < 10)
        		cons = 0;
        }
        else
        {
        	if (cons < 10)
        		cons++;
        }
        cout << cons << endl;
    }
    if (cons == 10) result = true;
    return result;

}



int main()
{
	for (int i = 0; i < 12; i++)
	{
		attempts.push_back(attempts_arr[i]);
	}
	cout << "result: " << incorrectPasscodeAttempts("1111", attempts) << endl;

	cout << "Hello world!" << endl;
    return 0;
}

