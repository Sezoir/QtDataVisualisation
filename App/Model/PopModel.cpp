#include "PopModel.hpp"

namespace App::Models {
    PopModel::PopModel(QObject *parent)
        : QAbstractListModel(parent)
    {
    }

    int PopModel::rowCount(const QModelIndex &parent) const
    {
        // For list models only the root node (an invalid parent) should return the list's size. For all
        // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
        if (parent.isValid())
            return 0;

        // FIXME: Implement me!
        return 1;
    }

    QVariant PopModel::data(const QModelIndex &index, int role) const
    {
        if (!index.isValid())
            return QVariant();

        // FIXME: Implement me!
        switch(role)
        {
        case cityRole:
            return QVariant(QStringLiteral("xxxxx"));
        case yearRole:
            return QVariant(1999);
        case populationRole:
            return QVariant(10);
        }

        return QVariant();
    }

    bool PopModel::setData(const QModelIndex &index, const QVariant &value, int role)
    {
        if (data(index, role) != value) {
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
}
