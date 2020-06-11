#pragma once

#include <QAbstractListModel>
#include <QObject>

namespace App::Models {
    class PopModel : public QAbstractListModel
    {
        Q_OBJECT

    public:
        explicit PopModel(QObject *parent = nullptr);

        enum {
            cityRole = Qt::UserRole,
            yearRole,
            populationRole
        };

        // Basic functionality:
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        // Editable:
        bool setData(const QModelIndex &index, const QVariant &value,
                     int role = Qt::EditRole) override;

        Qt::ItemFlags flags(const QModelIndex& index) const override;

        virtual QHash<int, QByteArray> roleNames() const override;

    private:
    };
}

