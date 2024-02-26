#include "./../external/fmt-10/include/fmt/format.h"
#include "./../external/tinyxml2-10/tinyxml2.h"

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "./account.hpp"
#include "./askme.hpp"
#include "./clearc.hpp"
#include "./file.hpp"

void set_application_paths(std::string *app_path, std::string *app_dir) {
    std::int32_t dir_len = 0;
    const std::string _app_path = get_application_path(&dir_len);
    const std::string _app_dir = get_application_dir(_app_path, dir_len);

    *app_path = _app_path;
    *app_dir = _app_dir;
}

void save_accounts(std::vector<Account> accounts, const std::string &path);

int main() {
    std::string APPLICATION_DIR = "";
    std::string APPLICATION_PATH = "";
    set_application_paths(&APPLICATION_PATH, &APPLICATION_DIR);

    const std::string SAVE_FILE =
        fmt::format("{0}{1}accounts.txt", APPLICATION_DIR, PATH_SEP);
    std::vector<Account> accounts;

    clear_screen();

    if (!can_open_file(SAVE_FILE)) {
        std::cout << "It seems like you don't have any accounts." << '\n';
        std::cout << "Would you like to create one now?" << '\n';
        if (ask_question()) {
            Account account = Account::create();
            accounts.push_back(account);
        } else {
            clear_screen();
            return EXIT_SUCCESS;
        }
    } else {
    }

    accounts.push_back(Account{});
    accounts.push_back(Account{"Dummy", "Ass", 20});

    save_accounts(accounts, SAVE_FILE);
    return EXIT_SUCCESS;
}

void save_accounts(std::vector<Account> accounts, const std::string &path) {

#ifdef _WIN32
    FILE *file;
    fopen_s(&file, path.c_str(), "w+");
#else
    FILE *file = fopen(path.c_str(), "w+");
#endif

    if (file == nullptr) {
        perror(fmt::format("Couldn't open \"{0}\" for saving", path).c_str());
        return;
    }

    tinyxml2::XMLDocument document;
    tinyxml2::XMLDeclaration *document_decl = document.NewDeclaration();
    document.LinkEndChild(document_decl);

    tinyxml2::XMLElement *accounts_element = document.NewElement("Accounts");

    for (size_t i = 0; i < accounts.size(); i++) {
        tinyxml2::XMLElement *profile_element =
            document.NewElement(fmt::format("Account{0}", i + 1).c_str());

        tinyxml2::XMLElement *forname_element = document.NewElement("Forname");
        forname_element->SetText(accounts[i].get_forname().c_str());
        profile_element->LinkEndChild(forname_element);

        tinyxml2::XMLElement *surname_element = document.NewElement("Surname");
        surname_element->SetText(accounts[i].get_surname().c_str());
        profile_element->LinkEndChild(surname_element);

        tinyxml2::XMLElement *age_element = document.NewElement("Age");
        age_element->SetText(accounts[i].get_age());
        profile_element->LinkEndChild(age_element);

        accounts_element->LinkEndChild(profile_element);
    }

    document.LinkEndChild(accounts_element);

    fclose(file);
}