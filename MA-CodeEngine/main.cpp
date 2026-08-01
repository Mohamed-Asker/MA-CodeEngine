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

std::string ReverseWordsInString(std::string text1, const std::string& delimiter)
{
	std::string text2 = "";
	std::vector <std::string > vTokens;
	vTokens = split(text1, delimiter);

	std::vector <std::string>::iterator iter = vTokens.end();

	while (iter != vTokens.begin())
	{
		iter--;
		text2 = text2 + *iter + delimiter;
	}
	return text2.substr(0, text2.length() - delimiter.length());
}

int main()
{
	
	std::string text;
	text = ReadText("Enter your text");
	text = ReverseWordsInString(text, " ");

	std::cout << "\nString after reverseing words: \n";
	std::cout << text << "|" << std::endl;

	system("pause > 0");

	return 0;
}