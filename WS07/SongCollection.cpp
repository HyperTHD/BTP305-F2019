// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 06/11/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "SongCollection.h"

namespace sdds
{
	SongCollection::SongCollection(const char* filename)
	{
		std::ifstream file(filename);

		if (!file)
			std::cerr << "Error! Cannot open: " << filename << std::endl;
		else
		{
			std::string temp{};

			while (std::getline(file, temp))
			{
				m_songs.push_back(extractToken(temp));
			}
			file.close();
		}
	}

	Song SongCollection::extractToken(const std::string str)
	{
		Song newSong;
		std::string temp = str;
		size_t new_pos = 0; // record position of last non-whitespace character

		/*
			This function will extract the tokens, and return that so it can be pushed to the vector.
			The first 3 strings can potentially have spaces in between so they have to be done differently, rest can be done in a similar manner
			Have new_pos be the position of the last non-whitespace character for each attribute, extract them, and store them
			3rd line has a space at the beginning so if checks for that, then erases that character only using string iterator .begin()
		*/

		std::string fullattribute{};
		std::string arr[6];

		for (size_t i = 0; i < 3; ++i)
		{
			fullattribute = temp.substr(0, 25);
			new_pos = fullattribute.find_last_not_of(" ");
			arr[i] = fullattribute.substr(0, new_pos + 1);
			temp.erase(0, 25);
		}

		if (arr[0].at(0) == ' ')
			arr[0].erase(arr[0].begin());

		newSong.m_title = arr[0];
		newSong.m_artist = arr[1];
		newSong.m_album = arr[2];

		for (size_t i = 3; i < 6; ++i)
		{
			fullattribute = temp.substr(0, 5);
			new_pos = fullattribute.find_last_not_of(" ");
			arr[i] = fullattribute.substr(0, new_pos + 1);
			temp.erase(0, 5);
		}

		newSong.m_year = arr[3];
		newSong.m_length = stoi(arr[4]);
		newSong.m_price = stod(arr[5]);

		return newSong;
	}


	void SongCollection::display(std::ostream& os) const
	{
		for_each(m_songs.begin(), m_songs.end(), [&os](const Song& theSong) {
			os << theSong;
		});
	}

	
	std::ostream& operator<<(std::ostream& os, const Song& theSong)
	{
		size_t minutes = theSong.m_length / 60;
		size_t seconds = theSong.m_length % 60;

		 os << "| " << std::setw(20) << std::left << theSong.m_title << " | "
			<< std::setw(15) << std::left << theSong.m_artist << " | "
			<< std::setw(20) << std::left << theSong.m_album << " | "
			<< std::setw(6) << std::right << theSong.m_year << " | "
			<< minutes << ":";

		 seconds < 10 ? os << "0" << seconds : os << seconds;
		
		 return os << " | " << theSong.m_price << " |" << std::endl;
	}
}