#pragma once
#include <vector>
#include "Card.h"
#include "PokerHandType.h"
 
// Abstract class sebagai blueprint semua checker tangan poker
// Menggunakan Chain of Responsibility Pattern
class PokerHandChecker {
protected:
    PokerHandChecker* nextChecker = nullptr; // Checker berikutnya dalam chain
 
public:
    virtual ~PokerHandChecker() = default;
 
    // Set checker berikutnya dalam chain
    void setNext(PokerHandChecker* next);
 
    // Cek apakah kartu memenuhi syarat tangan ini
    virtual bool checkPokerHand(const std::vector<Card>& cards) = 0;
 
    // Kembalikan jenis tangan yang dicek oleh checker ini
    virtual PokerHandType getHandType() const = 0;
};