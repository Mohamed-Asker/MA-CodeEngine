//My Soluation
#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

const std::string ClientsFileName = "ClientsData.txt";


std::string ReadText(const std::string& msg)
{
	std::string text;
	std::cout << msg << ": ";
	std::getline(std::cin, text);

	return text;
}
struct stClientData
{
	std::string accNumber = "";
	std::string PinCode = "";
	std::string name = "";
	std::string phone = "";
	double accBalance = 0;
};

std::vector <std::string> split(std::string& line, const std::string& delimiter = " ")
{
	std::vector <std::string> vTokens;
	std::string sWord = "";
	int pos = 0;

	while ((pos = line.find(delimiter)) != std::string::npos)
	{
		sWord = line.substr(0, pos);
		if (sWord != "")
		{
			vTokens.push_back(sWord);
		}
		line.erase(0, pos + delimiter.length());
	}

	if (line != delimiter)
	{
		vTokens.push_back(line);
	}
	return vTokens;
}

stClientData ConvertFormLineToRecord(std::string& line, const std::string& delimiter = " ")
{
	stClientData client;
	std::vector <std::string> vClientsData;
	vClientsData = split(line, delimiter);

	client.accNumber = vClientsData.at(0);
	client.PinCode = vClientsData.at(1);
	client.name = vClientsData.at(2);
	client.phone = vClientsData.at(3);
	client.accBalance = std::stod(vClientsData.at(4));

	return client;
}

std::vector <stClientData> LoadDataFromFileToVector(const std::string& FileName)
{
	std::vector <stClientData> vClientsData;
	std::fstream file;

	file.open(FileName, std::ios::in);
	if (file.is_open())
	{
		stClientData client;
		std::string line;

		while (std::getline(file, line))
		{
			client = ConvertFormLineToRecord(line, "#//#");
			vClientsData.push_back(client);
		}
		file.close();
	}
	return vClientsData;
}

void PrintClient(stClientData client)
{
	std::cout << "|" << std::left << std::setw(20) << client.accNumber;
	std::cout << "|" << std::left << std::setw(18) << client.PinCode;
	std::cout << "|" << std::left << std::setw(40) << client.name;
	std::cout << "|" << std::left << std::setw(20) << client.phone;
	std::cout << "|" << std::left << std::setw(14) << client.accBalance << "|";
}


void PrintAllClientsData(const std::vector <stClientData>& vClientsData)
{
	std::cout << "\n\n \t\t\t\t\t\t Clients list (" << vClientsData.size() << ")(s) \n";
	std::cout << "----------------------------------------------------------------------------------------------------------------------\n";
	std::cout << "|" << std::left << std::setw(20) << "Account Number";
	std::cout << "|" << std::left << std::setw(18) << "Pin Code";
	std::cout << "|" << std::left << std::setw(40) << "Client Name";
	std::cout << "|" << std::left << std::setw(20) << "Phone";
	std::cout << "|" << std::left << std::setw(14) << "Balance" << "|\n";
	std::cout << "----------------------------------------------------------------------------------------------------------------------\n";

	for (const stClientData& client : vClientsData)
	{
		PrintClient(client);
		std::cout << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------------------------------------------------\n";
}



void PrintClientCard(const stClientData& client)
{
	std::cout << "\nThe following are the clients details: ";
	std::cout << std::left << std::setw(15) << "\nAccount Number" << ": " << client.accNumber;
	std::cout << std::left << std::setw(15) << "\nPin Code" << ": " << client.PinCode;
	std::cout << std::left << std::setw(15) << "\nName" << ": " << client.name;
	std::cout << std::left << std::setw(15) << "\nPhone" << ": " << client.phone;
	std::cout << std::left << std::setw(15) << "\nBalance" << ": " << client.accBalance;
}

bool FindClientByAccountNumber(stClientData& client, const std::string& accNumber)
{
	std::vector <stClientData> vClientsData = LoadDataFromFileToVector(ClientsFileName);
	for (stClientData& C : vClientsData)
	{
		if (C.accNumber == accNumber)
		{
			client = C;
			return true;
		}
	}
	return false;
}

int main()
{
	std::string accNumber = ReadText("Enter account number");
	stClientData client;

	if (FindClientByAccountNumber(client, accNumber))
	{
		PrintClientCard(client);
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Client with Account number (" << accNumber << ") not found.";
		std::cout << std::endl;
	}

	return 0;
}