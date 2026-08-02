//My Solution
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iomanip>


struct stClient
{
	std::string name = "";
	std::string accNumber = "";
	std::string pinCode = "";
	std::string phone = "";
	double accBalance = 0;
};

std::vector <std::string> split(std::string& text, const std::string& delimiter)
{
	std::vector <std::string> vTokens;
	std::string sWord = "";
	int pos = 0;

	while ((pos = text.find(delimiter)) != std::string::npos)
	{
		sWord = text.substr(0, pos);

		if (sWord != "")
		{
			vTokens.push_back(sWord);
		}

		text.erase(0, pos + delimiter.length());
	}

	if (text != delimiter)
	{
		vTokens.push_back(text);
	}
	return vTokens;
}

stClient ConvertLineToRecord(std::string text, const std::string& delimiter = " ")
{
	stClient client;
	std::vector <std::string > vClientData;
	vClientData = split(text, delimiter);

	client.accNumber = vClientData[0];
	client.pinCode = vClientData[1];
	client.name = vClientData[2];
	client.phone = vClientData[3];
	client.accBalance = std::stod(vClientData[4]);

	return client;
}

void PrintClientData(const stClient& client)
{
	std::cout << "\n\nThe followig is extracted client record:-";
	std::cout << std::left << std::setw(15) << "\nAccount Number" << ": " << client.accNumber;
	std::cout << std::left << std::setw(15) << "\nPin Code" << ": " << client.pinCode;
	std::cout << std::left << std::setw(15) << "\nName" << ": " << client.name;
	std::cout << std::left << std::setw(15) << "\nPhone" << ": " << client.phone;
	std::cout << std::left << std::setw(15) << "\nAccent balance" << ": " << client.accBalance << std::endl;
}

int main()
{
	stClient client;
	std::string text = "A150#//#1234#//#Mohamed Askar#//#0145928125#//#20000";
	client = ConvertLineToRecord(text, "#//#");

	std::cout << "Line record is: \n" << text;
	PrintClientData(client);


	return 0;
}