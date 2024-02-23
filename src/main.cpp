#include "./../external/tinyxml2-10/tinyxml2.h"
#include "./../external/whereami/src/whereami.h"
#include "./file.hpp"
#include <cstdlib>
#include <iostream>

int main() {

    using namespace tinyxml2;

    XMLDocument doc;
    XMLElement *dRoot = doc.RootElement();
    XMLElement *eAccounts = dRoot->InsertNewChildElement("");

    doc.SaveFile("mtdocs.xml");

    return EXIT_SUCCESS;
}
