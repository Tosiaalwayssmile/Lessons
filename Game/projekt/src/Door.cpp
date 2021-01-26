#include "Door.h"
#include <SDL_log.h>

/**
 * Door implementation
 */

/**
 * Door constructor that sets position and size of a Door.
 * @param x X position of coin. Defaults to 0.0.
 * @param y Y position of coin. Defaults to 0.0.
 * @see SolidObject
 */
Door::Door(double x, double y, double width, double height) :
    SolidObject(x, y, width, height)
{
   SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Door created at x:%f, y:%f", x, y);
}

/**
 * Door destructor.
 */
Door::~Door()
{
   SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Door opened (destroyed)");
}
