//
// Created by Momme Sherif on 20/05/2021.
//

#include "Restaurant.hpp"
#include <fstream>
namespace RestLib
{

    Restaurant::Restaurant(std::string _Restaurant_name , std::string FileName) : Restaurant_name{_Restaurant_name} {

        std::ifstream Datai;                                                // new in stream object


        try {
            Datai.open(FileName,std::ifstream::in);                        // open the file with the name (address) 'Filename'
            Datai.exceptions(std::ifstream::failbit | std::ifstream::badbit);        // possible exceptions
            while (!Datai.eof()&Datai.good()) {                           // as long as the file is open, readable and not finished keep reading
                string tempV {};
                string tempN {};
                getline(Datai,tempV);
                getline(Datai,tempN);

                vCustomers.push_back(Customer(tempV, tempN));
            }
            Datai.close();                                                // file must be closed again
        } catch (const std::ifstream::failure &e) {                           // exception handling
            std::cerr << "Error File could not be Found. " << std::endl
                      << "Please Enter a file name ending with .txt .. Exting with error # : " << e.what() << "\n" << std::flush;
        }
    }

    Customer& Restaurant::FindCustomer(std::string _customerLastName) {
        for (auto &_Customer : vCustomers) {
            if (_Customer.getName() == _customerLastName)
                return _Customer;
            else
                std::cerr << "User is not Fround" << std::endl;
            return _Customer;                                         ////////Falsch
        }
    }


}
