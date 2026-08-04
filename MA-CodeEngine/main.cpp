//My Soluation
#include <iostream>
#include <string >
#include <cctype>
#include <vector>
#include <fstream>
#include <iomanip>

const std::string ClientsFileName = "ClientsData.txt";
const std::string delimiter = "#//#";

struct stClientData
{
	std::string accNumber = "";
	std::string PinCode = "";
	std::string name = "";
	std::string phone = "";
	double accBalance = 0;
	bool MarkForDelete = false;
};

std::vector < std::string> split(std::string& line, const std::string delimiter = " ")
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

stClientData ConvertLineToRecord(std::string& line, const std::string& delimiter = " ")
{
	stClientData client;
	std::vector <std::string> vTokens;
	vTokens = split(line, delimiter);

	client.accNumber = vTokens.at(0);
	client.PinCode = vTokens.at(1);
	client.name = vTokens.at(2);
	client.phone = vTokens.at(3);
	client.accBalance = std::stod(vTokens.at(4));
	
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
			client = ConvertLineToRecord(line, ::delimiter);
			vClientsData.push_back(client);
		}
		file.close();
	}
	return vClientsData;
}

std::string ReadAccountNumber()
{
	std::string accNumber;
	std::cout << "Enter Account Number: ";
	std::getline(std::cin, accNumber);
	
	return accNumber;
}

bool FindClientByAccountNumber(const std::vector <stClientData>& vClientsData, stClientData& client, const std::string& accNumber)
{
	for (stClientData tempClient : vClientsData)
	{
		if (tempClient.accNumber == accNumber)
		{
			client = tempClient;
			return true;
		}
	}
	return false;
}

void PrintClientCard(const stClientData& client)
{
	std::cout << "\nThe following are the clients detalise: ";
	std::cout << std::left << std::setw(18) << "\nAccount Number" << ": " << client.accNumber;
	std::cout << std::left << std::setw(18) << "\nPin Code" << ": " << client.PinCode;
	std::cout << std::left << std::setw(18) << "\nName" << ": " << client.name;
	std::cout << std::left << std::setw(18) << "\nPhone" << ": " << client.phone;
	std::cout << std::left << std::setw(18) << "\nAccount Balance" << ": " << client.accBalance;
}

bool MarkClientForDeleteByAccountNumber(std::vector <stClientData>& vClientsData, const std::string& accNumber)
{
	for (stClientData& tempClient : vClientsData)
	{
		if (tempClient.accNumber == accNumber)
		{
			tempClient.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

std::string ConvertRecordToLine(const stClientData& client, const std::string& delimiter)
{
	std::string line = "";

	line += (client.accNumber + delimiter);
	line += (client.PinCode + delimiter);
	line += (client.name + delimiter);
	line += (client.phone + delimiter);
	line += std::to_string(client.accBalance);

	return line;
}

std::vector <stClientData> SaveVectorToFile(std::vector <stClientData>& vClientsData, const std::string& FileName)
{
	std::string DataLine;
	std::fstream file;
	file.open(FileName, std::ios::out);

	if (file.is_open())
	{
		for (const stClientData& tempClient : vClientsData)
		{
			if (tempClient.MarkForDelete == false)
			{
				DataLine = ConvertRecordToLine(tempClient, ::delimiter);
				file << DataLine << std::endl;
			}
		}
		file.close();
	}
	return vClientsData;
}

bool DeleteClientByAccountNumber(std::vector <stClientData>& vClientsData, const std::string& accNumber)
{
	stClientData client;
	char answer;
	
	if (FindClientByAccountNumber(vClientsData, client, accNumber))
	{
		PrintClientCard(client);
		std::cout << "\n\nAre you sure you want to delete thie client[Y,N]: ";
		std::cin >> answer;

		if (std::tolower(answer) == 'y')
		{
			MarkClientForDeleteByAccountNumber(vClientsData, accNumber);
			SaveVectorToFile(vClientsData, ::ClientsFileName);
			vClientsData = LoadDataFromFileToVector(::ClientsFileName);

			std::cout << "Clients deleted successfull." << std::endl;
			return true;
		}

	}
	else
	{
		std::cout << "Client with account number not found." << std::endl;
		return false;
	}

}

int main()
{
	std::vector <stClientData> vClientsData;
	vClientsData = LoadDataFromFileToVector(ClientsFileName);
	std::string accNumber = ReadAccountNumber();
	DeleteClientByAccountNumber(vClientsData, accNumber);

	return 0;
}