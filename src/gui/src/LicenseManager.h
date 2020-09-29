/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2015 Synergy Seamless Inc.
 *
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 *
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QObject>
#include <shared/EditionType.h>
#include <shared/SerialKey.h>
#include <ActivationNotifier.h>
#include <utility>

class AppConfig;

class LicenseManager: public QObject
{
    Q_OBJECT

public:
    LicenseManager(AppConfig* appConfig);
    std::pair<bool, QString> setSerialKey(SerialKey serialKey,
                                          bool acceptExpired = false);
    void refresh();
    Edition activeEdition() const;
    QString activeEditionName() const;
    SerialKey serialKey() const;
	void skipActivation() const;
	void notifyUpdate(QString fromVersion, QString toVersion) const;
	static QString getEditionName(Edition edition, bool trial = false);
	void notifyActivation(QString identity) const;
    QString getLicenseNotice() const;

private:
    AppConfig* m_AppConfig;
    SerialKey m_serialKey;

signals:
    void serialKeyChanged (SerialKey) const;
    void editionChanged (Edition) const;
    void LicenseExpired () const;
    void showLicenseNotice(const QString& notice) const;

protected:
    QString getTrialNotice() const;
    QString getTemporaryNotice() const;
};
