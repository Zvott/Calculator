#pragma once

#include <iostream>
#include <string>
#include <vector>

bool isoperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

bool store_values(std::vector<std::string>& vector, const std::string& str)
{
	std::string temp_str;
	for (size_t index = 0, i = 0; i < str.length(); i++)
	{
		if (std::isdigit(str[i]) || str[i] == '.')
		{
			temp_str += str[i];
			if (std::isdigit(str[i + 1]) || str[i + 1] == '.')
			{
				continue;
			}
			else
			{
				vector.push_back(temp_str);
				temp_str = "";
			}
		}
		else if (str[i] == '*' && std::isdigit(str[i + 1]))
		{
			vector.push_back("*");
		}
		else if (str[i] == '/' && std::isdigit(str[i + 1]))
		{
			vector.push_back("/");
		}
		else if (str[i] == '+' && std::isdigit(str[i + 1]))
		{
			vector.push_back("+");
		}
		else if (str[i] == '-' && std::isdigit(str[i + 1]))
		{
			if (i == 0 || isoperator(str[i - 1]))
			{
				temp_str += str[i];
			}
			else
				vector.push_back("-");
		}
		else
		{
			std::cout << "Type a valid expression." << std::endl;
			return false;
		}
	}

	if (vector.size() < 3)
	{
		std::cout << "Type a valid expression." << std::endl;
		return false;
	}

	return true;
}

void get_result(std::vector<std::string>& vector)
{
	size_t map_size = vector.size();

	for (size_t i = 0; i < map_size; i++)
	{
		if (i <= map_size && vector[i] == "*")
		{
			vector[i] = std::to_string(std::stod(vector[i - 1]) * std::stod(vector[i + 1]));
			vector.erase(vector.begin() + i - 1);
			vector.erase(vector.begin() + i);
			i--;
		}
		else if (i <= map_size && vector[i] == "/")
		{
			vector[i] = std::to_string(std::stod(vector[i - 1]) / std::stod(vector[i + 1]));
			vector.erase(vector.begin() + i - 1);
			vector.erase(vector.begin() + i);
			i--;
		}
		map_size = vector.size();
	}

	for (size_t i = 0; i < map_size; i++)
	{
		if (i <= map_size && vector[i] == "+")
		{
			vector[i] = std::to_string(std::stod(vector[i - 1]) + std::stod(vector[i + 1]));
			vector.erase(vector.begin() + i - 1);
			vector.erase(vector.begin() + i);
			i--;
		}
		else if (i <= map_size && vector[i] == "-")
		{
			vector[i] = std::to_string(std::stod(vector[i - 1]) - std::stod(vector[i + 1]));
			vector.erase(vector.begin() + i - 1);
			vector.erase(vector.begin() + i);
			i--;
		}
		map_size = vector.size();
	}
}
