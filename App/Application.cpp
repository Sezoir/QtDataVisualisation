#include "Application.hpp"
#include "Model/PopModel.hpp"
#include "PopulationItem.hpp"
#include <QQmlContext>
#include <QDir>
#include "xlsxdocument.h"

namespace App {

    Application::Application(QObject *parent, QQmlApplicationEngine *engine) :
        QObject(parent),
        mEngine(engine),
        mPopList(new Model::PopList(this))
    {
        if(!readTable("global-city-population-estimates.xlsx"))
            qDebug() << "Error with loading excel file" << QDir::currentPath() + "/global-city-population-estimates.xlsx";

        setContextProperties();

        registerTypes();
    }

    bool Application::registerTypes()
    {
        // Register types
        qmlRegisterType<App::Model::PopModel>("Pop", 1, 0, "PopModel");

        // Register uncreatable types
        qmlRegisterUncreatableType<Model::PopList>("Pop", 1, 0, "PopList", QStringLiteral("PopList should not be created in qml"));

        return true;
    }

    bool Application::setContextProperties()
    {
        this->mEngine->rootContext()->setContextProperty(QStringLiteral("popList"), this->mPopList);

        return true;
    }

    bool Application::readTable(QString path)
    {
        QXlsx::Document doc(path);
        if(!doc.load())
            return false;
        doc.selectSheet("CITIES-OVER-300K");
        for(int row = 2; row < 1693; row++)
        {
            for(int col = 8; col < 20; col++)
            {
                PopulationItem item;
                item.city = doc.read(row, 2).toString();
                item.year = doc.read(1, col).toInt();
                item.population = (int) doc.read(row, col).toFloat();
                this->mPopList->addItem(item);
            }
        }

        return true;
    }

}
