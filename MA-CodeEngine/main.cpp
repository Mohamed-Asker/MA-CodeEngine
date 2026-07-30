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

std::vector <std::string> Split(std::string Text, std::string delimt)
{
	short Pos = 0;
	std::string sWord;
	std::vector <std::string> Tokens;
	while ((Pos = Text.find(delimt)) != std::string::npos)
	{
		sWord = Text.substr(0, Pos);
		if (sWord != "")
		{
			Tokens.push_back(sWord);
		}
		Text.erase(0, Pos + delimt.length());
	}

	if (Text != delimt)
	{
		Tokens.push_back(Text);
	}
	return Tokens;
}

void PrintVector(std::vector <std::string> Content)
{
	for (std::string& Token : Content)
	{
		std::cout << Token << "\n";
	}
}

int main()
{
	std::string Text;
	Text = ReadText("Enter any text");
	std::vector <std::string> Content;

	Content = Split(Text, ",");
	std::cout << "\nTokens = " << Content.size() << "\n";
	PrintVector(Content);

	

	return 0;
}