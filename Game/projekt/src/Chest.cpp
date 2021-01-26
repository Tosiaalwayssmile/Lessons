#include "Chest.h"
#include <SDL_log.h>

/**
 * Chest implementation
 */

/**
 * Chest constructor that sets position and size of a Chest.
 * Size is a constant 1.0 width and 1.0 height.
 * @param x X position of coin. Defaults to 0.0.
 * @param y Y position of coin. Defaults to 0.0.
 * @see SolidObject
 */
Chest::Chest(double x, double y, double width, double height, bool doorKey) :
    SolidObject(x, y, width, height), doorKey(doorKey)
{
   SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Chest created at x:%f, y:%f", x, y);
}

/**
 * Chest destructor.
 */
Chest::~Chest()
{
   SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Chest destroyed");
}

bool Chest::getDoorKey()
{
    return this->doorKey;
}

void Chest::keyTaken()
{
    doorKey = false;
}
