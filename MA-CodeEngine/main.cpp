//My Solution
#include <iostream>
#include <string>
#include <cctype>
#include <vector>


std::string RemovePunctuation(std::string text)
{
	std::string text2;
	for (int i = 0; i < text.length(); i++)
	{
		if (!std::ispunct(text.at(i)))
		{
			text2 += text.at(i);
		}
	}
	return text2;
}
int main()
{
	std::string text = "Welcome to spain, Spain is a nice countey;Spain is very amazing.";

	std::cout << "Original text: \n";
	std::cout << text << "\n";

	std::cout << "\ntext after remove punctuation: \n";
	std::cout << RemovePunctuation(text) << "\n";

	system("pause > 0");
	return 0;
}