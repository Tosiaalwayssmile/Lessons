#include "Game.h"
#include "Door.h"
#include "Chest.h"
#include "Bookshelf.h"
#include "MonsterCreature.h"
#include "Trigger.h"

/**
 * Game implementation
 */

/**
 * The default constructor.
 * Sets gameState to menu.
 * @see GameState
 */
Game::Game():
        gameState(GameState::Menu),
        posUpdated(false),
        levelWidth(0),
        levelHeight(0),
        levelKeys(0),
        levelLoaded(false),
        posAlpha(1.0)
{
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Game created!");
}

/**
 * The default destructor.
 * Unloads level.
 */
Game::~Game()
{
        unloadLevel();
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Game destroyed!");
}

/**
 * Updates current state of game.
 * @return void
 */
void Game::gameLoop()
{
    posUpdated = false;

    if (gameState == GameState::Playing)
    {

        //move everything
        std::list<Controller*>::iterator it;
        for (it = controllerList.begin(); it != controllerList.end(); ++it)
        {

            if (!(*it)->getCreature()->getIsAlive())
            {
                posUpdated = true;
                PlayerController* tmpPC = dynamic_cast<PlayerController*>(*it);
                if (tmpPC != nullptr)
                    gameState = GameState::Lost;
                (*it)->getCreature()->destroy();
                delete (*it);
                controllerList.erase(it);
                it = controllerList.begin();
                if (it == controllerList.end())
                    break;
                continue;
            }
            (*it)->control();
        }
        //clear destroyed objects
        for (std::list<Object*>::iterator it = objectList.begin(); it != objectList.end(); ++it)
        {
            if ((*it)->getDestroyed())
            {
                delete (*it);
                objectList.erase(it);
                it = objectList.begin();
                if (it == objectList.end())
                    break;
            }
        }
        //untrigger the triggers
        std::for_each(objectList.begin(), objectList.end(), [](Object* o){ Trigger* tmpT = dynamic_cast<Trigger*>(o); if (tmpT != nullptr) tmpT->untrigger(); });
        //do physics
        posAlpha = physics->update(objectList);
        //check if positions were updated
        checkPositions();
    }


    if (gameState == GameState::Menu)
        if (levelLoaded)
            unloadLevel();
}

/**
 * Changes gameState to GameState::Playing and loads level.
 * @return void
 */
void Game::startGame()
{
        //Load level
        loadLevel();
        gameState = GameState::Playing;
}

/**
 * Changes gameState to GameState::Pause.
 * @return void
 */
void Game::pauseGame()
{
        gameState = GameState::Paused;
}

/**
 * Changes gameState to GameState::Playing.
 * @return void
 */
void Game::resumeGame()
{
        gameState = GameState::Playing;
}

/**
 * Changes gameState to GameState::Menu and unloads level.
 * @return void
 */
void Game::quitToMenu()
{
        gameState = GameState::Menu;
}

/**
 * Changes gameState to GameState::Quit.
 * @return void
 */
void Game::gameOver()
{
        gameState = GameState::Quit;
}

/**
 * Changes gameState to GameState::Won.
 * @return void
 */
void Game::wonGame()
{
    gameState = GameState::Won;
}

/**
 * Unloads level if loaded, loads level and initializes Physics.
 * @return void
 * @see Physics
 */
