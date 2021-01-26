#pragma once
#ifndef GAMEDEFS_H
#define GAMEDEFS_H

#include <SDL_stdinc.h>

//#define DEBUGGAME /* Uncomment to add debug info */

/**
 * Hardcoded constants.
 * Replace with information loaded from file ASAP!
 */
namespace GameDefinitions //TODO: Load informations from file
{
	//Game strings
	char const *const gameTitle = "STRASZNY DOM";
    char const *const gameSubtitles[] =
    {   "a simple game made by exhausted students",
        "made by Anna Kowalska and Antonina Matuszek" };
    int const gameSubtitlesSize = 3;
    char const *const gameLost = "YOU DIED";
    char const *const gameWon = "YOU WON!";

	//Screen dimension constants
	const int screenWidth = 640;
	const int screenHeight = 480;
	const int scale = screenHeight/16; // 30 for 480
}
#endif // GAMEDEFS_H
