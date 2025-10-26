class Bank {
public:
    using ll = long long;
    vector<ll> accountBalance;
    ll n;
    Bank(vector<long long>& balance) {
        accountBalance = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(money < 0 || account1 > n || account2 > n) return false;
        if(accountBalance[account1 - 1] < money) return false;

        accountBalance[account1 - 1] -= money;
        accountBalance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(money < 0 || account > n) return false;
        accountBalance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(money < 0 || account > n) return false;
        if(accountBalance[account - 1] < money) return false;
        accountBalance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */