cmake_minimum_required(VERSION 3.21)

project(SERVEUR_HTTP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

configure_file(
    "${CMAKE_SOURCE_DIR}/config/application.properties"
    "${CMAKE_BINARY_DIR}/config/application.properties"
    COPYONLY
)

file(
    COPY        "${CMAKE_CURRENT_SOURCE_DIR}/Front"
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)

find_package(Qt6 REQUIRED COMPONENTS 
    Core 
    Network
    HttpServer
    Sql
)

set(HEADERS
    Back/server/include/Serveur.h

    Back/database/include/Database.h

    Back/controllers/include/LoginController.h

    Back/utils/include/PropertiesReader.h
    Back/utils/include/Routeur.h
    Back/utils/include/Requete.h
    Back/utils/include/StaticFiles.h
    Back/utils/include/PageRouteur.h

    Back/core/include/Initializer.h

    Back/routes/include/Web.h
    Back/routes/include/Api.h

    Back/repositories/include/LoginRepository.h

    Back/services/include/LoginService.h
)

set(SOURCES
    Back/server/source/Serveur.cpp

    Back/database/source/Database.cpp

    Back/controllers/source/LoginController.cpp

    Back/utils/source/PropertiesReader.cpp
    Back/utils/source/Routeur.cpp
    Back/utils/source/Requete.cpp
    Back/utils/source/StaticFiles.cpp
    Back/utils/source/PageRouteur.cpp

    Back/core/source/Initializer.cpp

    Back/routes/source/Web.cpp
    Back/routes/source/Api.cpp

    Back/repositories/source/LoginRepository.cpp

    Back/services/source/LoginService.cpp

    main.cpp
)

add_executable(exec ${SOURCES} ${HEADERS})

target_include_directories(exec PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Back/models/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Back/controllers/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Back/repositories/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Back/server/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Back/database/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Back/utils/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Back/core/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Back/routes/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Back/services/include
)

target_link_libraries(exec PRIVATE
    Qt6::Core
    Qt6::Network
    Qt6::HttpServer
    Qt6::Sql
)