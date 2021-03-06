// qt-redmine client
// Copyright (C) 2015, Danila Demidow
// Author: dandemidow@gmail.com (Danila Demidow)

#ifndef SENDER_H
#define SENDER_H

#include <QMap>
#include <QObject>
#include <QtXml/QDomDocument>

#include "network.h"

class Sender: public QObject {
  Q_OBJECT
  Network &_net;
  QByteArray _ua;
protected:
  QUrl _url;
  QMap<QNetworkReply*, QByteArray> _buffer;

  void sendRequest(Network::RequestType t,
                   const QUrl &url,
                   const QByteArray& requestData);
public:
  explicit Sender(const QUrl &url, Network &net);
  Sender(const Sender &s);
  virtual ~Sender();

public slots:
  void onReadyRead();
  void onFinished();
public:
  template <class Cmd>
  void start(const Cmd &cmd) {
    QUrl url = _url;
    cmd.setPath(url);
//    url.setPath("/projects/28.xml");
//    url.setQuery("include=journals");
    sendRequest(cmd.type, url, cmd.getContent());
  }

signals:
  void finish();
  void result(QDomDocument);
};

#endif // SENDER_H
