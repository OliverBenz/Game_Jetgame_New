#pragma once

enum class Gamestate {
	Menu,        // Menu screen
	Main,        // In game
	Winscreen,   // Player won
	Reset,       // Resetting game
	End          // Exit application
};