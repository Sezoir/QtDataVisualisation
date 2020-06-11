#pragma once

#include <QObject>

namespace App {
    class Application : public QObject
    {
        Q_OBJECT

    public:
        explicit Application(QObject *parent = nullptr);
        ~Application() = default;




    };
}
