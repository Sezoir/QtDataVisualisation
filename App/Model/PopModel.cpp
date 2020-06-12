#include "PopModel.hpp"

namespace App::Model {
    PopModel::PopModel(QObject *parent)
        : QAbstractListModel(parent),
          mList(nullptr)
    {
    }

    int PopModel::rowCount(const QModelIndex &parent) const
    {
        // For list models only the root node (an invalid parent) should return the list's size. For all
        // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
        if (parent.isValid() || !mList)
            return 0;

        return this->mList->items().size();
    }

    QVariant PopModel::data(const QModelIndex &index, int role) const
    {
        if (!index.isValid() || !mList)
            return QVariant();

        const PopulationItem item = this->mList->items().at(index.row());
        switch(role)
        {
        case cityRole:
            return QVariant(item.city);
        case yearRole:
            return QVariant(item.year);
        case populationRole:
            return QVariant(item.population);
        }

        return QVariant();
    }

    bool PopModel::setData(const QModelIndex &index, const QVariant &value, int role)
    {
        if(!mList)
            return false;

        PopulationItem item = this->mList->items().at(index.row());
        switch(role)
        {
        case cityRole:
            item.city = value.toString();
            break;
        case yearRole:
            item.year = value.toInt();
            break;
        case populationRole:
            item.population = value.toInt();
            break;
        }

        if (mList->setItemAt(index.row(), item)) {
            // FIXME: Implement me!
            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }
        return false;
    }

    Qt::ItemFlags PopModel::flags(const QModelIndex &index) const
    {
        if (!index.isValid())
            return Qt::NoItemFlags;

        return Qt::ItemIsEditable; // FIXME: Implement me!
    }

    QHash<int, QByteArray> PopModel::roleNames() const
    {
        QHash<int, QByteArray> names;
        names[cityRole] = "city";
        names[yearRole] = "year";
        names[populationRole] = "population";
        return names;
    }

    PopList *PopModel::list() const
    {
        return mList;
    }

    void PopModel::setList(PopList *list)
    {
        beginResetModel();
//        if(mList)
//            mList->disconnect(this);

        if(mList)
            mList->disconnect(this);

        mList = list;

        if(mList)
        {
            connect(mList, &PopList::preItemAppended, this, [=]() {
                const int index = mList->items().size();
                beginInsertRows(QModelIndex(), index, index);
            });
            connect(mList, &PopList::postItemAppended, this, [=]() {
                endInsertRows();
            });
            connect(mList, &PopList::preItemRemoved, this, [=](int index) {
                beginRemoveRows(QModelIndex(), index, index);
            });
            connect(mList, &PopList::postItemRemoved, this, [=]() {
                endRemoveRows();
            });
        }

        endResetModel();
    }
}
