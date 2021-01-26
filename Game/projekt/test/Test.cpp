#include <boost/test/unit_test.hpp>
#include "Bookshelf.h"

/*
#include "Chest.h"
#include "Door.h"
#include "Controller.h"
#include "Creature.h"
#include "PlayerController.h"
#include "PlayerCreature.h"
#include "Game.h"
#include "InitError.h"
#include "Physics.h"
#include "MonsterCreature.h"
#include "Object.h"
#include "ViewModel.h"
#include "Trigger.h"
#include "Timer.h"
#include "SolidObject.h"
#include "SDLWrapper.h"
*/


BOOST_AUTO_TEST_SUITE(ProjectTest)


BOOST_AUTO_TEST_CASE(ObjectTest)
{
    PlayerCreature gracz(1,1,1,2,80);
        BOOST_CHECK(gracz.getX() == 1);
        BOOST_CHECK(gracz.getY() == 1);
        BOOST_CHECK(gracz.getWidth() == 1);
        BOOST_CHECK(gracz.getHeight() == 2);
        BOOST_CHECK(gracz.getHeartRate() == 80);
        BOOST_CHECK(gracz.getKeys() == 0);

    Bookshelf polka(1,1,1,2);
        BOOST_CHECK(polka.getX() == 1);
        BOOST_CHECK(polka.getY() == 1);
        BOOST_CHECK(polka.getWidth() == 1);
        BOOST_CHECK(polka.getHeight() == 2);

    Chest skrzynia(5,4,3,2);
        BOOST_CHECK(skrzynia.getX() == 5);
        BOOST_CHECK(skrzynia.getY() == 4);
        BOOST_CHECK(skrzynia.getWidth() == 3);
        BOOST_CHECK(skrzynia.getHeight() == 2);

    Door drzwi(15,14,13,12);
        BOOST_CHECK(drzwi.getX() == 15);
        BOOST_CHECK(drzwi.getY() == 14);
        BOOST_CHECK(drzwi.getWidth() == 13);
        BOOST_CHECK(drzwi.getHeight() == 12);

    MonsterCreature potwor(1,5,2,2,1);
        BOOST_CHECK(potwor.getX() == 1);
        BOOST_CHECK(potwor.getY() == 5);
        BOOST_CHECK(potwor.getWidth() == 2);
        BOOST_CHECK(potwor.getHeight() == 2);
        BOOST_CHECK(potwor.getHeartRate() == 1);
}



BOOST_AUTO_TEST_SUITE_END()
