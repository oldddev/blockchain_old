#include "../include/transaction.h"
#include "../include/blockchain.h"

using namespace std;

int main(){
    Blockchain blockchain;

    const string sender = blockchain.create_user();
    const string reciever = blockchain.create_user();
    const string reciever1 = blockchain.create_user();
    const string reciever2 = blockchain.create_user();


    Transaction tx(sender, reciever, 20000);
    Transaction tx1(sender, reciever1, 121);
    Transaction tx2(sender, reciever2, 212);

    blockchain.add_tx(tx);
    blockchain.add_tx(tx1);
    blockchain.add_tx(tx2);
    blockchain.add_tx(tx2);
    blockchain.add_tx(tx2);
    blockchain.add_tx(tx2);
    blockchain.add_tx(tx2);
    blockchain.add_tx(tx2);


    blockchain.show_utxo();

    blockchain.find_unspent(tx2.get_receiver());
    
    return 0;
}