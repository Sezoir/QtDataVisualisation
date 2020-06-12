#pragma once

#include <QObject>
#include <QVector>

// Get struct for the item to be stored
#include "../PopulationItem.hpp"

namespace App::Model
{
    class PopList : public QObject
    {
        Q_OBJECT
    public:
        explicit PopList(QObject *parent);

        QVector<PopulationItem> items() const;

        bool setItemAt(int index, const PopulationItem& item);
        void addItem(const PopulationItem& item);

       signals:
           void preItemAppended();
           void postItemAppended();

           void preItemRemoved(int index);
           void postItemRemoved();

       public slots:
//           void removeItems();

    private:
        QVector<PopulationItem> mItems;

    };
}

