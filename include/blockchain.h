#pragma once
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include "block.h"
#include "user.h"
#include "transaction.h"
#include "picosha2.h"
#include "user.h"

using namespace std;

class Blockchain : Block {

    protected:
    
        std::unordered_map<std::string, unsigned int> utxo;
        std::unordered_map<std::string, Transaction> transactions;
        std::unordered_map<std::string, User> users;

    public:
        Blockchain(){}

        void verify_tx(const Transaction& tx){
            const vector<string> all_unspents = find_unspent(tx.get_receiver());
            int total = 0;
            int unspent_used = 0;

            for(int i = 0; i < all_unspents.size(); i++){
                total += utxo[all_unspents[i]];
                unspent_used = i;
                if(total >= tx.get_amount()) break;
            }

            for(const auto& elem: all_unspents) {
                cout << "Deleting: " << elem << "\n";
                utxo.erase(elem);
            }
        }



        void add_utxo(const Transaction& tx) {

            int nonce = users[tx.get_receiver()].get_nonce();
            std::string hash = picosha2::hash256_hex_string(tx.get_receiver() + std::to_string(nonce));
            utxo[hash] = tx.get_amount();

        }
        void add_tx(const Transaction& tx) {

            transactions.emplace(tx.get_txid(), tx);
            block_add_tx(tx);
            // std::cout <<  "Transaction Added! : " << tx.get_sender() << " to " << tx.get_receiver() << "\n" << tx.get_txid() << std::endl;
            users[tx.get_receiver()].inc_nonce();
            verify_tx(tx);
            add_utxo(tx);
            
        }

        std::string create_user(){
            User user;
            users[user.get_addr(3)] = user;
            return user.get_addr(3);
        }

        void get_users(){
            for(auto& pair : users) std::cout << pair.first << std::endl;
        }

        void show_tx() {
            for(auto& tx : transactions){
                std::cout << tx.first << std::endl;
            }
        }
        void show_utxo() {
            for(auto& tx : utxo){
                std::cout << tx.first << " : ";
                std::cout << tx.second << std::endl;
            }
        }

        vector<std::string> find_unspent(const std::string& wal_addr){
            int nonce = 0;
            std::string uhash;
            vector<std::string> unspents;
            
            for (const auto& pair : utxo) {
                uhash = picosha2::hash256_hex_string(wal_addr + to_string(nonce));
                if(utxo.find(uhash) != utxo.end()) unspents.push_back(uhash);
                nonce++;
            }
            return unspents;
        }

};