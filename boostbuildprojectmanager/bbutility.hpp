#ifndef BBUTILITY_HPP_INCLUDED
#define BBUTILITY_HPP_INCLUDED
#ifdef _DEBUG

#include "bbprojectmanagerconstants.hpp"
// Qt
#include <QDebug>
#include <QHash>
#include <QSet>
#include <QString>
#include <QStringList>

////////////////////////////////////////////////////////////////////////////////

#define BBPM_QDEBUG(msg) \
    qDebug() \
        << "[" << BoostBuildProjectManager::Constants::BOOSTBUILD << "] " \
        << "(" << __PRETTY_FUNCTION__ << ")"; \
    qDebug().nospace() << "\t" << msg

#else
nospace
#define BBPM_QDEBUG(msg)

#endif // _DEBUG

////////////////////////////////////////////////////////////////////////////////
namespace BoostBuildProjectManager {
namespace Utility {

// Read all lines from a file.
QStringList readLines(QString const& absoluteFileName);

// Converts the path from relative to the project to an absolute path.
QStringList makeAbsolutePaths(QString const& basePath, QStringList const& paths);

QStringList& makeRelativePaths(QString const& basePath, QStringList& paths);

QHash<QString, QStringList> sortFilesIntoPaths(QString const& basePath
                                             , QSet<QString> const& files);
} // namespace Utility
} // namespace BoostBuildProjectManager

#endif // BBUTILITY_HPP_INCLUDED