void Game::loadLevel()
{
    unloadLevel();
        objectList.push_back(new SolidObject(0, 0, 1, 50));
        objectList.push_back(new SolidObject(0, 0, 60, 1));
        objectList.push_back(new SolidObject(59, 0, 1, 50));

        objectList.push_back(new SolidObject(0, 47, 60, 3));
        objectList.push_back(new SolidObject(17, 30, 1, 7));
        objectList.push_back(new SolidObject(17, 39, 1, 11));


        objectList.push_back(new Door(17.5, 37, 0.5, 2.0));

        objectList.push_back(new SolidObject(18, 47, 15, 3));
        objectList.push_back(new SolidObject(33, 30, 1, 20));

         objectList.push_back(new SolidObject(0, 30, 28, 1));
         objectList.push_back(new SolidObject(30, 30, 15, 1));

     objectList.push_back(new Door(28, 30, 2.0, 0.5));


    objectList.push_back(new SolidObject(22, 20, 1, 10));
    objectList.push_back(new SolidObject(14, 20, 8, 1));
    objectList.push_back(new SolidObject(14, 4, 1, 23));
    objectList.push_back(new SolidObject(14, 8, 4, 1));

    objectList.push_back(new SolidObject(20, 8, 4, 1));

    objectList.push_back(new Door(18, 8, 2, 0.5));

    objectList.push_back(new SolidObject(24, 0, 1, 2));

    objectList.push_back(new Door(24.5, 2, 0.5, 2));


    objectList.push_back(new SolidObject(24, 4, 1, 12));
    objectList.push_back(new SolidObject(24, 16, 15, 1));

        objectList.push_back(new SolidObject(39, 0, 1, 12));
        objectList.push_back(new SolidObject(39, 14, 1, 17));

        objectList.push_back(new Door(39.5, 12, 0.5, 2));



        objectList.push_back(new SolidObject(30, 5, 4, 0.4));
        objectList.push_back(new SolidObject(30, 0, 0.4, 5));

        objectList.push_back(new SolidObject(33, 7, 0.5, 2));
        objectList.push_back(new SolidObject(33, 9, 6.5, 0.5));
        objectList.push_back(new SolidObject(50, 30, 10, 1));

    objectList.push_back(new SolidObject(54, 0, 1, 18));
    objectList.push_back(new SolidObject(54, 20, 1, 10));

    objectList.push_back(new Door(54.5, 18, 0.5, 2));


    objectList.push_back(new SolidObject(42, 34.5, 11, 0.5));
    objectList.push_back(new SolidObject(52, 39, 6, 0.5));
    objectList.push_back(new SolidObject(38, 40, 5, 0.5));
    objectList.push_back(new SolidObject(36, 44, 17, 0.5));
    objectList.push_back(new SolidObject(39, 32, 0.5, 6));
    objectList.push_back(new SolidObject(45, 38, 0.5, 6));

    objectList.push_back(new Chest(13, 45, 3, 1.3));
    objectList.push_back(new Chest(17, 22, 3, 1.3));
    objectList.push_back(new Chest(37, 19, 1.3, 3));
    objectList.push_back(new Chest(31, 35, 1.3, 3));
    objectList.push_back(new Chest(31, 1.3, 1.3, 3));
    objectList.push_back(new Chest(44, 45.3, 3, 1.3));
    objectList.push_back(new Chest(55.5, 28, 3, 1.3));

    objectList.push_back(new Bookshelf(24, 46, 5, 1));
    objectList.push_back(new Bookshelf(1, 15, 1, 5));
    objectList.push_back(new Bookshelf(53, 7, 1, 5));


        objectList.push_back(new PlayerCreature(1, 45));

        playerController = new PlayerController(dynamic_cast<PlayerCreature*> (objectList.back()));
        controllerList.push_back(playerController);

    objectList.push_back(new MonsterCreature(9, 22, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(9, 28, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(9, 40, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(24, 33, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(31, 38, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(28, 44, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(28, 6, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(35, 13, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(32, 28, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(39, 27, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(46, 20, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(39, 14, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(45, 7, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(35, 23, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(30, 17, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(23, 14, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(17, 11, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(4, 14, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(12, 7, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));


    objectList.push_back(new MonsterCreature(55, 42, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(40, 45, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(36, 35, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(39, 32, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(57, 37, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));
    objectList.push_back(new MonsterCreature(36, 42, 2, 2));
    controllerList.push_back(new Controller(dynamic_cast<Creature*> (objectList.back())));

    objectList.push_back(new Trigger(this, &Game::wonGame, nullptr, nullptr, 55.5, 28, 3, 1.3));

        levelWidth = 60;
        levelHeight = 50;
        levelLoaded = true;
        physics = new Physics(levelWidth, levelHeight);
}

/**
 * Unloads level if loaded.
 * @return void
 */
void Game::unloadLevel()
{
        if (levelLoaded)
        {
                std::for_each(controllerList.begin(), controllerList.end(), [](Controller* c){delete(c); });
                controllerList.clear();
                std::for_each(objectList.begin(), objectList.end(), [](Object* o){delete(o); });
                objectList.clear();
                delete physics;
                levelLoaded = false;
        levelKeys = 0;
        levelHeight = 0;
        levelWidth = 0;
        }
}

/**
 * Get current GameState.
 * @return GameState
 */
GameState Game::getGameState() const
{
    return gameState;
}

/**
 * Get pointer to PlayerController.
 * @return PlayerController*
 */
PlayerController* Game::getPlayerController() const
{
    return playerController;
}

/**
 * Check if game has ended.
 * @return bool
 */
bool Game::getHasEnded() const
{
        if (gameState == GameState::Quit)
                return true;
        else
                return false;
}

/**
 * Check if game state has changed.
 * @return bool
 */
bool Game::getPosUpdated() const
{
        return posUpdated;
}

/**
 * Get width of loaded level.
 * @return int
 */
int Game::getLevelWidth() const
{
    return levelWidth;
}

/**
 * Get height of loaded level.
 * @return int
 */
int Game::getLevelHeight() const
{
    return levelHeight;
}

/**
 * Get number of coins spawned on loaded level.
 * @return int
 */
Uint8 Game::getLevelKeys() const
{
    return levelKeys;
}

/**
 * Get coefficient of game state between steps, where 0 is previous step and 1 is current step.
 * @return double
 */
double Game::getPosAlpha() const
{
    return posAlpha;
}

/**
 * Get reference to constant list of loaded game objects.
 * @return std::list<Object*> const&
 */
std::list<Object*> const& Game::getObjectList() const
{
        return objectList;
}

/**
 * Sets posUpdated to true if state of game objects has changed.
 * @return void
 */
void Game::checkPositions()
{
    for (std::list<Object*>::iterator it = objectList.begin(); it != objectList.end(); ++it)
    {
        if ((*it)->getPrevX() != (*it)->getX() || (*it)->getPrevY() != (*it)->getY())
        {
            posUpdated = true;
        }
    }
}
