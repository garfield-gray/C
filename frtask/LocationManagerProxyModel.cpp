#include "LocationManagerProxyModel.h"

LocationManagerProxyModel::LocationManagerProxyModel(QObject *parent) : QSortFilterProxyModel(parent)
{
    m_sourceModel = new LocationManager(this);
    setSourceModel(m_sourceModel);
}

void LocationManagerProxyModel::addLocation(const QString &picture, const QColor &colour, const QString &name, const QString &loc, const QVector2D &mercator)
{
    m_sourceModel->addLocation(picture, colour, name, loc, mercator);
}

void LocationManagerProxyModel::editLocation(int index, const QString &name, const QString &loc)
{
    if (index >= 0 && index < m_sourceModel->rowCount())
    {
        QModelIndex sourceIndex = mapToSource(this->index(index, 0));
        QString imageName = sourceIndex.data(LocationManager::NameRole).toString();
        QString typeName = sourceIndex.data(LocationManager::LocationRole).toString();
        m_sourceModel->editClicked(imageName, typeName);
    }
}

void LocationManagerProxyModel::deleteLocation(int index)
{
    if (index >= 0 && index < m_sourceModel->rowCount())
    {
        QModelIndex sourceIndex = mapToSource(this->index(index, 0));
        QString imageName = sourceIndex.data(LocationManager::NameRole).toString();
        QString typeName = sourceIndex.data(LocationManager::LocationRole).toString();
//        m_sourceModel->deleteClicked(imageName, typeName);
    }
}

bool LocationManagerProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{

}
