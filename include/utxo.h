#include <cstdint>
#include <string>
#pragma once

class UTXO {
    public:
        const std::string owner;
        const unsigned int amount;
    
    UTXO(const std::string& owner, unsigned int amount) :
    owner(owner), amount(amount) {}
};