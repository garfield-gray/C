#ifndef LOCATIONMANAGERPROXYMODEL_H
#define LOCATIONMANAGERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "LocationManager.h" // Assuming you have this class defined

class LocationManagerProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    LocationManagerProxyModel(QObject *parent = nullptr);

public slots:
    Q_INVOKABLE void addLocation(const QString &picture, const QColor &colour, const QString &name, const QString &loc, const QVector2D &mercator);
    Q_INVOKABLE void editLocation(int index, const QString &name, const QString &loc);
    Q_INVOKABLE void deleteLocation(int index);

private:
    LocationManager *m_sourceModel;
};

#endif // LOCATIONMANAGERPROXYMODEL_H

