#pragma once
#include <string>
#include <ctime>
#include "picosha2.h"

class Transaction{

    private:
        const std::string from;
        const std::string to;
        const double amount;
        std::string tx_hash;

    public:
        Transaction(const std::string& from, const std::string& to, double&& amount) 
        : from(from), to(to), amount(amount){
            time_t timestamp;
            time(&timestamp);
            tx_hash = picosha2::hash256_hex_string(from + to + std::to_string(amount) + std::to_string(timestamp));
        }
        std::string get_tx() const {
            return tx_hash;
        }
};