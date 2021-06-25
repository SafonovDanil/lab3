#ifndef FILESMODEL_H
#define FILESMODEL_H


#include <QAbstractTableModel>
#include <QList>
#include "imodel.h"
#include "entry.h"

class FilesModel : public QAbstractTableModel, public iModel
{
public:
    FilesModel(QObject *parent, QList<Entry> model = QList<Entry>());

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    virtual void updateModel(QList<Entry> model);
    void convertData(QList<Entry> model);

private:

    enum ColumnName {
    NAME,
    SIZE,
    PERCENT
    };


    QList<Entry> m_model;

};
#endif // FILESMODEL_H
