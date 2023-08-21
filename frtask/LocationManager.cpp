#include "LocationManager.h"

LocationManager::LocationManager(QObject *parent) : QAbstractListModel(parent)
{

    addLocation("qrc:/Eiffel.jpg", QColor(Qt::black), "Eiffel", "Franrce, Paris", QVector2D(1.854f, 2.953f));
    addLocation("qrc:/Rihanna.jpg", QColor(Qt::green), "Rihanna", "California, St Davis", QVector2D(1.084f, 2.0521f));
    addLocation("qrc:/Ariana.jpg", QColor(Qt::gray), "Ariana", "Frapo, Paris", QVector2D(1.0265f, 2.8450f));
    addLocation("qrc:/rihanna.jpg", QColor(Qt::red), "rihanna", "Fropoance, Paris", QVector2D(1.0545f, 2.694150f));
    addLocation("qrc:/Eiffel.jpg", QColor(Qt::blue), "Eiffekkl", "Fraopnce, Paris", QVector2D(1.0f, 2.0f));
    addLocation("qrc:/Eiffel.jpg", QColor(Qt::red), "Eiffekkl", "Fraonce, Paris", QVector2D(1.099f, 2.0f));
    addLocation("qrc:/Eiffel.jpg", QColor(Qt::red), "Eiffekkl", "Fraonce, Paris", QVector2D(3.0f, 2.0f));
    addLocation("qrc:/Eiffel.jpg", QColor(Qt::red), "Eiffekkl", "Fraonce, Paris", QVector2D(1.90f, 2.0f));


}

int LocationManager::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_locations.size();
}

QVariant LocationManager::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_locations.size())
        return QVariant();

    const Location &location = m_locations[index.row()];
    switch (role) {
    case PictureRole:
        return location.picture;
    case ColourRole:
        return location.colour;
    case NameRole:
        return location.name;
    case LocationRole:
        return location.loc;
    case MercatorRole:
        return location.mercator;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> LocationManager::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[PictureRole] = "picture";
    roles[NameRole] = "name";
    roles[ColourRole] = "colour";
    roles[LocationRole] = "loc";
    roles[MercatorRole] = "mercator";
    return roles;
}

void LocationManager::addLocation(const QString &picture, const QColor &colour, const QString &name, const QString &loc,const QVector2D &mercator)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    Location location;
    location.name = name;
    location.picture = picture;
    location.colour = colour;
    location.loc = loc;
    location.mercator = mercator;
    m_locations.append(location);
    endInsertRows();
}


void LocationManager::editClicked(const QString& imageName, const QString& typeName){
    qDebug() << "Image clicked:" << imageName << typeName;
}
void LocationManager::deleteClicked(const QString& imageName, const QString& typeName){
    qDebug() << "Image clicked:" << imageName << typeName;
}
