// HandGenerator.cpp
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "HandGenerator.h"

Hand HandGenerator::generateHand() {
    std::cout << "Generating random hand...\n";
    Hand hand;
    
    // Inisialisasi random engine
    std::mt19937 gen(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution<> rankDist(2, 14); // Rank 2 sampai 14 (11=J, 12=Q, 13=K, 14=A)
    std::uniform_int_distribution<> suitDist(0, 3);  // 0-3 untuk indeks Suit
    char suits[] = {'H', 'D', 'C', 'S'}; // Hearts, Diamonds, Clubs, Spades

    // Menghasilkan 8 kartu random untuk tangan pemain
    for(int i = 0; i < 8; ++i) {
        Card randomCard;
        randomCard.rank = rankDist(gen);
        randomCard.suit = suits[suitDist(gen)];

        hand.cards.push_back(randomCard);
    }

    std::cout << "Finished generating 8 cards.\n\n";
    return hand;
}