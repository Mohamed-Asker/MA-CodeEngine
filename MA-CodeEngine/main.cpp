//My Solution
#include <iostream>
#include <cctype>
#include <string>
#include <vector>

std::string ReadText(const std::string& Msg)
{
	std::string Text;
	std::cout << Msg << ": ";
	std::getline(std::cin, Text);
	return Text;
}

std::vector <std::string> split(std::string text, const std::string& delimiter)
{
	std::vector <std::string> vTokens;
	std::string sWord;
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

std::string ReverseWords(std::vector <std::string> vTokens, const std::string& delimiter)
{
	std::string text = "";
	while (!vTokens.empty())
	{
		text = text + vTokens.back() + delimiter;
		vTokens.pop_back();
	}
	return text.substr(0, text.length() - delimiter.length());
}

int main()
{
	std::vector <std::string> vTokens;
	std::string text;

	text = ReadText("Enter your text");
	vTokens = split(text, " ");
	text = ReverseWords(vTokens, " ");

	std::cout << "\nString after reverseing words: \n";
	std::cout << text << "|" << std::endl;

	system("pause > 0");

	return 0;
}