#ifndef Bookshelf_H
#define Bookshelf_H

#include "SolidObject.h"

/**
 * Bookshelf is an object that derives from SolidObject.
 */
class Bookshelf :
    public SolidObject
{
public:
    /**
     * Bookshelf constructor that sets position and size of a Bookshelf.
     * @param x X position. Defaults to 0.0.
     * @param y Y position. Defaults to 0.0.
     * @see SolidObject
     */
    Bookshelf (double x = 0.0, double y = 0.0, double width = 0.0, double height = 0.0);

    /**
     * Bookshelf destructor.
     */
    ~Bookshelf();


private:


};
#endif // Bookshelf_H
