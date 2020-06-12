#pragma once
#include <QAbstractListModel>
#include "PopList.hpp"

namespace App::Model {
//    class PopList;

    class PopModel : public QAbstractListModel
    {
        Q_OBJECT
        Q_PROPERTY(PopList* list READ list WRITE setList)
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

        PopList *list() const;
        void setList(PopList *list);

    private:
        PopList* mList;
    };
}

