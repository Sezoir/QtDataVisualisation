#pragma once

#include <QObject>
#include <QQmlApplicationEngine>
#include <QString>
#include "Model/PopList.hpp"

namespace App {
    class Application : public QObject
    {
        Q_OBJECT

    public:
        explicit Application(QObject *parent, QQmlApplicationEngine* engine);
        ~Application() = default;

    private:
        bool registerTypes();
        bool setContextProperties();
        bool readTable(QString path);

        QQmlApplicationEngine* mEngine;

        Model::PopList* mPopList;
    };
}
