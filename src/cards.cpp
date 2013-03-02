#include "cards.h"

/* Methods for the abstract classes */
bool Card::operator==(const Card &other) const {
    return name == other.name;
}

ostream& operator<<(ostream& out, const Card &card) {
    out << card.name;
    return out;
}

string Card::getName() {
    return name;
}

int Card::getCost() {
    return cost;
}

int TerritoryCard::getPoints() {
    return points;
}

int MoneyCard::getCoins() {
    return coins;
}

/* Money cards */
Copper::Copper() {
    name = "Copper";
    cost = 0;
    coins = 1;
}

Silver::Silver() {
    name = "Silver";
    cost = 3;
    coins = 2;
}

Gold::Gold() {
    name = "Gold";
    cost = 6;
    coins = 3;
}

/* Territory Cards */
Estate::Estate() {
    name = "Estate";
    cost = 2;
    points = 1;
}

Dutchie::Dutchie() {
    name = "Dutchie";
    cost = 5;
    points = 3;
}

Province::Province() {
    name = "Province";
    cost = 8;
    points = 6;
}

Curse::Curse() {
    name = "Curse";
    cost = 0;
    points = -1;
}

/* Kingdom Cards */
Cellar::Cellar() {
    name = "Cellar";
    cost = 2;
}

void Cellar::printDescription() {
    cout << "+1 Action\nDiscard any number of cards\n+1 Card per card discarded"
         << endl;
}

void Cellar::action(Player player) {
    cur_player.gainAction();
    cout << "Which cards would you like to discard?" << endl;
    // TODO decide how to take in what cards they'd like to be rid of
}

Chapel::Chapel() {
    name = "Chapel";
    cost = 2;
}

void Chapel::printDescription() {
    cout << "Trash up to 4 cards from your hand" << endl;
}

void Chapel::action() {
    // TODO decide how to take in what cards they'd like to be rid of
}

Moat::Moat() {
    name = "Moat";
    cost = 2;
}

void Moat::printDescription() {
    cout << "+2 Card\nWhen another player plays an Attack card, you may reveal,"
         << " this from your hand. If you do, you are unaffected by that Attack."
         << endl;
}

void Moat::action() {
    cur_player.drawCard(2); // TODO ensure attack cards ineffective on possession
}

Chancellor::Chancellor() {
    name = "Chancellor";
    cost = 3;
}

void Chancellor::printDescription() {
    cout << "+2 Coins\nYou may immediately put your deck into your discard pile"
         << endl;
}

void Chancellor::action() {
    cur_player.gainCoin(2);
    // TODO decide how to offer deck cycling
}

Village::Village() {
    name = "Village";
    cost = 3;
}

void Village::printDescription() {
    cout << "+1 Card\n+2 Actions" << endl;
}

void Village::action() {
    cur_player.drawCard();
    cur_player.gainAction(2);
}

Woodcutter::Woodcutter() {
    name = "Woodcutter";
    cost = 3;
}

void Woodcutter::printDescription() {
    cout << "+1 Buy\n+2 Coins" << endl;
}

void Woodcutter::action() {
    cur_player.gainBuy();
    cur_player.gainCoin(2);
}

Workshop::Workshop() {
    name = "Workshop";
    cost = 3;
}

void Workshop::printDescription() {
    cout << "Gain a card costing up to 4 Coins" << endl;
}

void Workshop::action() {
    //TODO decide how to offer and see what they select
}

Bureaucrat::Bureaucrat() {
    name = "Bureaucrat";
    cost = 4;
}

void Bureaucrat::printDescription() {
    cout << "Gain a silver card; put it on the top of your deck. "
         << "Each other player reveals a Victory card from his hand and puts it"
         << " on his deck (or reveals a hand with no Victory cards)."
         << endl;
}

void Bureaucrat::action() {
    // TODO decide how attack cards deal with game
}

Feast::Feast() {
    name = "Feast";
    cost = 4;
}

void Feast::printDescription() {
    cout << "Trash this card.\nGain a card costing up to 5 Coins." << endl;
}

void Feast::action() {
    // TODO decide how to offer and see what the select
}

Gardens::Gardens() {
    name = "Gardens";
    cost = 2;
    value = 0; // TODO make point counting method do something special here
}

Militia::Militia() {
    name = "Militia";
    cost = 4;
}

void Militia::printDescription() {
    cout << "+2 Coins\n Each other player discards down to 3 cards in his hand."
         << endl;
}

void Militia::action() {
    cur_player.gainCoin(2);
    // TODO decide on best interface for players all discarding
}

