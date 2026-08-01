//My Solution
#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <vector>


std::string ReadText(const std::string& Msg)
{
	std::string Text;
	std::cout << Msg << ": ";
	std::getline(std::cin, Text);

	return Text;
}

std::string JoinString(std::vector <std::string> vTokens,const  std::string& delimiter)
{
	std::string Text = "";

	for (std::string& Token : vTokens)
	{
		Text = Text + Token + delimiter;
	}

	return Text.substr(0, Text.length() - delimiter.length());
}

std::string JoinString(std::string Tokens[100], int ArrLength,const std::string& delimiter)
{
	std::string Text;
	for (int i = 0; i < ArrLength; i++)
	{
		Text = Text + Tokens[i] + delimiter;
	}

	return Text.substr(0, Text.length() - delimiter.length());
}

int main()
{
	std::vector <std::string> vTokens;
	std::string Tokens[5] = { "Mohamed" ,"Ahmed" ,"Mahmoud" ,"Hessan" ,"Askar" };

	vTokens.push_back("Mohamed");
	vTokens.push_back("Ahmed");
	vTokens.push_back("Mahmoud");
	vTokens.push_back("Hessan");
	vTokens.push_back("Askar");

	std::cout << "Vector after join: \n";
	std::cout << JoinString(vTokens, "\\") << "\n";

	std::cout << "\nArray after join: \n";
	std::cout << JoinString(Tokens, 5, "\\") << "\n";

	system("pause > 0");
	return 0;
}