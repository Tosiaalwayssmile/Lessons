#ifndef Door_H
#define Door_H

#include "SolidObject.h"

/**
 * Door is an object that derives from SolidObject.
 */
class Door :
    public SolidObject
{
public:
    /**
     * Door constructor that sets position and size of a Door.
     * @param x X position. Defaults to 0.0.
     * @param y Y position. Defaults to 0.0.
     * @see SolidObject
     */
    Door (double x = 0.0, double y = 0.0, double width = 0.0, double height = 0.0);

    /**
     * Door destructor.
     */
    ~Door();
};
#endif // Door_H
