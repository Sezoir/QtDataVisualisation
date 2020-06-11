#include "Startup.hpp"

namespace Bootloader {
    Startup::Startup() :
        QObject(nullptr),
        mEngine(new QQmlApplicationEngine()),
        mIsValid(true)
    {
        // Load main view
        loadMainView();
    }

    void Startup::loadMainView()
    {
        // Load main qml file
        this->mEngine->load(QUrl(QStringLiteral("qrc:/Resources/main.qml")));

        // Get root objects
        auto rootObjects = this->mEngine->rootObjects();

        // Validate
        if(rootObjects.isEmpty())
        {
            qDebug() << "There are no qml objects";
            this->mIsValid = false;
            return;
        }

        // Get pointer to root object
        this->mRoot = rootObjects[0];
    }

}
