//My Soluation
#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

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

std::vector <std::string> split(std::string& line,const std::string delimiter = " ")
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


stClientData ConvertLineToRecord(std::string& line,const std::string& delimiter = " ")
{
	stClientData client;
	std::vector <std::string> vClientRecord;
	vClientRecord = split(line, delimiter);

	client.accNumber = vClientRecord[0];
	client.PinCode = vClientRecord[1];
	client.name = vClientRecord[2];
	client.phone = vClientRecord[3];
	client.accBalance = std::stod(vClientRecord[4]);

	return client;
}

std::vector <stClientData> LoadDataFromFileToVector(const std::string& FileName) 
{
	std::vector <stClientData> vClients;
	std::fstream file;

	file.open(FileName, std::ios::in);
	if (file.is_open())
	{
		stClientData client;
		std::string line;

		while (std::getline(file, line))
		{
			client = ConvertLineToRecord(line, ::delimiter);
			vClients.push_back(client);
		}
		file.close();
	}
	return vClients;
}

std::string ReadAccountNumber()
{
	std::string accNumber;
	std::cout << "Enter Account Number: ";
	std::getline(std::cin, accNumber);

	return accNumber;
}

bool FindClientByAccountNumber(std::vector <stClientData>& vClients, stClientData& client, const std::string& accNumber)
{
	for (const stClientData& tempClient : vClients)
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
	std::cout << "\nThe following are the client details: ";
	std::cout << std::left << std::setw(18) << "\nAccount Number" << ": " << client.accNumber;
	std::cout << std::left << std::setw(18) << "\nPin Code" << ": " << client.PinCode;
	std::cout << std::left << std::setw(18) << "\nName" << ": " << client.name;
	std::cout << std::left << std::setw(18) << "\nPhone" << ": " << client.phone;
	std::cout << std::left << std::setw(18) << "\nAccount Balance" << ": " << client.accBalance;
	std::cout << std::endl;
}

stClientData ChangeClientRecord(const std::string& accNumber)
{
	stClientData client;

	client.accNumber = accNumber;

	std::cout << "Enter new pin code        : ";
	std::getline(std::cin, client.PinCode);
	std::cout << "Enter new name            : ";
	std::getline(std::cin, client.name);
	std::cout << "Enter new phone           : ";
	std::getline(std::cin, client.phone);
	std::cout << "Enter new Account balance : ";
	std::cin >> client.accBalance;

	return client;
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

std::vector <stClientData> SaveVectorToFile(std::vector <stClientData>& vClients,const std::string& FileName)
{
	std::fstream file;
	std::string DataLine;

	file.open(FileName, std::ios::out);
	if (file.is_open())
	{
		for (const stClientData client : vClients)
		{
			if (client.MarkForDelete == false)
			{
				DataLine = ConvertRecordToLine(client, ::delimiter);
				file << DataLine << std::endl;
			}
		}
		file.close();
	}
	return vClients;
}

bool UpdateClientByAccountNumber(std::vector <stClientData>& vClients, const std::string& accNumber)
{
	stClientData client;
	char answer;

	if (FindClientByAccountNumber(vClients, client, accNumber))
	{
		PrintClientCard(client);
		std::cout << "\nAre you sure you want to update this client[Y,N]: ";
		std::cin >> answer;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (std::tolower(answer) == 'y')
		{
			for (stClientData& tempClient : vClients)
			{
				if (tempClient.accNumber == accNumber)
				{
					tempClient = ChangeClientRecord(accNumber);
					break;
				}
			}
			SaveVectorToFile(vClients, ::ClientsFileName);
			std::cout << "\nClient updated successfully. " << std::endl;
			return true;
		}
		return false;
	}
	else
	{
		std::cout << "Client with account number (" << accNumber << ") not found." << std::endl;
		return false;
	}
}

int main()
{
	std::vector <stClientData> vClients;
	vClients = LoadDataFromFileToVector(::ClientsFileName);
	char answer;
	do 
	{
		std::string accNumber = ReadAccountNumber();
		UpdateClientByAccountNumber(vClients, accNumber);
		std::cout << "Do you want to update another client: ";
		std::cin >> answer;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("cls");

	} while (answer == 'y' || answer == 'Y');

	return 0;
}