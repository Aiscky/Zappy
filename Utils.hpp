//
// Utils.hpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/client_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Tue Jun 16 16:47:04 2015 Thibault WOIVRE
// Last update Tue Jun 30 17:08:48 2015 Thibault WOIVRE
//

#ifndef			UTILS_HH
#define			UTILS_HH

#include		"./include/includeGraphic.hh"

class			Utils {

public:

	static bool             				isNumber(const std::string &str) {
		int                   i = 0;

		while (str[i]) {
			if (str[i] < '0' || str[i] > '9') {
				return (false);
			}
			i++;
		}
		return (true);
	}

	template<typename T>
	static T								max(T a, T b) {
		if (a > b)
			return (a);
		else
			return (b);
	}

	template<typename T>
	static T								min(T a, T b) {
		if (a < b)
			return (a);
		else
			return (b);
	}


	static std::string                    	intToString(int nb) {
		std::stringstream                   ss;

		ss << nb;
		return (ss.str());
	}

	static int								stringToInt(std::string &str) {
		std::stringstream                   ss;
		int					nb;

		ss << str;
		ss >> nb;
		return (nb);
	}


	static std::vector<std::string>       *split(std::string str, std::string sep) {
		char*                               cstr=const_cast<char*>(str.c_str());
		char*                               current;
		std::vector<std::string>            *arr = new std::vector<std::string>();

		current = strtok(cstr,sep.c_str());
		while (current != NULL){
			arr->push_back(current);
			current = strtok(NULL, sep.c_str());
		}
		return arr;
	}

	static float				cartesianToIsoX(float x, float y) {
		return (x - y);
	}

	static float				cartesianToIsoY(float x, float y) {
		return ((x + y) / 2);
	}

	static float				isoToCartesianX(float x, float y) {
		return (2 * y + x) / 2;
	}

	static float				isoToCartesianY(float x, float y) {
		return (2 * y - x) / 2;
	}

	static bool					RectInRect(const sf::FloatRect &inRect, const sf::FloatRect &outRect) {
		if (inRect.Top < outRect.Top)
			return (false);
		if (inRect.Bottom > outRect.Bottom)
			return (false);
		if (inRect.Right > outRect.Right)
			return (false);
		if (inRect.Left < outRect.Left)
			return (false);
		return (true);
	}
};

#endif
