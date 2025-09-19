class Spreadsheet {
public:
    vector<vector<int>> spreadsheet;
    Spreadsheet(int rows) {
        spreadsheet = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    int getIndex(string& cell) {
        string index = cell.substr(1);
        int ind = stoi(index) - 1;
        return ind;
    }

    int solve(string& s) {
        if(isdigit(s[0])) return stoi(s);
        int col = s[0] - 'A';
        int row = getIndex(s);

        return spreadsheet[row][col];
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = getIndex(cell);
        spreadsheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = getIndex(cell);
        spreadsheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        string s = formula.substr(1);
        int plusInd = s.find('+');

        string left = s.substr(0,plusInd);
        string right = s.substr(plusInd+1);

        return solve(left) + solve(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */