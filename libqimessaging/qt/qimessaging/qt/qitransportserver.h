/*
** Author(s):
**  - Laurent LEC <llec@aldebaran-robotics.com>
**
** Copyright (C) 2012 Aldebaran Robotics
*/

#ifndef QITRANSPORTSERVER_H_
# define QITRANSPORTSERVER_H_

# include <qimessaging/api.hpp>
# include <qimessaging/qt/QiTransportSocket>

# include <QObject>
# include <QByteArray>

class QiTransportServerPrivate;

class QIMESSAGING_API QiTransportServer : public QObject
{
  Q_OBJECT

public:
  QiTransportServer(QObject* parent = 0);
  virtual ~QiTransportServer();

  bool listen(const QUrl& listenURL);
  QUrl listeningUrl() const;
  void close();

  bool hasPendingConnections() const;
  QiTransportSocket* nextPendingConnection();
  bool isListening() const;

  void setIdentity(const QByteArray& key,
                   const QByteArray& certificate);

signals:
  void newConnection();

public:
  QiTransportServerPrivate* _p;
};

#endif /* ifndef QITRANSPORTSERVER_H_ */
