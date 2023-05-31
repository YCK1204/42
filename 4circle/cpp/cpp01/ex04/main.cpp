/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:05:19 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/13 18:44:01 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::ifstream					infile;
std::ofstream					outfile;

int	err(std::string msg)
{
	std::cerr << msg << std::endl;
	infile.close();
	outfile.close();
	return (1);
}

int main(int ac, char **av)
{
	std::string						s1;
	std::string						s2;
	std::string						str;
	std::size_t						len;
	int								s2_len;

	if (ac != 4)
		return (err("argument number error"));
	s1 = static_cast<std::string>(av[2]);
	s2 = static_cast<std::string>(av[3]);
	infile.open(av[1]);
	if (infile.is_open())
	{
		if (!s1.length())
			return (err("s1 error"));
		outfile.open(static_cast<std::string>(av[1]) + ".replace");
		s2_len = s2.length();
		while (1)
		{
			getline(infile, str);
			if (infile.eof())
				break ;
			len = 0;
			while (1)
			{
				len = str.find(s1, len);
				if (len == std::string::npos)
					break ;
				str.erase(len, s1.length());
				str.insert(len, s2);
				len += s2_len;
			}
			str += "\n";
			outfile.write(str.c_str(), str.length());
		}
	}
	else
		return (err("infile error"));
	infile.close();
	outfile.close();
	return (0);
}
