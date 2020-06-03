#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


constexpr const char message01_01[] = "Dark Ritual";
constexpr const char message01_02[] = "";
constexpr const char message01_03[] = "You have entered";
constexpr const char message01_04[] = "a dungeon system";
constexpr const char message01_05[] = "full of surprises,";
constexpr const char message01_06[] = "challenges and, of";
constexpr const char message01_07[] = "course, rewards. ";
constexpr const char message01_08[] = "";
constexpr const char message01_09[] = "Battle your way to";
constexpr const char message01_10[] = "the last level and";
constexpr const char message01_11[] = "make an offering at";
constexpr const char message01_12[] = "the altar to buy";
constexpr const char message01_13[] = "back your freedom.";
constexpr const char message01_14[] = "";
constexpr const char message01_15[] = "You must complete";
constexpr const char message01_16[] = "each level in the";
constexpr const char message01_17[] = "alloted time - if";
constexpr const char message01_18[] = "you fail to do so";
constexpr const char message01_19[] = "you will perish.";
constexpr const char message01_20[] = "";
constexpr const char message01_21[] = "You will discover";
constexpr const char message01_22[] = "runes or win them";
constexpr const char message01_23[] = "by killing enemies";
constexpr const char message01_24[] = "- there are six in";
constexpr const char message01_25[] = "all to collect and";
constexpr const char message01_26[] = "you will need all";
constexpr const char message01_27[] = "of them before you";
constexpr const char message01_28[] = "make your offering";
constexpr const char message01_29[] = "at the altar.";
constexpr const char message01_30[] = "";
constexpr const char message01_31[] = "You will find more";
constexpr const char message01_32[] = "information in this";
constexpr const char message01_33[] = "first level as you";
constexpr const char message01_34[] = "approach new items";
constexpr const char message01_35[] = "or enemies. After";
constexpr const char message01_36[] = "that, you will be";
constexpr const char message01_37[] = "on your own ..";

constexpr const char message02_01[] = "As you travel, you";
constexpr const char message02_02[] = "will come across ";
constexpr const char message02_03[] = "coins, food, magic";
constexpr const char message02_04[] = "potions and spells.";
constexpr const char message02_05[] = "";
constexpr const char message02_06[] = "You can only carry";
constexpr const char message02_07[] = "a handful of items";
constexpr const char message02_08[] = "so you must choose";
constexpr const char message02_09[] = "carefully.";
constexpr const char message02_10[] = "";
constexpr const char message02_11[] = "You can view your";
constexpr const char message02_12[] = "items by pressing";
constexpr const char message02_13[] = "the C button. From";
constexpr const char message02_14[] = "there you can use";
constexpr const char message02_15[] = "items or drop those";
constexpr const char message02_16[] = "you no longer need.";

constexpr const char message03_01[] = "Chests and barrels";
constexpr const char message03_02[] = "can sometimes hide";
constexpr const char message03_03[] = "goodies. Opening or";
constexpr const char message03_04[] = "shooting them will";
constexpr const char message03_05[] = "reveal any items";
constexpr const char message03_06[] = "they may be hiding.";
constexpr const char message03_07[] = "";
constexpr const char message03_08[] = "Some doors require";
constexpr const char message03_09[] = "keys to unlock them.";
constexpr const char message03_10[] = "Search the nearby ";
constexpr const char message03_11[] = "rooms, barrels and";
constexpr const char message03_12[] = "chests to find one.";

constexpr const char message04_01[] = "Other doors can be";
constexpr const char message04_02[] = "activated by using";
constexpr const char message04_03[] = "a lever or standing";
constexpr const char message04_04[] = "on a pressure plate";
constexpr const char message04_05[] = "";
constexpr const char message04_06[] = "Some levers may be";
constexpr const char message04_07[] = "broken but you will";
constexpr const char message04_08[] = "be able to fix them";
constexpr const char message04_09[] = "using tools lying";
constexpr const char message04_10[] = "nearby.";
constexpr const char message04_11[] = "";
constexpr const char message04_12[] = "To navigate some";
constexpr const char message04_13[] = "rooms, you may need";
constexpr const char message04_14[] = "to use two or more";
constexpr const char message04_15[] = "levers to arrange";
constexpr const char message04_16[] = "the doors to allow";
constexpr const char message04_17[] = "passage.";

