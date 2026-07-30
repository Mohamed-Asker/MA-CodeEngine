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


short CountEachWordInstring(std::string Text)
{
	std::string delimt = " ";
	std::string sWord;
	short Pos = 0;
	short Counter = 0;

	while ((Pos = Text.find(delimt)) != std::string::npos)
	{
		sWord = Text.substr(0, Pos);
		if (sWord != "")
		{
			Counter++;
		}
		Text.erase(0, Pos + delimt.length());
	}

	if (Text != "")
	{
		Counter++;
	}
	return Counter;
}

int main()
{
	std::string Text;
	Text = ReadText("Enter any text");
	std::cout << "\nThe number of words in your string: ";
	std::cout << CountEachWordInstring(Text) << std::endl;
	return 0;
}