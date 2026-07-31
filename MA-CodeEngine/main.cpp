#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>


std::string ReadText(const std::string& Msg)
{
	std::string Text;
	std::cout << Msg << ": ";
	std::getline(std::cin, Text);

	return Text;
}

std::string TrimLeft(std::string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ')
		{
			return Text.substr(i, Text.length() - 1);
		}
	}
	return "";
}

std::string TrimRight(std::string Text)
{
	for (int i = Text.length() - 1; i >= 0; i--)
	{
		if (Text[i] != ' ')
		{
			return Text.substr(0, i + 1);
		}
	}
	return "";
}

std::string Trim(std::string Text)
{
	return TrimRight(TrimLeft(Text));
}


int main()
{
	std::string Text;
	Text = "    Mohamed Askar    ";

	std::cout << std::left << std::setw(15) << "Trim left" << ": " << TrimLeft(Text) << "|\n";
	std::cout << std::left << std::setw(15) << "Trim rigth" << ": " << TrimRight(Text) << "|\n";
	std::cout << std::left << std::setw(15) << "Trim" << ": " << Trim(Text) << "|\n";
	
	return 0;
}