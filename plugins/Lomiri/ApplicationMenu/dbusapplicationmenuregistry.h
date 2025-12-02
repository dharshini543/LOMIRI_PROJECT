/*
 * Copyright (C) 2016 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DBUSAPPLICATIONMENUREGISTRY_H
#define DBUSAPPLICATIONMENUREGISTRY_H

#include "applicationmenuregistry.h"

class DBusApplicationMenuRegistry : public ApplicationMenuRegistry,
                                    protected QDBusContext
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)

public:
    ~DBusApplicationMenuRegistry();
    static ApplicationMenuRegistry* instance();

    QString name() const;
    void setName(const QString &newName);

// protected:
    explicit DBusApplicationMenuRegistry(QObject *parent = 0);
signals:
    void nameChanged();
private:
    QString m_name;
};

#endif // DBUSAPPLICATIONMENUREGISTRY_H
