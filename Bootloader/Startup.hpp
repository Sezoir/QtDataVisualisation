#pragma once
#
#include <QObject>
#include <QQmlApplicationEngine>

namespace Bootloader {
    class Startup : public QObject
    {
    Q_OBJECT
    public:
        // Constructor/Destructor
        Startup();
        ~Startup() = default;

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
        // States whether application has successfully loaded
        bool mIsValid;

        /**
         * @brief Loads the main view qml
         */
        void loadMainView();


    };
}
