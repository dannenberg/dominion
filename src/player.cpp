#include "player.h"

Player::Player() {
    // populate starting deck and draw initial hand
    for (int i = 0; i < 7; i++) {
        deck.push_back(Copper());
    }
    for (int i = 0; i < 7; i++) {
        deck.push_back(Estate());
    }
    
    // shuffle and draw
    random_shuffle(deck.begin(), deck.end());
    for (int i = 0; i < 5; i++) {
        drawCard();
    }
}

void Player::startTurn() {
    actions = 1;
    coins = 0;
    buys = 1;
}

void Player::endTurn() {
    // empty remaining hand into discard then draw a new hand
    discard_pile.insert(discard_pile.begin(), hand.begin(), hand.end()); // TODO test
    hand.clear();
    drawHand();
}

void Player::drawCard() {
    // if deck is empty shuffle discard to be new deck before drawing
    if (deck.empty()) {
        deck.swap(discard_pile); // TODO test
        random_shuffle(deck.begin(), deck.end());
    }
    hand.push_back(deck.back()); // TODO check if this can be better
    deck.pop_back();
}

void Player::drawHand() {
    for (int i = 0; i < 5; i++) {
        drawCard();
    }
}

int Player::playAction(ActionCard card) {
    // play the card, decrement action, return remaining actions
    hand.erase(find(hand.begin(), hand.end(), card)); // TODO test
    discard_pile.push_back(card);
    card.action();
    actions--;
    return actions;
}

/* returns -1 when card cannot be purchased, number of coins remaining after
 * purchase if buys remain, or zero otherwise.
 */
int Player::buyCard(Card card) {
    // try to buy card
    if (card.getCost() < coins && buys > 0) {
        coins -= card.getCost();
        buys--;
        discard_pile.push_back(card);
    }
    else {
        cout << "Player could not afford card: " << card;
        return -1;
    }
    if (buys > 0) {
        return coins;
    } else {
        return 0;
    }
}

int main() {
    cout << "hello world" << endl;
}
