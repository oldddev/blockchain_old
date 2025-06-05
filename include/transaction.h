#pragma once
#include <string>
#include <string>
#include <vector>
#include "picosha2.h"
#include <chrono>

class Transaction{

    private:

        std::string sender;
        std::string receiver;
        unsigned int amount;
        std::string txid;

    public:
        Transaction(const std::string& sender, const std::string& receiver, unsigned int amount) :
        sender(sender), receiver(receiver), amount(amount) {


            auto now = std::chrono::high_resolution_clock::now();
            auto micros = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();

            txid = picosha2::hash256_hex_string(sender + receiver + std::to_string(amount) + std::to_string(micros));
        }

        std::string get_txid() const {
            return txid;
        }
        std::string get_sender() const {
            return sender;
        }
        std::string get_receiver() const {
            return receiver;
        }
        unsigned int get_amount() const {
            return amount;
        }

};