#include "Web.h"

Web::Web(PageRouteur& pr) : pageRouteur(pr) {}

void Web::declarationDesRoutesWeb() {
    pageRouteur.page("/login","page/login.html");
}