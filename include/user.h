#pragma  once
#include <string>
#include "picosha2.h"
#include <chrono>

class User {

    unsigned int nonce;
    std::string prv_addr;
    std::string pub_addr;
    std::string wal_addr;

    public:
        User(){

            auto now = std::chrono::high_resolution_clock::now();
            auto micros = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();

            nonce = 0;
            prv_addr = picosha2::hash256_hex_string(std::to_string(micros) + std::to_string(micros));
            pub_addr = picosha2::hash256_hex_string(prv_addr);
            wal_addr = picosha2::hash256_hex_string(pub_addr);
        }

        std::string get_addr(int input){
            switch (input) {
                case 1:
                    return prv_addr;
                case 2:
                    return pub_addr;
                case 3:
                    return wal_addr;
            }
            return "";
        }

        void inc_nonce(){
            nonce++;
        }

        int get_nonce(){
            return nonce;
        }

};