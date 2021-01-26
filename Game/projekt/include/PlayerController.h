#pragma once
#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Controller.h"
#include "PlayerCreature.h"
#include "Timer.h"
#include <SDL_keyboard.h>
#include <SDL_events.h>

/**
 * PlayerController is a special Controller that takes interprets player input.
 */
class PlayerController: public Controller
{
public:

    /**
     * The default constructor with PlayerCreature possesion.
     * @param creature association of Creature object
     * @param maxSpeed an absolute value of a maximum horizontal velocity that PlayerController should set
     * @see PlayerCreature
     * @see Controller
     */
    PlayerController(PlayerCreature* creature);

    /**
     * The default destructor.
     */
    ~PlayerController();


    /**
     * An implementation of how to control associated PlayerCreature.
     * @see PlayerCreature
     * @see Controller
     * @return void
     */
    void control() override;

    /**
     * Assignment operator is deleted because PlayerController has constant variable.
     */
    PlayerController& operator=(PlayerController const&) = delete;


private:

    /**
     * Interpret player input.
     * @return void
     */
	void inputHandling();
};

#endif // PLAYERCONTROLLER_H
