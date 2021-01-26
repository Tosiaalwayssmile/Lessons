#include "PlayerCreature.h"
#include "Chest.h"
#include "Bookshelf.h"
#include "Door.h"
#include "Trigger.h"

/**
 * PlayerCreature implementation
 */

/**
 * The default constructor of PlayerCreature.
 * @param x X position of PlayerCreature.
 * @param y Y position of PlayerCreature.
 * @param width width of PlayerCreature.
 * @param height height of PlayerCreature.
 * @param health health of PlayerCreature. Defaults to 80
 * @see Creature
 */
PlayerCreature::PlayerCreature(double x, double y, double width, double height, Uint8 heartRate) :
    Creature(x, y, width, height, heartRate),
    keys(0)
{
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "PlayerCreature created!");
}

/**
 * Default destructor
 */
PlayerCreature::~PlayerCreature()
{
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "PlayerCreature destroyed!");
}

/**
 * Function for resolving special cases of collision.
 * If special case is not found, function calls Creature implementation of onCollision.
 * @param collider a pointer to a SolidObject with which MonsterCreature is colliding
 * @return void
 */
void PlayerCreature::onCollision(SolidObject* collider)
{
    Trigger* tmpT = dynamic_cast<Trigger*>(collider);
    if (tmpT != nullptr)
    {
        if (!tmpT->getDestroyed())
        {
            tmpT->trigger();
        }
    }

	//here do something if got a door
	Door* tmpDoor = dynamic_cast<Door*>(collider);
	if (tmpDoor != nullptr && keys != 0)
	{
		if (!tmpDoor->getDestroyed())
		{
            --keys;
			tmpDoor->destroy();
		}
		return;
	}


	//here do sth if got a chest
	Chest* tmpChest = dynamic_cast<Chest*>(collider);
	if ((tmpChest != nullptr) && (tmpChest->getDoorKey()))
	{
        ++keys;
        tmpChest->keyTaken();
		return;
	}

    Bookshelf* tmpBookshelf = dynamic_cast<Bookshelf*>(collider);
	if (tmpBookshelf != nullptr && getHeartRate() > 80)
	{
        coolDown();
		return;
	}

	Creature* tmpCreature = dynamic_cast<Creature*>(collider);
	if (tmpCreature != nullptr)
	{
		//if collided with creature, ignore it
		return;
	}

	Creature::onCollision(collider);
}

/**
 * Get number of collected keys.
 * @return Uint32
 */
Uint32 PlayerCreature::getKeys() const
{
	return keys;
}


