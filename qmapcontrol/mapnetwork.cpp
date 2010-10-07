/*
*
* This file is part of QMapControl,
* an open-source cross-platform map widget
*
* Copyright (C) 2007 - 2008 Kai Winter
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with QMapControl. If not, see <http://www.gnu.org/licenses/>.
*
* Contact e-mail: kaiwinter@gmx.de
* Program URL   : http://qmapcontrol.sourceforge.net/
*
*/

#include "mapnetwork.h"
#include <QNetworkProxy>

#include "tools.h"

namespace qmapcontrol
{
    MapNetwork::MapNetwork(ImageManager* parent)
        :parent(parent), nm(new QNetworkAccessManager(this))
    {
    }

    MapNetwork::~MapNetwork()
    {
    }

    void MapNetwork::loadImage(const QString& host, const QString& query)
    {
	QUrl url = QString("http://%1/%2").arg(host).arg(query);
	QNetworkRequest req(url);
	QNetworkReply *rep;

	Tools::fixupRequest(&req);
	rep = nm->get(req);

        connect(rep, SIGNAL(finished()), this, SLOT(requestFinished()));
	connect(rep, SIGNAL(error(QNetworkReply::NetworkError)), this,
		SLOT(requestError(QNetworkReply::NetworkError)));

	loadingMap[rep] = query;
    }

    void MapNetwork::requestFinished(void)
    {
	QNetworkReply *rep = (QNetworkReply *)sender();
	QPixmap pm;
	QString url;

	 // check if id is in map?
	if (!loadingMap.contains(rep))
	   return ;

	url = loadingMap[rep];
	loadingMap.remove(rep);

	if (pm.loadFromData(rep->readAll()))
	    parent->receivedImage(pm, url);

        if (loadingMap.isEmpty())
            parent->loadingQueueEmpty();
    }

    void MapNetwork::requestError(QNetworkReply::NetworkError code)
    {
	QNetworkReply *rep = (QNetworkReply *)sender();

	if (!loadingMap.contains(rep))
	    return ;

	loadingMap.remove(rep);
        if (loadingMap.isEmpty())
            parent->loadingQueueEmpty();
    }

    void MapNetwork::abortLoading()
    {
	foreach (QNetworkReply *rep, loadingMap.keys())
	    rep->abort();
	loadingMap.clear();
	parent->loadingQueueEmpty();
    }

    bool MapNetwork::imageIsLoading(const QString & host, const QString & url)
    {
        return loadingMap.values().contains(url);
    }

    void MapNetwork::setProxy(const QString & host, int port)
    {
	QNetworkProxy proxy;

	proxy.setHostName(host);
	proxy.setPort(port);
	nm->setProxy(proxy);
    }
}
