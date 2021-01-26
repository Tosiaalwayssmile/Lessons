#include "Bookshelf.h"

#ifdef USE_SDL
 #include <SDL_log.h>
#endif

/**
 * Bookshelf implementation
 */

/**
 * Bookshelf constructor that sets position and size of a Bookshelf.
 * Size is a constant 1.0 width and 1.0 height.
 * @param x X position of coin. Defaults to 0.0.
 * @param y Y position of coin. Defaults to 0.0.
 * @see SolidObject
 */
Bookshelf::Bookshelf(double x, double y, double width, double height) :
    SolidObject(x, y, width, height)
{
#ifdef USE_SDL
   SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Bookshelf created at x:%f, y:%f", x, y);
#endif
}

/**
 * Bookshelf destructor.
 */
Bookshelf::~Bookshelf()
{
#ifdef USE_SDL
   SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Bookshelf destroyed");
#endif
}

