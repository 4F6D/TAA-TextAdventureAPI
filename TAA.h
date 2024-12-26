/**
 * @file
 * @brief TAA - TextAdventureAPI
 *
 * This API provides fundamental functions and classes that can be used to create
 * a text-based adventure game. It allows for the creation of various locations,
 * adding choices, and interacting with the player. This API is designed to offer
 * a simple and flexible foundation for text-based adventures.
 *
 * @copyright Copyright (C) 2024 Rigge. All rights reserved.
 *
 * This file is part of TAA - TextAdventureAPI.
 *
 * @license
 * This file is part of TAA - TextAdventureAPI.
 *
 * TAA - TextAdventureAPI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * TAA - TextAdventureAPI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with TAA - TextAdventureAPI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Rigge
 * @version 0.1
 * @date 2024
 */

#pragma once
#include <string>
#include <iostream>
#include <unordered_set>
#include <vector>

namespace TAA
{
	// ASCII-Escape-Sequences to color in text
	// Use: COLOR << text << RESET
	const std::string RED{ "\033[31m" };
	const std::string RESET{ "\033[0m" };
	const std::string YELLOW{ "\033[33m" };
	const std::string GREEN{ "\033[32m" };
	const std::string BLUE{ "\033[34m" };

	/*--------------------------------------
	* Function: TEXT
	* Description: Prints text to the console
	*--------------------------------------*/
	void TEXT(std::string text)
	{
		std::cout << text << std::endl;
	}

	/*--------------------------------------
	* Function: INPUT
	* Description: Takes player input
	*--------------------------------------*/
	void INPUT(std::string& inputText)
	{
		std::getline(std::cin, inputText);
	}

	/*--------------------------------------
	* Function: COLORED TEXT
	* Description: Prints out colored text
	*--------------------------------------*/
	std::string RED_TEXT(std::string text) {  return RED + text + RESET; }			// RED
	std::string BLUE_TEXT(std::string text) { return BLUE + text + RESET; }			// BLUE
	std::string GREEN_TEXT(std::string text) { return GREEN + text + RESET; }		// GREEN
	std::string YELLOW_TEXT(std::string text) { return YELLOW + text + RESET; }		// YELLOW

	/*--------------------------------------
	* Class: Location
	* Description: Create locations for the player to visit
	*--------------------------------------*/
	class Location
	{
	public:
		// Constructor
		Location(const std::string& name = "Default Name", const std::string& description = "Default Description") 
			: location_Name{name}, location_Description{description}
		{
		}

		void AddLocation()
		{
		}

		void AddChoice(std::string option, std::string nextLocation, std::string response)
		{
			m_Choices.push_back({ option, nextLocation, response });
		}

		void Display()
		{
			TEXT(location_Name);
			TEXT(location_Description);
			for (const auto& choice : m_Choices) { TEXT(" - " + choice.option); }
		}

	private:
		std::string location_Name;					// Location name
		std::string location_Description;			// Location description
		
		// Creating a Choice-Object
		struct Choice {
			std::string option;						// What the Player has to type to progress to next location
			std::string nextLocation;				// What the next location is
			std::string response;					// Response to entering next location
		};

		std::vector<Choice> m_Choices;				// List of available options in room

	};

	/*--------------------------------------
	 * Class: Game
	 * Description: Controls Game
	 *--------------------------------------*/
	class Game
	{
	public:
		// Constructor with game name and game description
		Game(std::string name = "My Awesome Textadventure!", std::string welcome_message = "")
			: m_Name{ name }, m_Welcome_Message{ welcome_message }
		{
		}

		void Init()
		{
			TEXT("Welcome to " + m_Name + "\n" + m_Welcome_Message);
			TEXT("");
		}

		void Run()
		{
			while (isRunning)
			{	
				currentLocation->Display();
				INPUT(m_Input);
				if (quitCommands.count(m_Input)) { isRunning = false; }
			}
		}

		void SetWelcomeMessage(std::string welcome_message)
		{
			m_Welcome_Message = welcome_message;
		}

	private:
		std::string m_Input;
		std::string m_Name;
		std::string m_Welcome_Message;
		Location* currentLocation;						// Current location the player is at
		std::unordered_set<std::string> quitCommands = {"q", "Q", "quit", "Quit", "QUIT", "exit", "Exit", "EXIT"};
		bool isRunning = true;
	};

}




