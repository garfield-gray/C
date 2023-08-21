#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
namespace _qt_qml_ProxyModelThing_Main_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_ProxyModelThing_AyBtn_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_ProxyModelThing_AyLineEdit_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_ProxyModelThing_AyText_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_ProxyModelThing_CustomBorder_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_ProxyModelThing_CustomRadius_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_ProxyModelThing_ImageRadius_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_ProxyModelThing_MyTableView_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/ProxyModelThing/Main.qml"), &QmlCacheGeneratedCode::_qt_qml_ProxyModelThing_Main_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/ProxyModelThing/AyBtn.qml"), &QmlCacheGeneratedCode::_qt_qml_ProxyModelThing_AyBtn_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/ProxyModelThing/AyLineEdit.qml"), &QmlCacheGeneratedCode::_qt_qml_ProxyModelThing_AyLineEdit_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/ProxyModelThing/AyText.qml"), &QmlCacheGeneratedCode::_qt_qml_ProxyModelThing_AyText_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/ProxyModelThing/CustomBorder.qml"), &QmlCacheGeneratedCode::_qt_qml_ProxyModelThing_CustomBorder_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/ProxyModelThing/CustomRadius.qml"), &QmlCacheGeneratedCode::_qt_qml_ProxyModelThing_CustomRadius_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/ProxyModelThing/ImageRadius.qml"), &QmlCacheGeneratedCode::_qt_qml_ProxyModelThing_ImageRadius_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/ProxyModelThing/MyTableView.qml"), &QmlCacheGeneratedCode::_qt_qml_ProxyModelThing_MyTableView_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appProxyModelThing)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appProxyModelThing))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_appProxyModelThing)() {
    return 1;
}
