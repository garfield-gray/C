#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H


#include <QObject>
#include <QAbstractListModel>
#include <QColor>
#include <QVector2D>



class LocationManager : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit LocationManager(QObject *parent = nullptr);

    enum {
        PictureRole = Qt::UserRole,//cause the others are been reserved
        ColourRole,
        NameRole,
        LocationRole,
        MercatorRole
    };

    // QAbstractListModel overrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void deleteClicked(int index);

public slots:
    void addLocation(const QString &picture, const QColor &colour, const QString &name, const QString &loc,const QVector2D &mercator);
    void editClicked(const QString& imageName, const QString& typeName);

private:
    struct Location {
        QString picture;
        QColor colour;
        QString name;
        QString loc;
        QVector2D mercator;


    };

    QList<Location> m_locations;
};

#endif