constexpr const char message05_01[] = "By now, you have";
constexpr const char message05_02[] = "probably worked";
constexpr const char message05_03[] = "out that you can";
constexpr const char message05_04[] = "cast spells.";
constexpr const char message05_05[] = "";
constexpr const char message05_06[] = "The dungeons are";
constexpr const char message05_07[] = "full of enemies";
constexpr const char message05_08[] = "that will kill you";
constexpr const char message05_09[] = "if you do not kill";
constexpr const char message05_10[] = "them first.";
constexpr const char message05_11[] = "";
constexpr const char message05_12[] = "You can use barrels";
constexpr const char message05_13[] = "and chests to hide";
constexpr const char message05_14[] = "behind and you will";
constexpr const char message05_15[] = "find additional";
constexpr const char message05_16[] = "spells that you";
constexpr const char message05_17[] = "should conserve";
constexpr const char message05_18[] = "until needed.";

constexpr const char message06_01[] = "Hopefully you have";
constexpr const char message06_02[] = "been collecting ";
constexpr const char message06_03[] = "all the coins you";
constexpr const char message06_04[] = "have seen in your";
constexpr const char message06_05[] = "travels.";
constexpr const char message06_06[] = "";
constexpr const char message06_07[] = "You can visit the";
constexpr const char message06_08[] = "shops that you will";
constexpr const char message06_09[] = "discover scattered";
constexpr const char message06_10[] = "around to buy the ";
constexpr const char message06_11[] = "items you will need";
constexpr const char message06_12[] = "to restore your";
constexpr const char message06_13[] = "health or to equip";
constexpr const char message06_14[] = "you to battle the";
constexpr const char message06_15[] = "stronger enemies";
constexpr const char message06_16[] = "found in higher";
constexpr const char message06_17[] = "levels.";

constexpr const char message07_01[] = "Congratulations!";
constexpr const char message07_02[] = "";
constexpr const char message07_03[] = "Although you have";
constexpr const char message07_04[] = "seen some of the";
constexpr const char message07_05[] = "enemies and items";
constexpr const char message07_06[] = "to be found in the";
constexpr const char message07_07[] = "dungeons, there are";
constexpr const char message07_08[] = "plenty more to ";
constexpr const char message07_09[] = "find and battle as";
constexpr const char message07_10[] = "you explore.";
constexpr const char message07_11[] = "";
constexpr const char message07_12[] = "Good luck!";

constexpr const char message08_01[] = "You may think you";
constexpr const char message08_02[] = "have collected";
constexpr const char message08_03[] = "everything from a";
constexpr const char message08_04[] = "room but watch";
constexpr const char message08_05[] = "those enemies as";
constexpr const char message08_06[] = "they are thieves!";

constexpr const char message09_01[] = "Barrels seem to";
constexpr const char message09_02[] = "just block your way";
constexpr const char message09_03[] = "but can be a great";
constexpr const char message09_04[] = "shield. Sometimes";
constexpr const char message09_05[] = "they can contain a";
constexpr const char message09_06[] = "treasure.";

constexpr const char message10_01[] = "Did you know that";
constexpr const char message10_02[] = "certain treasures";
constexpr const char message10_03[] = "can surprise you?";
constexpr const char message10_04[] = "You might end up";
constexpr const char message10_05[] = "being chased by";
constexpr const char message10_06[] = "some.";

constexpr const char message11_01[] = "Find all the runes";
constexpr const char message11_02[] = "in order to perform";
constexpr const char message11_03[] = "the secret ritual";
constexpr const char message11_04[] = "before our rivals.";
constexpr const char message11_05[] = "We must be the ones,";
constexpr const char message11_06[] = "the chosen ones.";

constexpr const char message12_01[] = "They say sometimes";
constexpr const char message12_02[] = "you can hear bones";
constexpr const char message12_03[] = "shattering loudly";
constexpr const char message12_04[] = "underground. Cries.";
constexpr const char message12_05[] = "Screams. Must be ";
constexpr const char message12_06[] = "the necromancers.. ";

