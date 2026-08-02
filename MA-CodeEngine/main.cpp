//My Solution
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iomanip>
#include <fstream>

const std::string& ClientsFileName = "ClientsData.txt";

struct stClientData
{
	std::string name = "";
	std::string accNumber = "";
	std::string phone = "";
	std::string PinCode = "";
	double accBalance = 0;
};

stClientData ReadClientData()
{
	stClientData client;

	std::cout << "Account Number: ";
	std::getline(std::cin >> std::ws, client.accNumber);
	std::cout << "Pin Code: ";
	std::getline(std::cin, client.PinCode);
	std::cout << "Name: ";
	std::getline(std::cin, client.name);
	std::cout << "Phone: ";
	std::getline(std::cin, client.phone);
	std::cout << "Account balance: ";
	std::cin >> client.accBalance;

	return client;
}

std::string ConvertRecodToLine(const stClientData& client, const std::string& delimiter)
{
	std::string text;

	text += client.accNumber + delimiter;
	text += client.PinCode + delimiter;
	text += client.name + delimiter;
	text += client.phone + delimiter;
	text += std::to_string(client.accBalance);

	return text;
}

void AddClientsToFile(const std::string& text)
{
	std::fstream file;
	file.open(ClientsFileName, std::ios::out | std::ios::app);

	if (file.is_open())
	{
		file << text << "\n";
		file.close();
	}
}

void AddNewClient()
{
	stClientData client;
	client = ReadClientData();
	AddClientsToFile(ConvertRecodToLine(client, "#//#"));
}

void AddClients()
{
	char AddMore = 'Y';
	do
	{
		system("cls");
		AddNewClient();

		std::cout << "\nClient added successfully.";
		std::cout << "\nDo yo want to add more clients[Y,N]: ";
		std::cin >> AddMore;

	} while (std::tolower(AddMore) == 'y');
}

int main()
{
	AddClients();
	return 0;
}