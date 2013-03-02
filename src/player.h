#include <algorithm>
#include <vector>
#include <ctime>
#include "cards.h"

using namespace std;

/* 
 * This header file defines the player class.
 */

class Player {
    public:
        Player();
        void startTurn();
        void endTurn();
        void drawHand();
        void drawCard();
        int playAction(ActionCard card);
        int buyCard(Card card);
    protected:
        int actions; // number of remaining actions
        int coins; // number of remaining coins
        int buys; // number of remaining buys
        vector<Card> hand; // cards currently in player hand
        vector<Card> deck; // cards currently in player deck
        vector<Card> discard_pile; // cards currently in player discard pile
};