constexpr const char message13_01[] = "In the depth of the";
constexpr const char message13_02[] = "dungeons, even a";
constexpr const char message13_03[] = "master cultist like";
constexpr const char message13_04[] = "you could go insane";
constexpr const char message13_05[] = "Maybe it's the only";
constexpr const char message13_06[] = "way to ascend?";

constexpr const char message14_01[] = "Save some of your";
constexpr const char message14_02[] = "potions and spells";
constexpr const char message14_03[] = "for later levels -";
constexpr const char message14_04[] = "you will definitely";
constexpr const char message14_05[] = "need them!";

constexpr const char message15_01[] = "The cultists are all";
constexpr const char message15_02[] = "counting on you to";
constexpr const char message15_03[] = "free our souls. Go";
constexpr const char message15_04[] = "forth and conquer";
constexpr const char message15_05[] = "thise enemies!";

const uint8_t messageLengths[] = { 37, 16, 12, 17, 18, 17, 12, 6, 6, 6, 6, 6, 6, 5, 5 };

constexpr const char * const messages01[] = { 
message01_01,
message01_02,
message01_03,
message01_04,
message01_05,
message01_06,
message01_07,
message01_08,
message01_09,
message01_10,
message01_11,
message01_12,
message01_13,
message01_14,
message01_15,
message01_16,
message01_17,
message01_18,
message01_19,
message01_20,
message01_21,
message01_22,
message01_23,
message01_24,
message01_25,
message01_26,
message01_27,
message01_28,
message01_29,
message01_30,
message01_31,
message01_32,
message01_33,
message01_34,
message01_35,
message01_36,
message01_37,
};

constexpr const char * const messages02[] = { 
message02_01,
message02_02,
message02_03,
message02_04,
message02_05,
message02_06,
message02_07,
message02_08,
message02_09,
message02_10,
message02_11,
message02_12,
message02_13,
message02_14,
message02_15,
message02_16,
};

constexpr const char * const messages03[] = { 
message03_01,
message03_02,
message03_03,
message03_04,
message03_05,
message03_06,
message03_07,
message03_08,
message03_09,
message03_10,
message03_11,
message03_12,
};

constexpr const char * const messages04[] = { 
message04_01,
message04_02,
message04_03,
message04_04,
message04_05,
message04_06,
message04_07,
message04_08,
message04_09,
message04_10,
message04_11,
message04_12,
message04_13,
message04_14,
message04_15,
message04_16,
message04_17,
};

constexpr const char * const messages05[] = { 
message05_01,
message05_02,
message05_03,
message05_04,
message05_05,
message05_06,
message05_07,
message05_08,
message05_09,
message05_10,
message05_11,
message05_12,
message05_13,
message05_14,
message05_15,
message05_16,
message05_17,
message05_18,
};

constexpr const char * const messages06[] = { 
message06_01,
message06_02,
message06_03,
message06_04,
message06_05,
message06_06,
message06_07,
message06_08,
message06_09,
message06_10,
message06_11,
message06_12,
message06_13,
message06_14,
message06_15,
message06_16,
message06_17,
};

constexpr const char * const messages07[] = { 
message07_01,
message07_02,
message07_03,
message07_04,
message07_05,
message07_06,
message07_07,
message07_08,
message07_09,
message07_10,
message07_11,
message07_12,
};

constexpr const char * const messages08[] = { 
message08_01,
message08_02,
message08_03,
message08_04,
message08_05,
message08_06,
};

constexpr const char * const messages09[] = { 
message09_01,
message09_02,
message09_03,
message09_04,
message09_05,
message09_06,
};

constexpr const char * const messages10[] = { 
message10_01,
message10_02,
message10_03,
message10_04,
message10_05,
message10_06,
};

constexpr const char * const messages11[] = { 
message11_01,
message11_02,
message11_03,
message11_04,
message11_05,
message11_06,
};

constexpr const char * const messages12[] = { 
message12_01,
message12_02,
message12_03,
message12_04,
message12_05,
message12_06,
};

constexpr const char * const messages13[] = { 
message13_01,
message13_02,
message13_03,
message13_04,
message13_05,
message13_06,
};

constexpr const char * const messages14[] = { 
message14_01,
message14_02,
message14_03,
message14_04,
message14_05,
};

