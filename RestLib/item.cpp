//
// Created by Momme Sherif on 20/05/2021.
//

#include "item.hpp"
namespace RestLib
{
RestLib::item::item(std::string _item_name, double _item_amount) : item_name{_item_name}, item_amount{item_amount}{
}

    std::string item::get_item_name(item) {
        return item_name;
    }

    double item::get_item_amount(item) {
        return item_amount;
    }


}
