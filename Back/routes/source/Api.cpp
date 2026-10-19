#include "Api.h"

Api::Api(Routeur& route, Database& data)
    : routeur(route),
      database(data),
      loginRepository(database),
      loginService(loginRepository),
      loginController(loginService) {
}

void Api::declarationDesRoutesApi() {
    routeur.post("/api/login", [this](const Requete& req) {
        return loginController.login(req);
    });
}