/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:20:13 by ddraco            #+#    #+#             */
/*   Updated: 2021/01/21 18:11:39 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

std::string replacement(std::string s, const std::string &search, const std::string &replace)
{
	std::string result = "";
	int search_index;

	for (int i = 0; i < (int)s.length(); i++)
	{
		search_index = 0;
		while(s[i + search_index] == search[search_index] && search_index < (int)search.length())
			search_index++;
		if (search_index == (int)search.length())
		{
			result.append(replace);
			i += (search_index - 1);
		}
		else
			result += s[i];
	}
	return (result);
}

int main(int argc, char **argv)
{
	std::ifstream fin;
	std::ofstream fout;
	std::string s;

	if (argc == 4)
	{
		try
        {
            if (strlen(argv[1]) == 0)
                throw "Bad filename.";
            else if (strlen(argv[2]) == 0)
                throw "Bad search string.";
            else if (strlen(argv[3]) == 0)
                throw "Bad replace string.";
            fin.open(argv[1]);
	        if (!fin.is_open())
		        throw "Bad input file.";
            fout.open(std::string(argv[1]) + ".replace", std::ios::trunc);
            if (!fout.is_open())
		        throw "Bad output file.";
            while (std::getline(fin, s))
            {
                fout << replacement(s, argv[2], argv[3]);
                if (!fin.eof())
                    fout << '\n';
            }
        }
        catch(const char* exception)
        {
            std::cerr << "err: " << exception << '\n';
        }
	}
	else
		std::cout << "error: Invalid number of arguments.\n";
	fin.close();
	fout.close();
}