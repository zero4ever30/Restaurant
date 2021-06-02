/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#include "Finance.hpp"

#include <utility>

using namespace std;
using namespace RestLib;

Finance::Finance(string _name, string _owner) : ownerName(std::move(_owner)), name(std::move(_name)) {
    for (int i = 0; i < FINANCE_COUNT; i++) {
        accountMoney.push_back(0);
    }
}

std::string Finance::GetName() {
    return name;
}

std::string Finance::GetOwnerName() {
    return ownerName;
}

void Finance::AddMoneyInput(const FINANCE_TYPE &type, const double &amount) {

    cout << type << endl;
    cout << amount << endl;

    accountMoney[type] = amount;
    if (type == FINANCE_PURCHASE_DISHES || type == FINANCE_PURCHASE_DRINKS) {
        accountMoney[FINANCE_PURCHASE] += amount;
    } else if (type == FINANCE_SELL_DISHES || type == FINANCE_SELL_DRINKS) {
        accountMoney[FINANCE_SELL] += amount;
    }
}

double Finance::GetMoneyAmount(const FINANCE_TYPE &type) {
    return accountMoney[type];
}

void Finance::LoadFinanceClass(const string &filename) {
    // Create new filestream object
    ifstream financeReadFile;

    try {
        // try to open ingredientsFile for reading
        financeReadFile.open(filename, ifstream::in);
        // possible exceptions
        financeReadFile.exceptions(ifstream::failbit | ifstream::badbit);

        // as long as the file is open, readable and not finished keep reading
        while (!financeReadFile.eof() && financeReadFile.good()) {
            string identifier;
            string amount;

            getline(financeReadFile, identifier, '=');
            getline(financeReadFile, amount, ';');

            if (!identifier.empty() && !amount.empty()) {
                // Search for identifier
                auto ret {find(convertFinanceTypeToString.begin(), convertFinanceTypeToString.end(), identifier)};
                if(ret != convertFinanceTypeToString.end()){
                    // Valid identifier
                    AddMoneyInput(static_cast<FINANCE_TYPE>(ret - convertFinanceTypeToString.begin()), stod(amount));
                }

                if (financeReadFile.peek() == '\n') {
                    // Ignoring last char in ifstream
                    financeReadFile.ignore(1);
                }
            }
        }
        // close ingredientsFile
        financeReadFile.close();
    } catch (const system_error &e) {
        // exception handling
        cerr << "Error File could not be Found. " << filename << endl
             << "Please Enter a file name ending with .txt .. Exting with error # : " << e.code().message() << endl
             << flush;
    }
}

void Finance::SaveFinanceClass(const string &filename) {
    ofstream Savefile;

    try {
        Savefile.open(filename, ofstream::out);
        Savefile.exceptions(ofstream::failbit | ofstream::badbit);
        bool firstLine {true};
        for (int i = 0; i < FINANCE_COUNT; i++) {
            if (firstLine) {
                Savefile << convertFinanceTypeToString[i] << "=" << accountMoney[i] << ";";
                firstLine = false;
            } else {
                Savefile << endl << convertFinanceTypeToString[i] << "=" << accountMoney[i] << ";";
            }
        }
        Savefile.close();
    } catch (const system_error& e) {                           // exception handling
        cerr << "Error File could not be Found. " << filename << endl
             << "Please Enter a file name ending with .txt .. Exting with error # : " << e.code().message() << "\n"
             << flush;
    }
}
