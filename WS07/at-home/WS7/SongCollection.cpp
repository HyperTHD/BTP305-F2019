// Name: Abdulbasid Guled
// Seneca Student ID: 156024184
// Seneca email: aguled5@myseneca.ca
// Date of completion: 08/11/2019
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
				m_songs.push_back(extractTokens(temp));
			}
			file.close();
		}
	}

	Song SongCollection::extractTokens(const std::string str)
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
			fullattribute.erase(0, temp.find_first_not_of(" "));
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
		size_t totalTime = 0; // Total song length time

		for_each(m_songs.begin(), m_songs.end(), [&os](const Song& theSong) {
			os << theSong << std::endl;
		});

		totalTime = std::accumulate(m_songs.begin(), m_songs.end(), 0, [](int a, const Song& b) {
			return b.m_length + a;
		});

		os << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
	
		size_t totalHours = totalTime / 3600;
		size_t totalMinutes = (totalTime / 60) % 60;
		size_t totalSeconds = totalTime % 60;

		os << "| " << std::right << std::setw(77) << "Total Listening Time: " << totalHours << ":" << totalMinutes << ":" << totalSeconds << " |" << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, const Song& theSong)
	{
			size_t minutes = theSong.m_length / 60;
			size_t seconds = theSong.m_length % 60;

			 os << "| " << std::setw(20) << std::left << theSong.m_title << " | "
				<< std::setw(15) << std::left << theSong.m_artist << " | "
				<< std::setw(20) << std::left << theSong.m_album << " | "
				<< std::setw(6) << std::right << theSong.m_year << " | "
				<< minutes << ":" << std::setw(2) << std::setfill('0') << seconds << std::setfill(' ');
			 return os << " | " << theSong.m_price << " |";
	}

	// sort will sort collection in ascending order

	void SongCollection::sort(const char* field)
	{
		if (field == std::string_view("title"))
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
				return a.m_title < b.m_title;
			});

		else if (field == std::string_view("album"))
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
				return a.m_album < b.m_album;
			});
		else
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
				return a.m_length < b.m_length;
			});
	}

	bool SongCollection::inCollection(const std::string artist) const
	{
		bool found = false;

		auto check = std::find_if(m_songs.begin(), m_songs.end(), [artist](const Song& song) {
			return song.m_artist == artist;
		});

		if (check != m_songs.end())
			found = true;
		return found;
	}

	std::list<Song> SongCollection::getSongsForArtist(std::string_view artist) const
	{
		std::list<Song>artistList(m_songs.size());
		
		auto copy = std::copy_if(m_songs.begin(), m_songs.end(), artistList.begin(), [artist](const Song& song) {
			return song.m_artist == artist;
		});

		artistList.resize(std::distance(artistList.begin(), copy));
		
		return artistList;
	}

	void SongCollection::cleanAlbum()
	{
		std::transform(m_songs.begin(), m_songs.end(), m_songs.begin(), [](Song& song) {
			if (song.m_album == "[None]")
				song.m_album = "";
				
			return song;
		});
	}
}