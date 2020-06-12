#include "PopList.hpp"
#include <QDebug>

namespace App::Model
{
    PopList::PopList(QObject *parent) : QObject(parent)
    {
//        mItems.append({QStringLiteral("uk"), 1999, 7000});
//        mItems.append({QStringLiteral("germany"), 1999, 15023});
    }

    QVector<PopulationItem> PopList::items() const
    {
        return mItems;
    }

    void PopList::addItem(const PopulationItem& item)
        {
            emit preItemAppended();

            this->mItems.append(item);

            emit postItemAppended();
        }

    bool PopList::setItemAt(int index, const PopulationItem &item)
    {
        if(index < 0 || index >= this->mItems.size())
            return false;
        const PopulationItem& oldItem = mItems.at(index);
        if(item.city == oldItem.city && item.year == oldItem.year && item.population == oldItem.population)
            return false;

        this->mItems[index] = item;
        return true;
    }
}
