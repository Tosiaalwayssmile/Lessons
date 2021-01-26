#pragma once
#ifndef PLAYERCREATURE_H
#define PLAYERCREATURE_H

#include "Creature.h"

/**
 * PlayerCreature is a Creature that should be controlled by Player.
 * It derives from Creature.
 * @see Creature
 */
class PlayerCreature :
	public Creature
{
public:
    /**
     * The default constructor of PlayerCreature.
     * @param x X position of PlayerCreature. Defaults to 0.0
     * @param y Y position of PlayerCreature. Defaults to 0.0
     * @param width width of PlayerCreature. Defaults to 1.0
     * @param height height of PlayerCreature. Defaults to 1.0
     * @param health health of PlayerCreature. Defaults to 80
     * @see Creature
     */
	PlayerCreature(double x = 0.0, double y = 0.0, double width = 1.0, double height = 1.0, Uint8 heartRate = 80);

    /**
     * Default destructor
     */
	~PlayerCreature();

    /**
     * Function for resolving special cases of collision.
     * If special case is not found, function calls Creature implementation of onCollision.
     * @param collider a pointer to a SolidObject with which MonsterCreature is colliding
     * @return void
     */
    void onCollision(SolidObject* collider) override;

    /**
     * Get number of collected coins.
     * @return Uint32
     */
	Uint32 getKeys() const;



private:
    /**
     * Number of collected keys.
     */
	Uint32 keys;
};

#endif // PLAYERCREATURE_H
