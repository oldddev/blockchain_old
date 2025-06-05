#pragma once
#include <iostream>
#include <vector>
#include "transaction.h"

using namespace std;

class Block {

    protected:
        vector<Transaction> txs;
    
    public:
        vector<Transaction> get_transactions() const {
            return txs;
        }
        void block_add_tx(Transaction tx){

            txs.push_back(tx);

        }

};