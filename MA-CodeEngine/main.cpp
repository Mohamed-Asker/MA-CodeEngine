//My Solution
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iomanip>
#include <fstream>

struct stClientData
{
	std::string name = "";
	std::string accNumber = "";
	std::string pinCode = "";
	std::string phone = "";
	double accBalance = 0;
};

const std::string& ClientsFileName = "ClientsData.txt";


std::vector <std::string> split(std::string text, const std::string delimiter = " ")
{
	int pos = 0; 
	std::string sWord = "";
	std::vector <std::string> vTokens;

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

stClientData ConvertLineToRecord(const std::string& line, const std::string& delimiter)
{
	stClientData client;
	std::vector <std::string> vClientData;
	vClientData = split(line, delimiter);

	client.accNumber = vClientData[0];
	client.pinCode = vClientData[1];
	client.name = vClientData[2];
	client.phone = vClientData[3];
	client.accBalance = std::stod(vClientData[4]);

	return client;
}

std::vector <stClientData> LoadDataFromFileToVector(const std::string& FileName)
{
	std::vector <stClientData> vClientsData;
	std::fstream file;
	file.open(FileName, std::ios::in);

	if (file.is_open())
	{
		std::string line;
		stClientData client;

		while (std::getline(file, line))
		{
			client = ConvertLineToRecord(line, "#//#");
			vClientsData.push_back(client);
		}
		file.close();
	}
	return vClientsData;
}

void PrintClientData(const stClientData& client)
{
	std::cout << "|" << std::left << std::setw(20) << client.accNumber;
	std::cout << "|" << std::left << std::setw(18) << client.pinCode;
	std::cout << "|" << std::left << std::setw(40) << client.name;
	std::cout << "|" << std::left << std::setw(20) << client.phone;
	std::cout << "|" << std::left << std::setw(14) << client.accBalance << "|";
}

void ShowAllClients(std::vector <stClientData>& vClientsData)
{
	std::cout << "\n\n\t\t\t\t\t\t Clients list (" << vClientsData.size() << ") (s) \n";
	std::cout << "----------------------------------------------------------------------------------------------------------------------\n";
	std::cout << "|" << std::left << std::setw(20) << "Account Number" << "|";
	std::cout << std::left << std::setw(18) << "Pin Code" << "|";
	std::cout << std::left << std::setw(40) << "Client Name" << "|";
	std::cout << std::left << std::setw(20) << "Phone" << "|";
	std::cout << std::left << std::setw(14) << "Balance" << "|";
	std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";

	for (stClientData& client : vClientsData)
	{
		PrintClientData(client);
		std::cout << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;
}

int main()
{
	std::vector <stClientData> vClientData = LoadDataFromFileToVector(ClientsFileName);
	ShowAllClients(vClientData);


	return 0;
}