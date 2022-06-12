class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        if(income <= brackets[0][0]) {
            tax = (double)income*brackets[0][1] / 100;
            return tax;
        }
        tax = (double)brackets[0][0] * brackets[0][1] / 100;
        income -= brackets[0][0];
        cout << "INCOME: " << income << endl;
        cout << "TAX: " << tax << endl;
        for(int i = 1; i < brackets.size(); i++) {
            int slab = brackets[i][0] - brackets[i-1][0];
            if(income <= slab) {
                tax += (double)income * brackets[i][1] / 100;
                return tax;               
            }
            
            cout << "INCOME: " << income << endl;
            cout << "TAX: " << tax << endl;
            tax += (double)slab*brackets[i][1] / 100;
            income -= slab;
        }
        
        return tax;
    }
};