//My Solution
#include <iostream>
#include <string>
#include <cctype>
#include <vector>


struct stClientData
{
	std::string name = "";
	std::string phone = "";
	std::string PinCode = "";
	std::string accNumber = "";
	double accBalance = 0;
};


stClientData ReadNewClient()
{
	stClientData client;

	std::cout << "Account number: ";
	std::getline(std::cin, client.accNumber);
	std::cout << "Pin code: ";
	std::getline(std::cin, client.PinCode);
	std::cout << "Name: ";
	std::getline(std::cin, client.name);
	std::cout << "Phone: ";
	std::getline(std::cin, client.phone);
	std::cout << "Account balance: ";
	std::cin >> client.accBalance;

	return client;
}

std::string ConvertRecodToLine(stClientData& client, const std::string& delimiter = " ")
{
	std::string text = "";

	text += client.accNumber + delimiter;
	text += client.PinCode + delimiter;
	text += client.name + delimiter;
	text += client.phone + delimiter;
	text += std::to_string(client.accBalance);

	return text;
}

int main()
{

	stClientData Client;
	Client = ReadNewClient();
	
	std::cout << "Client record for saving is: \n";
	std::cout << ConvertRecodToLine(Client, "#//#") << "\n";

	return 0;
}