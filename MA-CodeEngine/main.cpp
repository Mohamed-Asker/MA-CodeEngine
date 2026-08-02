//My Solution.
#include <iostream>
#include <cctype>
#include <string>
#include <vector>

std::string ReadText(const std::string& msg)
{
	std::string text;
	std::cout << msg << ": ";
	std::getline(std::cin, text);

	return text;
}

std::string Replace(std::string text, int pos, int count, std::string NewText)
{
	std::string repText = "";

	for (int i = 0; i < pos; i++)
	{
		repText += text.at(i);
	}

	repText += NewText;

	for (int i = pos + count; i < text.length(); i++)
	{
		repText += text.at(i);
	}

	return repText;
}

std::string ReplaceAll(std::string text, const std::string& OldWord, const std::string& NewWord)
{
	int pos = 0;
	while ((pos = text.find(OldWord)) != std::string::npos)
	{
		text = Replace(text, pos, OldWord.length(), NewWord);
		pos += NewWord.length();
	}
	return text;
}

int main()
{
	std::string text = "Hi Egypt how are you in this days Egypt is very nice";

	std::cout << "Text before replace: \n";
	std::cout << text << "\n";
	
	text = ReplaceAll(text, "Egypt", "Spain");

	std::cout << "\nText after replace: \n";
	std::cout << text << std::endl;
}