constexpr const char * const messages15[] = { 
message15_01,
message15_02,
message15_03,
message15_04,
message15_05,
};


void Game::showGuide() {


    // Handle player actions ..

    if (PC::buttons.pressed(BTN_A) || PC::buttons.pressed(BTN_B) || PC::buttons.pressed(BTN_C)) {

        PD::setColor(0, 0);
        gameState = GameState::Game; 
        this->guide->setPuffIndex(20);

    }

    if ((PC::buttons.pressed(BTN_UP) || PC::buttons.repeat(BTN_UP, 2)) && this->guideTop > 0) {

        this->guideTop--; 

    }

    if ((PC::buttons.pressed(BTN_DOWN) || PC::buttons.repeat(BTN_DOWN, 2)) && this->guideTop + 6 < messageLengths[this->guideNumber]) {

        this->guideTop++; 

    }


    // Render screen ..

    PD::fillScreen(0);
    this->renderEnvironment(!this->map.isBossLevel() && !this->map.isAltarLevel(), 0, 0);
    this->renderHud();

    PD::setColor(15);
    PD::fillRect(14, 8, 86, 60);

    PD::drawBitmap(7, 1, Images::AltarTOP_Wide);
    PD::drawBitmap(6, 8, Images::AltarLHS);
    PD::drawBitmap(96, 8, Images::AltarRHS);
    PD::drawBitmap(8, 64, Images::AltarBOT_Wide);


    PD::setColor(4, 15);
    PD::setFont(font3x5);

    uint8_t endLoop = (this->guideTop + 6 > messageLengths[this->guideNumber] ? messageLengths[this->guideNumber] : this->guideTop + 6);

    uint8_t xOffset = (endLoop > 6 ? 0 : 2);

    for (uint8_t x = this->guideTop; x < endLoop; x++) {

        switch (this->guideNumber) {

            case 0:
                {
                    const char * message = messages01[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;

            case 1:
                {
                    const char * message = messages02[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;

            case 2:
                {
                    const char * message = messages03[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;

            case 3:
                {
                    const char * message = messages04[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;

            case 4:
                {
                    const char * message = messages05[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;

            case 5:
                {
                    const char * message = messages06[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;

            case 6:
                {
                    const char * message = messages07[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;

            case 7:
                {
                    const char * message = messages08[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;

            case 8:
                {
                    const char * message = messages09[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;

            case 9:
                {
                    const char * message = messages10[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;         

            case 10:
                {
                    const char * message = messages11[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;               

            case 11:
                {
                    const char * message = messages12[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;       

            case 12:
                {
                    const char * message = messages13[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;              

            case 13:
                {
                    const char * message = messages14[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;              

            case 14:
                {
                    const char * message = messages15[x];
                    showGuide_renderLine(x - this->guideTop, xOffset, message);
                }
                break;                       

        }

    }


    // Draw scroll bar ..

    if (endLoop > 6) {
            
        PD::setColor(9);
        PD::drawRect(91, 13, 4, 43);

        if (messageLengths[this->guideNumber] > 6) {

            uint16_t length = 410 / messageLengths[this->guideNumber];

            PD::drawLine(93, 15 + ((this->guideTop * length) / 10), 93, 14 + ((this->guideTop + 6) * length) / 10);

            if (this->guideTop > 0) {
                PD::drawBitmap(91, 8, Images::ArrowUpEnabled);
            }
            else {
                PD::drawBitmap(91, 8, Images::ArrowUpDisabled);
            }

            if (this->guideTop + 6 == messageLengths[this->guideNumber]) {
                PD::drawBitmap(91, 58, Images::ArrowDownDisabled);
            }
            else {
                PD::drawBitmap(91, 58, Images::ArrowDownEnabled);
            }
            
        }
        else {

            PD::drawBitmap(91, 8, Images::ArrowUpDisabled);
            PD::drawBitmap(91, 58, Images::ArrowDownDisabled);

        }

    }

    PD::setFont(fontKoubit);

}

void Game::showGuide_renderLine(uint8_t line, uint8_t xOffset, const char message[]) {

    PD::setCursor(16 + xOffset, 13 + (line * 8));
    PD::print(message);

}