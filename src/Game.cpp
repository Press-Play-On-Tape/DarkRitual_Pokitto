#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;



void Game::setup(GameCookieHighScores *cookieHighScore, GameCookieSaveGame *cookieSaveGame) { 
    
    this->cookieHighScore = cookieHighScore;
    this->cookieSaveGame = cookieSaveGame;
    this->splashScreenVariables.buttonCounter = 16;

    map.setLevel(0);

    this->theme = SoundEffect::MainTheme;
    if (mainThemeFile.openRO("music/darkrit1.raw")) {
        auto& music = Audio::play<0>(mainThemeFile);
        music.setLoop(true);
    }

}

void Game::loop(void) {
    
    PC::buttons.pollButtons();
    PD::clear();

    switch(gameState) {

        case GameState::SplashScreen: 
            splashScreen(); 
            break;

        case GameState::MainMenu: 
            updateMainMenu(); 
            break;

        case GameState::Game_Init_Music:
            if (!this->map.isBossLevel()) {
                if (this->theme != SoundEffect::MainTheme) {
                    this->theme = SoundEffect::MainTheme;
                    if (mainThemeFile.openRO("music/darkrit1.raw")) {
                        auto& music = Audio::play<0>(mainThemeFile);
                        music.setLoop(true);
                    }
                }
            }
            else {
                if (this->theme != SoundEffect::BossTheme) {
                    this->theme = SoundEffect::BossTheme;
                    if (mainThemeFile.openRO("music/darkritC.raw")) {
                        auto& music = Audio::play<0>(mainThemeFile);
                        music.setLoop(true);
                    }
                }
            } 
            gameState = GameState::Game;
            [[fallthrough]];

        case GameState::Game: 
            updateGame(this->gameMode); 
            break;

        case GameState::LoadMap: 
            nextLevelLoad(this->gameMode); 
            break;

        case GameState::EndOfLevel: 
            endOfLevel(); 
            break;

        case GameState::Inventory: 
            showInventory(); 
            break;

        case GameState::Dead: 
            death(); 
            break;

        case GameState::HighScore: 
            highScore(); 
            break;

        case GameState::WinState_Init:  
            win_Init(); 
            break;

        case GameState::WinState:  
            win(); 
            break;

        case GameState::Shop_Init_Music:  
            if (this->theme != SoundEffect::ShopTheme) {
                this->theme = SoundEffect::ShopTheme;
                if (mainThemeFile.openRO("music/darkritA.raw")) {
                    auto& music = Audio::play<0>(mainThemeFile);
                    music.setLoop(true);
                }  
            }
            gameState = GameState::Shop;
            [[fallthrough]];

        case GameState::Shop:  
            showShop(); 
            break;

        case GameState::AltarPieceAchieved:  
            showAltarPieceMessage();
            break;

        case GameState::Guide:  
            showGuide();
            break;

        case GameState::NeedRune:  
            showNeedRuneMessage();
            break;

        case GameState::Puzzle_Init_Game:
            play_InitGame();
            break;

        case GameState::Puzzle_No_Selection:
            play_NoSelection();
            break;

        case GameState::Puzzle_Node_Selected:
            play_NodeSelected();
            break;

        case GameState::Puzzle_Game_Over:
            puzzleGameOver();
            break;

        case GameState::GameSaved:
            showGameSavedMessage();
            break;

        #ifdef DEBUG
            case GameState::MapDetails:  
                mapDetails(); 
                break;
        #endif

    }
	
}



