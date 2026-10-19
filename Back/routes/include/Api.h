#pragma once

#include "Routeur.h"
#include "LoginController.h"
#include "Database.h"

class Api {
    private:
        Routeur& routeur;
        Database& database;

        LoginRepository loginRepository;
        LoginService loginService;
        LoginController loginController;
        
    public:
        Api(Routeur& routeur, Database& database);

        void declarationDesRoutesApi();
};