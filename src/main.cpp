#include "../include/transaction.h"
#include <iostream>

using namespace std;

int main(){
    const Transaction tx("SHAIKALI", "MARWAAN", 1000);
    cout << tx.get_tx() << endl;
    return 0;
}