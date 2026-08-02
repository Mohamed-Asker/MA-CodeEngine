#include <iostream>
#include <cctype>
#include <string>
#include <vector>


std::vector <std::string> split(std::string text, const std::string& delimiter)
{
	int pos = 0;
	std::vector <std::string> vTokens;
	std::string sWord;

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

std::string LowerAllString(std::string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		text.at(i) = std::tolower(text.at(i));
	}
	return text;
}

std::string JoinString(std::vector <std::string> vTokens, const std::string& delimiter)
{
	std::string text = "";
	for (std::string& token : vTokens)
	{
		text += (token + delimiter);
	}
	return text.substr(0, text.length() - delimiter.length());
}


std::string ReplaceWordInStringUsingSplit(std::string text, const  std::string& OldWord, const std::string& NewWord, bool MatchCase = true)
{
	std::vector <std::string> vTokens;
	vTokens = split(text, " ");

	for (std::string& token : vTokens)
	{
		if (MatchCase)
		{
			if (token == OldWord)
			{
				token = NewWord;
			}
		}
		else
		{
			if (LowerAllString(token) == LowerAllString(OldWord))
			{
				token = NewWord;
			}
		}
	}
	return JoinString(vTokens, " ");
}

int main()
{
	std::string text = "Welcome to spain , spain is a nice country";
	std::string OldWord = "Spain";
	std::string NewWord = "Egypt";

	std::cout << "text before replace: \n" << text << "\n";

	std::cout << "\nReplace with match case: \n";
	std::cout << ReplaceWordInStringUsingSplit(text, OldWord, NewWord) << "\n";
	
	std::cout << "\nReplace with don't match case: \n";
  	std::cout << ReplaceWordInStringUsingSplit(text, OldWord, NewWord, false) << "\n";

	return 0;
}