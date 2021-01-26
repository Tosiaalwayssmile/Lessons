#include "PlayerController.h"
#include "GameDefs.h"

/**
 * PlayerController implementation
 */

/**
 * The default constructor with PlayerCreature possesion.
 * @param creature association of Creature object
 * @param maxSpeed an absolute value of a maximum horizontal velocity that PlayerController should set
 * @see PlayerCreature
 * @see Controller
 */
PlayerController::PlayerController(PlayerCreature* creature) :  Controller(creature, 5.0)
{
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "PlayerController created!");
}

/**
 * The default destructor.
 */
PlayerController::~PlayerController()
{
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "PlayerController destroyed!");
}


/**
 * An implementation of how to control associated PlayerCreature.
 * @see PlayerCreature
 * @see Controller
 * @return void
 */
void PlayerController::control()
{
    inputHandling();
}

/**
* Interpret player input.
* @return void
*/
void PlayerController::inputHandling()
{
	const Uint8 *state = SDL_GetKeyboardState(nullptr);
	if (state[SDL_SCANCODE_LEFT])
		goLeft();
	else if (state[SDL_SCANCODE_RIGHT])
		goRight();
	else if (state[SDL_SCANCODE_UP])
		goForward();
	else if (state[SDL_SCANCODE_DOWN])
		goBackward();
	else
		stopGoing();
}

