#ifndef TX2E_ACCOUNT
#define TX2E_ACCOUNT

#define MAXIMUM_NAME_LENGTH 64
#define MAXIMUM_AGE_STR_LENGTH 3

#include "./../external/fmt-10/include/fmt/format.h"
#include "./askme.hpp"
#include "./clearc.hpp"

#include <cstdint>
#include <iostream>
#include <string>
class Account {
    const std::string _forname;
    const std::string _surname;
    const std::uint32_t _age;

  public:
    Account();
    Account(const std::string &forname, const std::string &surname,
            std::uint32_t age);

    Account(const Account &account);
    Account &operator=(const Account &other) {
        *this =
            Account{other.get_forname(), other.get_surname(), other.get_age()};
        return *this;
    }

    const std::string get_forname() const;
    const std::string get_surname() const;
    const std::uint32_t get_age() const;

    static Account create();
};

inline Account::Account() : _forname("John"), _surname("Doe"), _age(0) {}

inline Account::Account(const std::string &forname, const std::string &surname,
                        std::uint32_t age)
    : _forname(forname), _surname(surname), _age(age) {}

inline const std::string Account::get_forname() const { return this->_forname; }
inline const std::string Account::get_surname() const { return this->_surname; }
inline const std::uint32_t Account::get_age() const { return this->_age; }

inline Account::Account(const Account &account)
    : _forname(account.get_forname()), _surname(account.get_surname()),
      _age(account.get_age()) {}

inline Account Account::create() {
    clear_screen();
    std::cout << "What is your first name?: " << '\n';
    std::string forname;
    std::cin >> forname;

    clear_screen();
    std::cout << "What is your last name?: " << '\n';
    std::string surname;
    std::cin >> surname;

    clear_screen();
    std::cout << "What is your age?: " << '\n';
    std::uint32_t age;
    while (true) {
        std::cin >> age;
        if (!std::cin.fail())
            break;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        clear_screen();
        std::cout << "Please enter a number: " << '\n';
    }

    clear_screen();
    std::cout << fmt::format("Is this information correct?\nForname: "
                             "{0}\nSurname: {1}\nAge: {2}",
                             forname, surname, age)
              << '\n';

    std::string dummy;
    std::getline(std::cin, dummy);

    if (!ask_question()) {
        Account::create();
    }

    return {{forname}, {surname}, age};
}

#endif // TX2E_ACCOUNT
