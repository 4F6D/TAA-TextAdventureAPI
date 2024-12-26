# Text Adventure API (TAA)

THIS IS NOT READY TO USE BUT WILL BE UPDATED IN THE FUTURE
Everything is in one file for ease of use. Might change in the future

## Overview

This API provides the fundamental building blocks for creating a text-based adventure game. It allows you to define locations, present choices to the player, and navigate between different locations based on player input. The API also includes utilities for printing text in the console, including colored text.

## Features

- Create and manage locations with descriptions.
- Define choices at each location to navigate the adventure.
- Output colored text for a more immersive experience.
- Handle user input and allow players to interact with the game.
- Run the game in a loop until the player decides to quit.

---

## Classes

### `TAA::Location`

This class is used to represent a location in the text adventure. Each location has a name, description, and a set of choices that the player can make to navigate to other locations.

#### Constructor

```cpp
Location(const std::string& name = "Default Name", const std::string& description = "Default Description");
```

- `name`: The name of the location.
- `description`: A brief description of the location.

#### Methods

- `void AddChoice(std::string option, std::string nextLocation, std::string response)`: Adds a choice that the player can select to move to the next location.
- `void Display()`: Displays the name, description, and available choices of the current location.

#### Example

```cpp
Location forest("Forest", "You are in a dense, dark forest.");
forest.AddChoice("Go North", "Mountain", "You walk north and find yourself at the foot of a mountain.");
forest.AddChoice("Go South", "River", "You head south and reach a flowing river.");
forest.Display();
```

### `TAA::Game`

The `Game` class is used to control the game loop and handle player input. It initializes the game, displays the welcome message, and processes player decisions.

#### Constructor

```cpp
Game(std::string name = "My Awesome Textadventure!", std::string welcome_message = "");
```

- `name`: The name of the game.
- `welcome_message`: The welcome message that is displayed at the beginning of the game.

#### Methods

- `void Init()`: Initializes the game and displays the welcome message.
- `void Run()`: Runs the game loop. The player is presented with the current location and makes decisions based on available choices. The game ends if the player inputs a quit command.

#### Example

```cpp
Game myGame("Epic Adventure", "Welcome to the adventure!");
myGame.Init();
myGame.Run();
```

---

## Functions

### `TAA::TEXT`

```cpp
void TEXT(std::string text);
```

- Prints the provided text to the console followed by a newline.

#### Example

```cpp
TEXT("Hello, welcome to the game!");
```

### `TAA::INPUT`

```cpp
void INPUT(std::string& inputText);
```

- Reads a line of text from the user input and stores it in the provided string variable.

#### Example

```cpp
std::string playerChoice;
INPUT(playerChoice);
```

### Colored Text Functions

The following functions allow printing colored text in the console:

- `TAA::RED_TEXT(std::string text)`: Returns the text wrapped in red color.
- `TAA::BLUE_TEXT(std::string text)`: Returns the text wrapped in blue color.
- `TAA::GREEN_TEXT(std::string text)`: Returns the text wrapped in green color.
- `TAA::YELLOW_TEXT(std::string text)`: Returns the text wrapped in yellow color.

#### Example

```cpp
TEXT(RED_TEXT("This is a red message!"));
TEXT(GREEN_TEXT("This is a green message!"));
```

---

## Example Usage

Here is an example of how you can use the TAA API to create a simple text adventure game:

```cpp
#include "TAA.h"

int main() {
    // Create locations
    TAA::Location forest("Forest", "You are standing in a dark, dense forest.");
    TAA::Location mountain("Mountain", "You are at the base of a snow-capped mountain.");
    TAA::Location river("River", "You stand beside a flowing river.");

    // Add choices to each location
    forest.AddChoice("Go North", "Mountain", "You walk north and find yourself at the foot of a mountain.");
    forest.AddChoice("Go South", "River", "You head south and reach a flowing river.");

    mountain.AddChoice("Go South", "Forest", "You walk back to the forest.");
    river.AddChoice("Go North", "Forest", "You walk back to the forest.");

    // Initialize the game
    TAA::Game myGame("Epic Adventure", "Welcome to the adventure!");
    myGame.Init();

    // Start the game loop
    myGame.Run();

    return 0;
}
```

In this example, we create three locations (`forest`, `mountain`, `river`), each with a name and description. The player can choose between options that lead to other locations. The game runs until the player decides to quit.

---

## License

This API is released under the GNU General Public License v3.0 (GPL-3.0). You are free to redistribute and modify this code under the terms of the license. This software is provided "as is" without warranty of any kind.

You can read the full text of the GNU General Public License here: [GNU GPL v3 License](https://www.gnu.org/licenses/gpl-3.0.html).
