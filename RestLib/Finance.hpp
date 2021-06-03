/*
 PIC - Labor Versuch 3
 Created by Mohamed Mahmoud 930154 and Tobias Fricke 932874
 Last Edit: 01/06/2021
*/

#ifndef MAIN_CPP_FINANCE_HPP
#define MAIN_CPP_FINANCE_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

namespace RestLib {
    class Finance {

    public:
        Finance() = delete;
        Finance(std::string _name, std::string _owner);

        enum FINANCE_TYPE {
            FINANCE_SELL_DRINKS = 0,
            FINANCE_SELL_DISHES,
            FINANCE_SELL,
            FINANCE_PURCHASE_DRINKS,
            FINANCE_PURCHASE_DISHES,
            FINANCE_PURCHASE,
            FINANCE_COUNT
        };

        std::string GetName();
        std::string GetOwnerName();

        void LoadFinanceClass(const std::string &filename);
        void SaveFinanceClass(const std::string &filename);

        template<FINANCE_TYPE financeType>
        void AddMoneyInput(const double &amount) {
            switch (financeType) {
                case FINANCE_PURCHASE_DISHES:
                    accountMoney[FINANCE_PURCHASE_DISHES] += amount;
                    accountMoney[FINANCE_PURCHASE] += amount;
                    break;
                case FINANCE_PURCHASE_DRINKS:
                    accountMoney[FINANCE_PURCHASE_DRINKS] += amount;
                    accountMoney[FINANCE_PURCHASE] += amount;
                    break;
                case FINANCE_SELL_DISHES:
                    accountMoney[FINANCE_SELL_DISHES] += amount;
                    accountMoney[FINANCE_SELL] += amount;
                    break;
                case FINANCE_SELL_DRINKS:
                    accountMoney[FINANCE_SELL_DRINKS] += amount;
                    accountMoney[FINANCE_SELL] += amount;
                    break;
                case FINANCE_SELL:
                    accountMoney[FINANCE_SELL] += amount;
                    break;
                case FINANCE_PURCHASE:
                    accountMoney[FINANCE_PURCHASE] += amount;
                    break;
            }
        }

        double GetMoneyAmount(const FINANCE_TYPE &type);

    private:
        std::string name;
        std::string ownerName;
        std::vector<double> accountMoney;

        std::vector<std::string> convertFinanceTypeToString {"FINANCE_SELL_DRINKS", "FINANCE_SELL_DISHES", "FINANCE_SELL", "FINANCE_PURCHASE_DRINKS", "FINANCE_PURCHASE_DISHES", "FINANCE_PURCHASE", "FINANCE_CREDIT"};
    };
}

#endif //MAIN_CPP_FINANCE_HPP