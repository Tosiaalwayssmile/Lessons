#ifndef Chest_H
#define Chest_H

#include "SolidObject.h"

/**
 * Chest is an object that derives from SolidObject.
 */
class Chest :
    public SolidObject
{
public:
    /**
     * Chest constructor that sets position and size of a Chest.
     * @param x X position. Defaults to 0.0.
     * @param y Y position. Defaults to 0.0.
     * @param doorKey Defaults to true.
     * @see SolidObject
     */
    Chest(double x = 0.0, double y = 0.0, double width = 0.0, double height = 0.0, bool doorKey = true);

    /**
     * Chest destructor.
     */
    ~Chest();
    /**
     * Return if doorKey is still inside the Chest.
     */
    bool getDoorKey();
     /**
     * Change the doorKey value to false.
     */
    void keyTaken();

private:

    bool doorKey;
};
#endif // Chest_H
