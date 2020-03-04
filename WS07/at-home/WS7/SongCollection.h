#pragma once

// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 08/11/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <fstream>

namespace sdds
{
	// Struct for the Song

	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		std::string m_year;
		size_t m_length;

	};

	// Class for the Song
	
	class SongCollection
	{
		// Can use any container so chosen vector

		std::vector<Song> m_songs{};

	public:
		Song extractTokens(const std::string);
		SongCollection(const char*);
		void display(std::ostream& os) const;
		void sort(const char*);
		void cleanAlbum();
		bool inCollection(const std::string) const;
		std::list<Song>getSongsForArtist(const std::string_view) const;
	};
	
	// Free Helper

	std::ostream& operator<<(std::ostream& os, const Song&);
}

#endif 