Moneylender::Moneylender() {
    name = "Moneylender";
    cost = 4;
}

void Moneylender::printDescription() {
    cout << "Trash a Copper from your hand. If you do, +3 Coins." << endl;
}

void Moneylender::action() {
    if (cur_player.trashCard(Copper)) {
        cur_player.gainCoin(3);
    }
}

Remodel::Remodel() {
    name = "Remodel";
    cost = 4;
}

void Remodel::printDescription() {
    cout << "Trash a card from your hand. Gain a card costing up to 2 Coins more"
         << " than the trashed card." << endl;
}

void Remodel::action() {
    // TODO offer and receive choice interface again...
}

Smithy::Smithy() {
    name = "Smithy";
    cost = 4;
}

void Smithy::printDescription() {
    cout << "+3 Cards\n" << endl;
}

void Smithy::action() {
    cur_player.drawCard(3);
}

Spy::Spy() {
    name = "Spy";
    cost = 2;
}

void Spy::printDescription() {
    cout << "+1 Card\n+1 Action\nEach player (including you) reveals the top "
         << "card of his deck and either discards it or puts it back, your "
         << "choice." << endl;
}

void Spy::action() {
    cur_player.drawCard();
    cur_player.gainAction();
    // TODO decide best interface for seeing top cards
}

Thief::Thief() {
    name = "Thief";
    cost = 4;
}

void Thief::printDescription() {
    cout << "Each other player reveals the top 2 cards of his deck. If they "
         << "revealed any Treasure cards, they trash one of them that you "
         << "choose. You may gain any or all of these trashed cards. They "
         << "discard the other revealed cards." << endl;
}

void Thief::action() {
    // TODO again interface...
}

ThroneRoom::ThroneRoom() {
    name = "Throne Room";
    cost = 4;
}

void ThroneRoom::printDescription() {
    cout << "Choose an Action card in your hand. Play it Twice" << endl;
}

void ThroneRoom::action() {
    // TODO list and choose again..
}

CouncilRoom::CouncilRoom() {
    name = "Council Room";
    cost = 5;
}

void CouncilRoom::printDescription() {
    cout << "+4 Cards\n+1 Buy\nEach other player draws a card." << endl;
}

void CouncilRoom::action() {
    cur_player.drawCard(4);
    cur_player.gainBuy();
    // TODO interface for attack reaching all of game
}

Festival::Festival() {
    name = "Festival";
    cost = 5;
}

void Festival::printDescription() {
    cout << "+2 Actions\n+1 Buy\n+2 Coins" << endl;
}

void Festival::action() {
    cur_player.gainAction(2);
    cur_player.gainBuy();
    cur_player.gainCoin(2);
}

Laboratory::Laboratory() {
    name = "Laboratory";
    cost = 5;
}

void Laboratory::printDescription() {
    cout << "+2 Cards\n+1 Action" << endl;
}

void Laboratory::action() {
    cur_player.drawCard(2);
    cur_player.gainAction();
}

Library::Library() {
    name = "Library";
    cost = 5;
}

void Library::printDescription() {
    cout << "Draw until you have 7 cards in hand. You may set aside any Action "
         << "cards drawn this way, as you draw them; discard the set aside "
         << "cards after you finish drawing." << endl;
}

void Library::action() {
    // TODO again interface for deciding
}

Market::Market() {
    name = "Market";
    cost = 5;
}

void Market::printDescription() {
    cout << "+1 Card\n+1 Action\n+1 Buy\n+1 Coin" << endl;
}

void Market::action() {
    cur_player.drawCard();
    cur_player.gainAction();
    cur_player.gainBuy();
    cur_player.gainCoin();
}

Mine::Mine() {
    name = "Mine";
    cost = 5;
}

void Mine::printDescription() {
    cout << "Trash a Treasure card from your hand. Gain a Treasure card costing "
         << "up to 3 Coins more; put it into your hand." << endl;
}

void Mine::action() {
    // TODO interface for choosing yet again
}

Witch::Witch() {
    name = "Witch";
    cost = 5;
}

void Witch::printDescription() {
    cout << "+2 Cards\nEach other player gains a Curse card." << endl;
}

void Witch::action() {
    cur_player.drawCard(2);
    // TODO attack interface
}

Adventurer::Adventurer() {
    name = "Adventurer";
    cost = 6;
}

void Adventurer::printDescription() {
    cout << "Reveal cards from your deck until you reveal 2 Treasure cards. Put "
         << "those Treasure cards in your hand and discard the other revealed "
         << "cards." << endl;
}

void Adventurer::action() {
    // TODO make this
}
