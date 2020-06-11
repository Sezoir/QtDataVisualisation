#pragma once
#include "App/Application.hpp"

#include <QObject>
#include <QQmlApplicationEngine>

namespace Bootloader {
    class Startup : public QObject
    {
    Q_OBJECT
    public:
        // Constructor/Destructor
        explicit Startup();
        ~Startup();

        /**
         * @brief Get the current value of mIsValid
         * @return bool
         */
        bool getSuccess() { return this->mIsValid; }

    private:
        // Qml engine
        QQmlApplicationEngine * mEngine;
        // Root object of qml
        QObject * mRoot;
        // Application
        App::Application * mApp;
        // States whether application has successfully loaded
        bool mIsValid;

        void loadModels();

        /**
         * @brief Loads the main view qml
         */
        void loadMainView();


    };
}
